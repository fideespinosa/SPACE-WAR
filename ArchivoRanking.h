#pragma once
#include "score.h"
class archivoRanking
{
private:
	score Points[5];
	bool state;
public:
	archivoRanking();
	void ShowFile();//muestra el archivo
	void Max();
	void saveFile(int gamePoints, int i); //guarda el puntaje nuevo en su respectivo lugar
	bool CalculateFile(score Score);//calcula el puntaje nuevo con los puntos anteriores
	void moveRanking(int i, score Score); //cambia el puesto para dejar un espacio libre donde se guarde el puntaje nuevo
	void cargar();
	void mostrar();
};
