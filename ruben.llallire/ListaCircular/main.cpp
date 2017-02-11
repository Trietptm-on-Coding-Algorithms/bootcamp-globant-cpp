#include <iostream>
#include <assert.h>

using namespace std;

typedef unsigned int size_t; // Si usan visual studio (probablemente) no necesitan este typedef
typedef struct ListElement lista;

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

    void insertNextTo(ListElement* element, int elemVal);
    void erase(ListElement* element);

    void clear();

    ListElement* getFirst();
    ListElement* getLast();

    size_t getElementCount();
private:
        // TODO: Complete
    lista *root;

};

//  TODO: Complete
CircularList::CircularList()
{
    this->root=NULL;
}

CircularList::getElementCount()
{
  size_t contador=0;
  lista *referencia=this->root;
    if(this->root!=NULL)
    {
        contador++;
        while(referencia->next!=this->root)
        {
            contador++;
            referencia=referencia->next;
        }
    }
    return contador;
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

/*
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
*/
/*
void testPushFront() {
    CircularList list;
    list.pushFront(1);
    list.pushFront(2);
    list.pushFront(3);
    assert(list.getElementCount() == 3);
    assert(list.getFirst()->val == 3);
    assert(list.getLast()->val == 1);
}
*/
int main() {
    testPushBack();
    testErase();
    testPushFront();

    return 0;
}
