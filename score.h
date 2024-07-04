#pragma once
#include <string>

class Score
{
private:
	int points;
	char name[10];
public:
	Score(int point);
	Score() {};
	int getPoints();
	void Show();
	void setPoint(int po) {

		points = po;
		return;
	}
	void setName(const char* name);
	const char* getName();
};

