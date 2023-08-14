#pragma once
#include <SDL.h>
#include "Entity.h"
#include <vector>

class Game
{
private:
	std::vector<Entity*> entities;
	SDL_Renderer* renderer;

public:
	Game(SDL_Renderer* renderer);
	~Game();
	void Run();
	void Draw() const;
};

