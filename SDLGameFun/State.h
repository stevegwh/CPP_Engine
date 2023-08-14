#pragma once
#include <memory>

class State
{
protected:
    State() = default;
public:
    //    State();
    virtual ~State();
    virtual bool CheckCondition() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Draw() = 0;
    std::shared_ptr<State> next;
};
