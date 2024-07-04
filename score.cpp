#include "score.h"
#include <cstring>
#include <iostream>
score::score(std::string n, int point)
{
	name = n;
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
