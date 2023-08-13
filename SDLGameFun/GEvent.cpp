#include "GEvent.h"

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
		if (*it == observer)
		{
			observerList.erase(it);
			break;
		}
	}
}

GEvent::GEvent() = default;
