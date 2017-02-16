#include <assert.h>

using namespace std;

typedef unsigned int size_t;		// Si usan visual studio (probablemente) no necesitan este typedef

template <class T>
struct ListElement {
	T val;
	ListElement* next;
};

template <class T>
class CircularList {
public:
	CircularList();
	~CircularList();

	ListElement<T>* pushFront(T elemVal);
	ListElement<T>* pushBack(T elemVal);

	ListElement<T>* insertNextTo(ListElement<T>* element, T elemVal);
	void erase(ListElement<T>* element);

	void clear();

	ListElement<T>* getFirst();
	ListElement<T>* getLast();

	size_t getElementCount();

private:
	ListElement<T>* root;
	ListElement<T>* tail;
	ListElement<T>* buildNode(T elemVal, ListElement<T>* next);
};

//  Constructor & Destructor  //
template <class T>
CircularList<T>::CircularList() {
	root = nullptr;
	tail = nullptr;
}
template <class T>
CircularList<T>::~CircularList() {
	clear();
}

//  Adders  //
template <class T>
ListElement<T>* CircularList<T>::buildNode(T elemVal, ListElement<T>* next) {
	ListElement<T>* newNode = new ListElement<T>();
	newNode->val = elemVal;
	if (next == nullptr)
		newNode->next = newNode;
	else
		newNode->next = next;
	return newNode;
}
template <class T>
ListElement<T>* CircularList<T>::pushFront(T elemVal) {
	ListElement<T>* newNode;
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
template <class T>
ListElement<T>* CircularList<T>::pushBack(T elemVal) {
	ListElement<T>* newNode;
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
template <class T>
ListElement<T>* CircularList<T>::insertNextTo(ListElement<T>* element, T elemVal) {
	ListElement<T>* newNode = nullptr;
	if (root == nullptr && element == nullptr)
		newNode = pushFront(elemVal);
	else if (root != nullptr && element != nullptr) {
		ListElement<T>* itr = root;
		do {
			if (itr == element) {
				newNode = new ListElement<int>();
				newNode->val = elemVal;
				newNode->next = itr->next;
				itr->next = newNode;
				if (element == tail)
					tail = newNode;
				break;
			}
			itr = itr->next;
		} while (itr != root);
	}
	return newNode;
}

//  Removers  //
template <class T>
void CircularList<T>::erase(ListElement<T>* element) {
	if (root != nullptr) {
		if (root == tail) {		// solo hay un elemento en la lista
			if (root == element) {
				delete root;
				root = nullptr;
				tail = nullptr;
			}
		} else {				// hay más de un elemento en la lista
			ListElement<T>* itr = root;
			ListElement<T>* prev = tail;
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
template <class T>
void CircularList<T>::clear() {
	if (root != nullptr) {
		ListElement<T>* itr = root;
		do {
			ListElement<T>* temp = itr->next;
			delete itr;
			itr = temp;
		} while (itr != root);

		root = nullptr;
		tail = nullptr;
	}
}

//  Getters  //
template <class T>
ListElement<T>* CircularList<T>::getFirst() {
	return root;
}
template <class T>
ListElement<T>* CircularList<T>::getLast() {
	return tail;
}
template <class T>
size_t CircularList<T>::getElementCount() {
	size_t count = 0;
	if (root != nullptr) {
		ListElement<T>* itr = root;
		do {
			count++;
			itr = itr->next;
		} while (itr != root);

	}
	return count;
}


//  TESTS  //

void testPushBack() {
	CircularList<int> listA;
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
	ListElement<int>* itr = listA.getFirst();
	do {
		sum += itr->val;
		itr = itr->next;
	} while (itr != listA.getFirst()); // Because this is a circular list
	assert(sum == 600); // 100 + 200 + 300 = 600
}

void testErase() {
	CircularList<int> list;
	ListElement<int>* one = list.pushBack(1);
	ListElement<int>* two = list.pushBack(2);
	ListElement<int>* three = list.pushBack(3);
	ListElement<int>* four = list.pushBack(4);
	ListElement<int>* five = list.pushBack(5);
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
	CircularList<int> list;
	list.pushFront(1);
	list.pushFront(2);
	list.pushFront(3);
	assert(list.getElementCount() == 3);
	assert(list.getFirst()->val == 3);
	assert(list.getLast()->val == 1);
}

void testInsertNextTo() {
	CircularList<int> list;
	ListElement<int>* one = list.insertNextTo(nullptr,1);
	assert(list.getFirst() == one);
	assert(list.getLast() == one);
	ListElement<int>* two = list.insertNextTo(one, 2);
	assert(list.getLast() == two);
	ListElement<int>* three = list.insertNextTo(one, 3);
	assert(list.getLast() == two);
	ListElement<int>* four = list.insertNextTo(one, 4);
	assert(list.getLast() == two);
	assert(list.getElementCount() == 4);
	list.erase(four);
	assert(list.getElementCount() == 3);
	ListElement<int>* five = list.insertNextTo(four, 5);
	assert(list.getElementCount() == 3);
	assert(five == nullptr);
	list.erase(one);
	assert(list.getFirst() == three);
	list.erase(three);
	assert(list.getFirst() == two);
	list.erase(two);
	assert(list.getElementCount() == 0);

}

int main() {
	testPushBack();
	testErase();
	testPushFront();
	testInsertNextTo();

	return 0;
}