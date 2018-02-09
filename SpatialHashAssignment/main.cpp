#include <iostream>
#include "Game.h"
#include "FPS.h"


int main(int argc, char* argv[])
{

	FPS fps; // initialising FPS class
	Game game; // initialising main game class
	game.createHash(); // sets up the hash
	fps.fpsinit(); // setsup the fps parameters
	while (true) { // main update loop

		
		game.listenForExit(); // listens for the exit input i.e. pressing the x button on the window
		if (game.listenForExit() == true) // checks if the exit variable has been met
		{
			break;
		}
	
		game.playerInput(); // listens for player input, if there is any starts the function
		game.Update(); // updates the game class, includes all particle updates etc
		game.RefreshHashBuckets(); // updates the hash, and all of the collisions
		fps.fpscalculation(); // calculates the fps/ screen refresh rate
		printf("FPS: %f\n", fps.framespersecond); // outputs the fps into the console window


		
	}
	game.gameQuit(); // exits the game, calling the sdl quit function


	return 0;
}