#include <assert.h>

using namespace std;

struct ListElement
{
	// tuve que cambiar "element" por "val"  o en cada uno de las lineas de codigo de los test
	int val;
	ListElement *next;
};
class CircularList
{
public:
	CircularList();
	~CircularList(); // falta
	ListElement *pushFront(int elemVal);
	ListElement *pushBack(int elemVal);
	void erase(ListElement*element);
	void clear(); // falta 
	ListElement*getFirst();
	ListElement*getLast(); 
	size_t getElementCount(); 

private:
	ListElement * root;
	ListElement * last;
	ListElement * first;
	int element;

};
CircularList::CircularList()
{
	// Constructor, inicializo con todos los punteros a NULL
	root = first = last = NULL;
};

CircularList::~CircularList()
{
	//delete[] elemVal
};

ListElement*CircularList::pushFront(int elemVal)
{
	// Coloca "elemVal" al inicio de la lista
	//element = elemVal;
	ListElement*next= new ListElement();
	ListElement * newElement = new ListElement();// puntero que vaya a nuevo elemento
	newElement->val = elemVal; // nuevo elemento apunta a elemento

	if (root == NULL)
	{
		newElement->next = newElement;
		first = last = newElement;
	}
	else
	{
		newElement->next = next;
	}
	return 0;
}

ListElement*CircularList::pushBack(int elemVal)
{	
	// coloca "elemVal" al final de la lista
	//element = elemVal;
	ListElement*next =new ListElement();
	ListElement * newElement = new ListElement();// puntero que vaya a nuevo elemento
	newElement->val = elemVal; // nuevo elemento apunta a elemento

	if (root == NULL)
	{
		newElement->next = newElement;
		first = last = newElement;
	}
	else
		newElement->next = next;
	return 0;
}

void CircularList::erase(ListElement* element)
{
	// Busca el elemento mencionado y lo borra, seria mejor ordenarlos y hacer alguna busqueda mejor como binaria para arrays?
	if (first == last)
	{
		first, last, root = NULL;
	}
	else
	{
		ListElement* itr = first;
		ListElement* ant = last;
		ListElement*aux = new ListElement();
		do {
			if (itr == element) 
			{
				first = itr->next;
				delete itr;
				break;
			}
				itr = itr->next;
		} while (itr != first);
	}
}

ListElement*CircularList::getLast()
{
	// Devuelve el ultimo elemento de la lista
	return last;
}
ListElement*CircularList::getFirst()
{
	//Devuelve el primer elemento de la lista
	return first;
}
size_t CircularList::getElementCount()
{
	// Devuelve la cantdad de elementos en la lista
	size_t	count = 0;
	if (root != NULL) {
		ListElement* itr = first;
		do {
			count++;
			itr = itr->next;

		} while (itr != first);
	}
	else
		count = 0;
	return count;
}

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