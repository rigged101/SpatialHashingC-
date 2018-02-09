#pragma once
#include "Particles.h" //  includes the particles class
#include <memory> // used for shared/ weak pointers
#include <SDL.h> // for all of the SDL 
#include "Container.h" // inclues the container class
#include <vector> // allows the use of vector
#include <time.h> // used for printf 


class Hash
{
public:
	
	
	int column, row; // column and row variables for each of the grid cells for the hash
	std::vector<std::shared_ptr<Container>> bucket;	// the bucket vector for the hash
	int bid; // bucket id
	int choices[2] = { 5, -5 }; // random choices for collision
	void ResetBuckets(); // resets and refreshes the buckets
	void CreateHash(int _gridWidth, int _gridHeight, int _cellSize); // creates the hash for the screen size, based on width height and the cell size
	void RefreshBuckets(std::vector<std::shared_ptr<Particles>> &_myVector, int _gridWidth, int _cellSize); // updates each of the buckets ant re-assigns correct particles to each bucket
	int GetBucketIdForParticle(int _gridWidth, int _cellSize, std::vector<std::shared_ptr<Particles>> &_myVector, int _i); // actual hashing function to assign the correct id for each of the particles
	Hash();
	~Hash();
};

