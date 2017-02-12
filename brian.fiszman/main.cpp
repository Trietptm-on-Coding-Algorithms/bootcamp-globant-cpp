#include <iostream>
#include <assert.h>

using namespace std;

struct ListElement {
    int val;
    ListElement* next;
};

class CircularList {
public:
    CircularList()
    {
        this->first = NULL;
        this->last  = NULL;
    }

    //    ~CircularList();

    ListElement* pushFront(int elemVal)
    {
        ListElement *le = new ListElement();
        le->val = elemVal;
        
        if (this->isEmpty())
        {
            this->first = this->last = le;
            this->last->next = this->first;
        }
        else
        {
            this->last->next = le;
            this->last = le;
            this->last->next = this->getFirst();
        }
        return le;
    }

    ListElement* pushBack(int elemVal)
    {
        ListElement *le = new ListElement();
        ListElement *aux = this->getFirst();
        le->val = elemVal;

        if (this->isEmpty())
        {
            this->first = this->last = le;
            this->last->next = this->first;
        }
        else
        {
            this->first = le;
            this->first->next = aux;
            this->last->next = this->getFirst();
        }
        return le;
    }

    void insertNextTo(ListElement* element, int elemVal);
    void erase(ListElement* element)
    {
        ListElement *aux = this->getFirst();
        if (this->getFirst() == element)
        {
            this->first = this->first->next;
            this->last->next = this->first;
            delete element;
        }
        else
        {
            for(size_t i = 0; i <= this->getElementCount(); i++)
            {
                if (aux->next == element)
                {
                    if (this->getLast() == element)
                    {
                        this->last = aux;
                        this->last->next = this->getFirst();
                    }
                    else
                    {
                        aux->next = aux->next->next;
                    }
                    delete element;
                    break;
                }
                aux = aux->next;
            }
        }
    }

    void clear();

    ListElement* getFirst(){ return this->first; }
    ListElement* getLast() { return this->last;  }

    size_t getElementCount()
    {
        if (this->isEmpty())
            return 0;            

        size_t elementCount = 0;
        ListElement* aux = this->getFirst();
        do {
            elementCount++;
            aux = aux->next;
        } while (this->getFirst() != aux);
        return elementCount;
    }
private:
    ListElement *first;
    ListElement *last;

    bool isEmpty()
    {
        return (this->first == NULL);
    }
};


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
