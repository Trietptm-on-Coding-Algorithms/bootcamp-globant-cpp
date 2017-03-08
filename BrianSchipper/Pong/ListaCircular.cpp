#include "stdafx.h"
#include "ListaCircular.h"
#include <iostream>

using namespace std;


ListaCircular::ListaCircular()
{
	first = nullptr;
	last = nullptr;
}


ListaCircular::~ListaCircular()
{
	Clear();
}

ListElement*ListaCircular::pushFront(sf::Sprite &elemval)
{
	ListElement * newSprite = new ListElement();
	newSprite-> val = elemval;

	if (first == nullptr)
	{
		last = newSprite;
		first = newSprite;
		newSprite->next = newSprite;

	}
	else
	{
		first = newSprite;
		newSprite->next = first;
		last->next = newSprite;
	}

	return 0;
}
void ListaCircular::Clear()

{
	if (first != nullptr)
		do
		{
			ListElement*toDelete = first;
			delete toDelete;
			first = first->next;
		} while (first != nullptr);

		last = nullptr;
}
size_t ListaCircular::getElementCount()

{
	size_t count = 0;
	ListElement *aux = first;
	if (first != nullptr)
	{
		do {
			count++;
			aux = aux->next;
		} while (aux != first);
	}
	return count;
}

void ListaCircular::LoadList(sf::Texture &texture,ListaCircular &lista)
{
	sf::Sprite sprite;
	sprite.setTexture(texture);
	lista.pushFront(sprite);
}
