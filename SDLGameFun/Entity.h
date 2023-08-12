#pragma once
#include "Transform.h"
#include <SDL.h>
class Entity
{
protected:
	Entity() {};
	virtual ~Entity() {};
public:
	virtual void Draw(SDL_Renderer* renderer) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void SetPosition(float x, float  y) = 0;
	virtual const Position& GetPosition() = 0;
	virtual void SetScale(int w, int  h) = 0;
	virtual const Scale& GetScale() = 0;
};

