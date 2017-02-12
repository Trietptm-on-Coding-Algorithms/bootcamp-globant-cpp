#include <iostream>
#include <assert.h>

using namespace std;

//typedef unsigned int size_t; // Si usan visual studio (probablemente) no necesitan este typedef

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
    ListElement *root;

};

//  TODO: Complete
CircularList::CircularList(){
    this->root=NULL; //la clase crea una referencia a auna lista nula
}

CircularList::~CircularList(){
    while(this->getFirst()!=NULL)
        this->erase(this->getLast());
}

size_t CircularList::getElementCount(){
    size_t contador=0;
    ListElement *referencia=this->getFirst();
    //solo va a contar cuando existan elementos en la lista
    if(this->getFirst()!=NULL){
        contador++;
        while(referencia!=this->getLast()){
            contador++;
            referencia=referencia->next;
        }
    }
    return contador;
}

ListElement* CircularList::getLast(){
    ListElement *referencia=this->getFirst();
    //devuelve el ultimo nodo de la lista a menos que sea una lista vacia
    //en cuyo caso devuelve NULL
    if(this->getFirst()!=NULL)
        while(referencia->next!=this->getFirst()){
            referencia=referencia->next;
        }
    return referencia;
}

ListElement* CircularList::getFirst(){
        return this->root;
}

ListElement* CircularList::pushBack(int elemVal){
    ListElement *nodo=new ListElement;
    //Agrego un elemento al final de la lista
    //se diferencian los casos de una lista vacia y una con elementos
    if(this->getFirst()!=NULL){
        this->getLast()->next=nodo;
    }
    else{
        this->root=nodo;
    }
    nodo->val=elemVal;
    nodo->next=this->getFirst();
    return nodo;
}

ListElement* CircularList::pushFront(int elemVal){
    ListElement *nodo=new ListElement;
    if(this->getFirst()!=NULL){
        nodo->next=this->getFirst();
        this->getLast()->next=nodo;
    }
    else{
        nodo->next=nodo;
    }
    nodo->val=elemVal;
    this->root=nodo;
    return nodo;
}

void CircularList::erase(ListElement* element){
    ListElement *referencia=this->getFirst();

    //Si la lista esta vacia no hace nada
    if(this->getFirst()!=NULL){
        //si solo hay un nodo en la lista
        if(this->getFirst()==referencia->next){
            this->root=NULL;
            delete element;
        }
        else{
            //si solo el nodo a eleminar es el primero de la lista
            if(this->getFirst()==element){
                referencia=this->getLast();
                referencia->next=this->getFirst()->next;
                this->root=referencia->next;
                delete element;
            }
            else{
                //si hay que eliminar un nodo final o de alguna posicion diferente a los caso anteriores
                //si el elemento no esta en la lista no se hace nada
                while(referencia->next!=element||referencia->next==this->getFirst())
                    referencia=referencia->next;
                if(referencia->next==element){
                    referencia->next=referencia->next->next;
                    delete element;
                }
            }
        }
    }
}

void CircularList::insertNextTo(ListElement* element, int elemVal){
    ListElement *referencia=this->getFirst();
    ListElement *nodo=new ListElement;
    nodo->val=elemVal;
    //tenemos que ver los casos en los que se encuentre el nodo y
    //donde el nodo no exista una lista
    if(referencia!=NULL){
        //caso donde el primer nodo es el que se quiere buscar
        if(referencia==element){
            nodo->next=this->getFirst()->next;
            this->getFirst()->next=nodo;
        }
        else{
            //caso que el nodo tenga que agregarse en el ultimo lugar de la lista
            if(element==this->getLast()){
                nodo->next=this->getFirst();
                this->getLast()->next=nodo;
            }
            else{
                //caso en donde el elemento es un nodo dentro de la lista o no existe
                while(referencia!=element||referencia->next==this->getFirst())
                    referencia=referencia->next;
                //caso en el que no existe el nodo que se referencia
                if(referencia!=element)
                    delete nodo;
                else{
                    nodo->next=referencia->next;
                    referencia->next=nodo;
                }
            }

        }

    }
    else{
        //caso en el que la lista esta vacia
        this->root=nodo;
        nodo->next=nodo;
    }

}

void CircularList::clear(){
    //borramos todo?
    while(this->getFirst()!=NULL)
        this->erase(this->getLast());
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
