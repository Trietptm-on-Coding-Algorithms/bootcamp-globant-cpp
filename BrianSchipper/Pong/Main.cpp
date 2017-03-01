#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
// Declaracion e inicializacion de variables
int main()

{
	bool play = false;
	bool opcion = false;

	Game game( play , opcion);
	
	if (play==true)
		game.Op_Play();
	else if (opcion==true)
		game.Op_Opcion();
	else
		exit;
}