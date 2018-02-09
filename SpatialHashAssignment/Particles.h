#pragma once
#include <memory>
#include <SDL.h>

class Container; // intialises the container class saying it can be used as its going to be needed later

class Particles
{
public:
	
	std::weak_ptr<Container> owner; // a weak pointer to the owner of this particle applies for each of the particles 
	void drawParticle(SDL_Renderer *_Renderer); // function to draw the particle
	int x, y; // x and y coordinate variables for the particle based on the screen

	Particles();
	~Particles();

};