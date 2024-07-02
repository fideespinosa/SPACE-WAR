#include "score.h"
#include <cstring>
#include <iostream>
int score::getPoints()
{
	return points;
}

void score::Show()
{

	std::cout << points << std::endl;

	return;
}
