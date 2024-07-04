#pragma once
#include "score.h"
class ArchivoRanking
{
private:
	Score Points[5];
	bool state;
public:
	ArchivoRanking();
	void ShowFile();//muestra el archivo
	void Max();
	void saveFile(int gamePoints, int i); //guarda el puntaje nuevo en su respectivo lugar
	bool CalculateFile(Score score);//calcula el puntaje nuevo con los puntos anteriores
	void moveRanking(int i, Score _Score); //cambia el puesto para dejar un espacio libre donde se guarde el puntaje nuevo
	bool cargar(Score score);
	Score mostrar(int nroScore);
};
