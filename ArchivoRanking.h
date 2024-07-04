#pragma once
#include "Score.h"

class ArchivoRanking
{
private:
	Score Points[5];
	bool state;
public:
	ArchivoRanking() {};
	bool CalculateFile(Score score);//calcula el puntaje nuevo con los puntos anteriores
	void moveRanking(int i, Score _Score); //cambia el puesto para dejar un espacio libre donde se guarde el puntaje nuevo
	bool cargar(Score score);
	Score mostrar(int nroScore);
};
