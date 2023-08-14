#pragma once
#include "Entity.h"

class Player :
    protected Entity
{
private:
    SDL_Rect* rect;
    Position* pos;
    Scale* scale;
public:
    Player();
    ~Player() override;
    void EventTest();
    void Update(float deltaTime) override;
    void Draw(SDL_Renderer* renderer) override;
    void SetPosition(float x, float  y) override;
    const Position& GetPosition() override;
    void SetScale(int w, int  h) override;
    const Scale& GetScale() override;
};

