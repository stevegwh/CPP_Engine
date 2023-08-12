#include "GEvent.h"

#include <iostream>
#include <ostream>

void GEvent::InvokeAllEvents() const
{
	for (Observer* ob : observerList)
	{
		ob->callback();
	}
}

void GEvent::Subscribe(Observer* observer)
{
	observerList.push_back(observer);
}

void GEvent::Unsubscribe(Observer* observer)
{
	for (auto it = observerList.begin(); it != observerList.end(); ++it)
	{
		std::cout << "Iterator: " << *it << std::endl;
		std::cout << "Iterated: " << observer << std::endl;
		if (*it == observer)
		{
			observerList.erase(it);
			break;
		}
	}
}

GEvent::GEvent() = default;
