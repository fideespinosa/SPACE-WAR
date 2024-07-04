#pragma once
#include <string>

class score
{
private:
	int points;
	char name[10];
public:
	score(int point);
	score() {};
	int getPoints();
	void Show();
	void setPoint(int po) {

		points = po;
		return;
	}
	void setName(const char* name);
	const char* getName();
};

