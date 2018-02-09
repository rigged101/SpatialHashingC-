#pragma once
#include <memory>
#include <vector>

class Particles; // temporary Particle class intanstiation so that this class knows it will later be used
class Container
{
public:
	
	int x, y; // specific coordantes for each container for the hash
	std::vector<std::shared_ptr<Particles>> particle; // vector of particles for the container
	Container(int _x, int _y); // initialises x and y coordinates
	~Container();
};