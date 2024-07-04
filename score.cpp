#include "score.h"
#include <cstring>
#include <iostream>

Score::Score( int point)
{
	points = point;
}

int Score::getPoints()
{
	return points;
}

void Score::Show()
{

	std::cout << points << std::endl;

	return;
}

void Score::setName(const char* _name)
{
	strcpy_s(name, _name);
}

const char* Score::getName()
{
	return name;
}


