#pragma once

#include <functional>
#include <vector>
#include "Observer.h"

class GEvent
{
private:
	std::vector<Observer*> observerList;
	
public:
	void Subscribe(Observer* observer);
	void Unsubscribe(Observer* observer);
	void InvokeAllEvents() const;
	GEvent();
};

