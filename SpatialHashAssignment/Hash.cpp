#include "Hash.h"


Hash::Hash()
{

}


Hash::~Hash()
{

}

void Hash::CreateHash(int _gridWidth, int _gridHeight, int _cellSize) // creates the hash
{
	column = _gridWidth / _cellSize; // counts the amount of columns based on width and cellsize
	row = _gridHeight / _cellSize; // counts the amount of rows based on height and cell size

	for (int i = 0; i < column; i++) // 2 dimensional for loop to assign coordinates for all of the buckets
	{
		for (int j = 0; j < row; j++)
		{
			bucket.push_back(std::make_shared<Container>(i,j)); // pushes the coordinates into the bucket vector
		}
		
	}
	
	
}

void Hash::RefreshBuckets(std::vector<std::shared_ptr<Particles>> &_myVector, int _gridWidth, int _cellSize) // updates the buckets and collisions
{
	int mini = -10; // values for collision 
	int maxi = 10; // when the particles collide
	srand(time(NULL));
	
	for (int i = 0; i < _myVector.size(); i++) // goes through all of the particles and pushes the particles into their correct bucket ids
	{
		bid = GetBucketIdForParticle(_gridWidth, _cellSize, _myVector, i); // sets bid using the hash function
		std::weak_ptr<Container> b = bucket.at(bid); // uses the bucket id reference and stores it into a temp container
		if (_myVector.at(i)->owner.lock().get() != b.lock().get()) // checks if the particles owner is the same or not, if its not it assigns the new owner
		{

			_myVector.at(i)->owner = b; // assigns the correct bucket id coordinates to the particles
			bucket.at(bid)->particle.push_back(_myVector.at(i));

		}
	}
	
	

	// collision detection
	for (int l = 0; l < bucket.size(); l++) // iterates through all of the buckets
	{
		for (int j = 0; j < bucket.at(l)->particle.size(); j++) // checks each particle within that bucket(l)
		{
			for (int k = 0; k < bucket.at(l)->particle.size(); k++) // checks each of the particles (k)  out of the same vector of the bucket using the second for loop
			{
				if (bucket.at(l)->particle.at(j)->x == bucket.at(l)->particle.at(k)->x && bucket.at(l)->particle.at(j)->y == bucket.at(l)->particle.at(k)->y)	// checks each of the particle in the bucket
																																								// then if the particles collide i.e. have same coordinates does the below 
				{
					int tempRand = rand() % 2;
					bucket.at(l)->particle.at(k)->x += choices[tempRand]; // add to x coordinate
					bucket.at(l)->particle.at(k)->y += choices[tempRand]; // add to y coordinate
				}
			}
		}
		
	}
	ResetBuckets(); // clears each of the bucket containers for each hash id



}

int Hash::GetBucketIdForParticle(int _gridWidth, int _cellSize, std::vector<std::shared_ptr<Particles>> &_myVector, int _i) // gets the bucket id/hash id
{
	int width = _gridWidth / _cellSize; // gets the width of the vector

	int bucketID = (_myVector.at(_i)->x / _cellSize) + (_myVector.at(_i)->y / _cellSize) * width; // gets the bucket id

	

	if (bucketID >= bucket.size()) // if some particles go way out of range of the hash size it does a sort of second bounding cleanup
	{
		return 0;
	}

	return bucketID; // returns buckets id
}

void Hash::ResetBuckets() // resets the buckets
{

	for (int i = 0; i < bucket.size(); i++) // for each of the bucket while it goes through each of the buckets deletes the container contents
	{
		while (!bucket.at(i)->particle.empty())
		{
			bucket.at(i)->particle.pop_back();
		}
	}
}






