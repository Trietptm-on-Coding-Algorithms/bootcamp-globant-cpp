#include <assert.h>
#include <iostream>

using namespace std;
//typedef long long unsigned int size_t;	

struct ListElement
{
	int val;
	ListElement *next;
};
class CircularList
{
public:
	CircularList();
	~CircularList(); 
	ListElement *pushFront(int elemVal);
	ListElement *pushBack(int elemVal);
	void erase(ListElement*element);
	void clear(); 
	ListElement*getFirst();
	ListElement*getLast(); 
	size_t getElementCount(); 

private:
	ListElement * last;
	ListElement * first;
	int element;

};
CircularList::CircularList()
{
	// Constructor, inicializo con todos los punteros a NULL
	first =NULL;
	last = NULL;
};

CircularList::~CircularList()
{
// llamo a la funcion clear para que elimine todos los elementos
	clear();
};

ListElement*CircularList::pushFront(int elemVal)
{
	// Coloca "elemVal" al inicio de la lista
	ListElement * newElement = new ListElement();
	newElement->val = elemVal;

	if (first == NULL)
	{
		// En caso de lista vacia, last = first= newElement y los punteros van a si mismo
		last= newElement;
		first= newElement;
		newElement-> next = newElement;
	}
	else
	{
		// En caso de que ya haya elementos, newElement apunta a first, last apunta a newElement y first pasa a ser newElement
		first = newElement;
		newElement ->next = first;
		last->next=newElement;
	}
	return 0;
}

ListElement*CircularList::pushBack(int elemVal)
{	
	// inversa de pushFront
	ListElement * newElement = new ListElement();
	newElement->val = elemVal;

	if (first == NULL)
	{
		first =newElement;
		last = newElement;
		newElement ->next =newElement;
	}
	else if (first != NULL)
	{
		
		newElement->next = first;
		last ->next =newElement;
		last=newElement;
	}
	return 0;
}

void CircularList::erase(ListElement* element)
{
	// Busca el elemento mencionado y lo borra 
	ListElement*aux=new ListElement();
	if ((first == last) && (element == first)) 
	{
		// caso de unico elemento
		ListElement*aux= first;
		delete aux;
		last = NULL;
		first = NULL;
	}
	else{
		do {
			if (aux == element) 
				{
					// caso en que haya mas de uno y busca 1 por 1 hasta encontrarlo 
					first = aux->next;
					delete aux;
					break;
				}
				aux = aux->next;
			} while (aux != first);
		if (aux == first)
			{
				// mandar mje elemento no encontrado 	
			}
	}
}
void CircularList::clear ()
{
	
	if (first != NULL) 
	do
	{ 
		ListElement*toDelete =first;
		delete toDelete;
		first = first->next;
	}	while (first != NULL);
	last = NULL;

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
	size_t count =0;
	
	ListElement *aux = first;

	if (first != NULL) 
	{	
		do {
			count++;
			aux = aux->next;

			} while (aux != first);
	}
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
	CircularList list;
	list.clear();
/*
	testPushBack();

	testErase();

	testPushFront();
*/
	return 0;
}

