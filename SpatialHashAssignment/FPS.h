#pragma once
#include <SDL.h>

class FPS
{
public:
	#define frame_values 20
	Uint32 frametimes[frame_values]; // initialises a frame time vector, so when it reaches the end it takes the amount of 
									 // time it took to get there, and calculates the fps based on that
	Uint32 frametimelast;	// check the last frame time
	Uint32 framecount;		// calculates the amount of frames
	float framespersecond;	// specifies the frames per second

	void fpsinit();			// initialises the fps parameters
	void fpscalculation();	// calculates the fps
	FPS();
	~FPS();
};

