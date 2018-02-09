#include "FPS.h"



FPS::FPS()
{

}


FPS::~FPS()
{

}

void FPS::fpsinit() // initialisation of all of the variables for counting the fps
{
	SDL_memset(frametimes, 0, sizeof(frametimes));
	framecount = 0;
	framespersecond = 0;
	frametimelast = SDL_GetTicks();

}

void FPS::fpscalculation() // calculates fps
{
	Uint32 frametimeindex;
	Uint32 getTicks;
	Uint32 count;
	Uint32 i;

	frametimeindex = framecount % frame_values;

	getTicks = SDL_GetTicks(); // gets the tickrate 

	frametimes[frametimeindex] = getTicks - frametimelast; 

	frametimelast = getTicks;

	framecount++;

	if (framecount < frame_values)
	{
		count = framecount;
	}
	else
	{
		count = frame_values;
	}

	framespersecond = 0;
	
	for (i = 0; i < count; i++)
	{
		framespersecond += frametimes[i];

	}
	framespersecond /= count;

	framespersecond = 1000.0 / framespersecond;
}