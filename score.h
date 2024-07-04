#pragma once
#include <string>

class score
{
private:
	int points;
	std::string name;
public:
	score(std::string n, int point);
	score();
	int getPoints();
	void Show();
	void setPoint(int po) {

		points = po;
		return;
	}
	std::string getName() {
		return name;
	}
	void setName(std::string n) {
		name = n;
	}

};

