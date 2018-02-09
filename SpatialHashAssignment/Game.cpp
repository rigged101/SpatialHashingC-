#include "Game.h"




Game::Game()
{

	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Hello", posX, posY, width, height, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	particleContainerInit(2000);

	
	

	Update();

}


Game::~Game()
{
}

void Game::Update()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); // sets the screen to black
	SDL_RenderClear(renderer); // clears the renderer
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // sets the particle pixel colour

	UpdateParticle(); // updates the position and redraws the particles
	
	SDL_RenderPresent(renderer); // draws everything through the renderer


	

}


void Game::particleContainerInit(int _i) // populates the vector with particles at a set starting position
{

	for (int i = 0; i < _i; i++)
	{
		particle.x = rand() % width;
		particle.y = rand() % height;
		container.push_back(std::make_shared<Particles> (particle));
		

	}
}

void Game::particleContainerDel(int _i) // deletes particles from the vector
{
	
	
	if (container.empty())
	{
		particleContainerInit(1000);
	}
	else
	{
		for (int i = 0; i < _i; i++)
		{

			container.pop_back();

		}
	}
	

}

void Game::UpdateParticle() // particle update function
{

	int mini = -5;
	int maxi = 5;
	int size = container.size();
	std::cout << "Particles: " << container.size() << "\n";
	for (size_t i = 0; i < container.size(); i++) // bounding box for loop that checks each of the particles if they go out of the screen
	{

		container.at(i)->drawParticle(renderer); // draws the particle
		container.at(i)->x += rand() % (maxi - mini + 1) + mini; // gives x coordinate random value to move to next
		container.at(i)->y += rand() % (maxi - mini + 1) + mini; // gives y coordinate random value to move to next
		if (container.at(i)->x >= width )
		{
			container.at(i)->x += -20;
		}
		if (container.at(i)->x <= 0)
		{
			container.at(i)->x += 20;
		}
		if (container.at(i)->y >= height)
		{
			container.at(i)->y += -20;
		}
		if (container.at(i)->y <= 0)
		{
			container.at(i)->y += 20;
		}
	}

	
}


void Game::gameQuit() // game exit function
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::playerInput() // player input function using sdl
{
	
		if(event.type == SDL_KEYDOWN) 
		{
				switch (event.key.keysym.sym)
				{
				case SDLK_UP: // if up add particles
					particleContainerInit(1000);
					break;
				case SDLK_DOWN: // if down delete particles
					particleContainerDel(1000);
				default:
					break;
				}
			

		}

	
}

bool Game::listenForExit() // listen for exit function
{
	if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
	{
		return true;
	}

	return false;
}

void Game::createHash() // creates the hash table
{
	hashTable.CreateHash(width, height, 100);
}
void Game::RefreshHashBuckets() // refreshes the buckets within the hash, using the hashtable class
{
	hashTable.RefreshBuckets(container, width, 100);
	
}

