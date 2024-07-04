#include "score.h"
#include <cstring>
#include <iostream>

score::score( int point)
{
	points = point;
}

int score::getPoints()
{
	return points;
}

void score::Show()
{

	std::cout << points << std::endl;

	return;
}

void score::setName(const char* _name)
{
	strcpy_s(name, _name);
}

const char* score::getName()
{
	return name;
}


