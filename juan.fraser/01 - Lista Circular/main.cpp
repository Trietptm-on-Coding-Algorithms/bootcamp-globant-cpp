#include <assert.h>

using namespace std;

typedef unsigned int size_t;		// Si usan visual studio (probablemente) no necesitan este typedef

struct ListElement {
	int val;
	ListElement* next;
};

class CircularList {
public:
	CircularList();
	~CircularList();

	ListElement* pushFront(int elemVal);
	ListElement* pushBack(int elemVal);

	//ListElement* insertNextTo(ListElement* element, int elemVal);
	void erase(ListElement* element);

	void clear();

	ListElement* getFirst();
	ListElement* getLast();

	size_t getElementCount();

private:
	ListElement* root;
	ListElement* tail;
	ListElement* buildNode(int elemVal, ListElement* next);
};

//  Constructor & Destructor  //

CircularList::CircularList() {
	root = nullptr;
	tail = nullptr;
}
CircularList::~CircularList() {
	clear();
}

//  Adders  //

ListElement* CircularList::buildNode(int elemVal, ListElement* next) {
	ListElement* newNode = new ListElement();
	newNode->val = elemVal;
	if (next == nullptr)
		newNode->next = newNode;
	else
		newNode->next = next;
	return newNode;
}

ListElement* CircularList::pushFront(int elemVal) {
	ListElement* newNode;
	if (root == nullptr) {
		newNode = buildNode(elemVal, nullptr);
		root = newNode;
		tail = newNode;
	} else {
		newNode = buildNode(elemVal, root);
		tail->next = newNode;
		root = newNode;
	}
	return newNode;
}
ListElement* CircularList::pushBack(int elemVal) {
	ListElement* newNode;
	if (root == nullptr) {
		newNode = buildNode(elemVal, nullptr);
		root = newNode;
		tail = newNode;
	} else {
		newNode = buildNode(elemVal, root);
		tail->next = newNode;
		tail = newNode;
	}
	return newNode;
}
/*ListElement* CircularList::insertNextTo(ListElement* element, int elemVal) {
if (element == root)
return pushFront(elemVal);
if (root == nullptr)
return nullptr;
if (element == tail)
return pushBack(elemVal);
// Search for element. If found, add. If not, do nothing.
ListElement* itr = root;
while (itr != tail) {
itr = itr->next;
if (itr == element) {

}
}
return NULL;
}*/

//  Removers  //

void CircularList::erase(ListElement* element) {
	if (root != nullptr) {
		if (root == tail) {		// solo hay un elemento en la lista
			if (root == element) {
				delete root;
				root = nullptr;
				tail = nullptr;
			}
		} else {				// hay más de un elemento en la lista
			ListElement* itr = root;
			ListElement* prev = tail;
			do {
				if (itr == element) {
					prev->next = itr->next;
					if (itr == root)
						root = itr->next;
					if (itr == tail)
						tail = prev;
					delete itr;
					break;
				}
				prev = itr;
				itr = itr->next;
			} while (itr != root);
		}
	}
}
void CircularList::clear() {
	if (root != nullptr) {
		ListElement* itr = root;
		do {
			ListElement* temp = itr->next;
			delete itr;
			itr = temp;
		} while (itr != root);

		root = nullptr;
		tail = nullptr;
	}
}

//  Getters  //

ListElement* CircularList::getFirst() {
	return root;
}
ListElement* CircularList::getLast() {
	return tail;
}
size_t CircularList::getElementCount() {
	size_t count = 0;
	if (root != nullptr) {
		ListElement* itr = root;
		do {
			count++;
			itr = itr->next;
		} while (itr != root);

	}
	return count;
}


//  TESTS  //

void testPushBack() {
	CircularList listA;
	assert(listA.getElementCount() == 0);
	assert(listA.getLast() == listA.getFirst());

	listA.pushBack(100);
	assert(listA.getElementCount() == 1);
	assert(listA.getFirst()->val == 100);
	assert(listA.getLast()->val == 100);
	assert(listA.getLast()->next == listA.getFirst());

	listA.pushBack(200);
	assert(listA.getElementCount() == 2);
	assert(listA.getFirst()->val == 100);
	assert(listA.getLast()->val == 200);
	assert(listA.getLast()->next == listA.getFirst());

	listA.pushBack(300);
	assert(listA.getElementCount() == 3);
	assert(listA.getFirst()->val == 100);
	assert(listA.getLast()->val == 300);
	assert(listA.getLast()->next == listA.getFirst());


	size_t sum = 0;
	ListElement* itr = listA.getFirst();
	do {
		sum += itr->val;
		itr = itr->next;
	} while (itr != listA.getFirst()); // Because this is a circular list
	assert(sum == 600); // 100 + 200 + 300 = 600
}

void testErase() {
	CircularList list;
	ListElement* one = list.pushBack(1);
	ListElement* two = list.pushBack(2);
	ListElement* three = list.pushBack(3);
	ListElement* four = list.pushBack(4);
	ListElement* five = list.pushBack(5);
	assert(list.getElementCount() == 5);
	assert(list.getLast()->next == list.getFirst());

	list.erase(three);
	assert(list.getElementCount() == 4);
	assert(list.getLast()->next == list.getFirst());

	list.erase(one);
	assert(list.getElementCount() == 3);
	assert(list.getFirst()->val != 1);
	assert(list.getLast()->next == list.getFirst());

	list.erase(five);
	assert(list.getElementCount() == 2);
	assert(list.getLast()->val != 5);
	assert(list.getLast()->next == list.getFirst());

	list.erase(two);
	list.erase(four);
	assert(list.getElementCount() == 0);
}

void testPushFront() {
	CircularList list;
	list.pushFront(1);
	list.pushFront(2);
	list.pushFront(3);
	assert(list.getElementCount() == 3);
	assert(list.getFirst()->val == 3);
	assert(list.getLast()->val == 1);
}

int main() {
	testPushBack();
	testErase();
	testPushFront();

	return 0;
}