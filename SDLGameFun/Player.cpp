#include "Player.h"
#include <iostream>

Player::Player()
{
	rect = new SDL_Rect();
	rect->x = 50;
	rect->y = 50;
	rect->w = 50;
	rect->h = 50;
	pos = new Position();
	pos->x = 50;
	pos->y = 50;
	scale = new Scale();
	scale->w = 50;
	scale->h = 50;
}

void Player::EventTest()
{
	std::cout << "Hello, world" << std::endl;
}

Player::~Player()
{
	delete rect;
	delete pos;
	delete scale;
}

void Player::Update(float deltaTime)
{
	rect->x = pos->x;
	rect->y = pos->y;
	rect->w = scale->w;
	rect->h = scale->h;
}

void Player::Draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 100, 100, 255);
	SDL_RenderFillRect(renderer, rect);
	SDL_RenderPresent(renderer);
}

void Player::SetPosition(float x, float y)
{
	pos->x = x;
	pos->y = y;
}

const Position& Player::GetPosition()
{
	return *pos;
}

void Player::SetScale(int w, int h)
{
	scale->w = w;
	scale->h = h;
}

const Scale& Player::GetScale()
{
	return *scale;
}
