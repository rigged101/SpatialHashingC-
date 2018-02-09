#pragma once
#include "Hash.h" // includes hash for the hash table function updates
#include <iostream>




class Game
{
public:
	Game();
	~Game();
	
	std::vector<std::shared_ptr<Particles>> container; // container for all of the particles


	Hash hashTable; // initialises the hastable class
	void createHash(); // creates the hash
	void RefreshHashBuckets(); // refreshes and updates the hash
	
	SDL_Renderer *renderer = NULL;	// initialises the renderer and sets it to null
	SDL_Window *window = NULL;	// initialises the window and sets it to null
	SDL_Event event;	// creates the event stream

	Particles particle;	// creates an instance of a particle
	
	


	int posX = 100 , posY = 100, width = 1200, height = 600; // parameters for the window size, and location where it shows up on the screen
	
	void Update();	// update function to update everything
	void gameQuit();	// sdl based game quit function, exits the game when called
	void playerInput();	// function that listen for player input using sdl
	bool listenForExit(); // function that waits for an exit call to close the program
	void particleContainerInit(int _i); // initialises the vector and populates the vector with particles
	void particleContainerDel(int _i); // deletes a specific amount of particles from the vector of particles in this case a 1000 per iteration
	void UpdateParticle(); // updates the particles position and draws to the screen
};

