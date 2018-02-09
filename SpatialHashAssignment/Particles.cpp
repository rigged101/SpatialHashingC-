#include "Particles.h"



Particles::Particles()
{
	x = 0;
	y = 0;
}


Particles::~Particles()
{
}

void Particles::drawParticle(SDL_Renderer *_Renderer) // draws the pixel based on its x and y coordinates
{
	SDL_RenderDrawPoint(_Renderer, x, y);

}
