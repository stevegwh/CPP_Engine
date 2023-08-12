#pragma once
#include <functional>
#include <utility>

struct Observer
{
	std::function<void()> callback;
	Observer(std::function<void()> func):callback(std::move(func)){}
};
