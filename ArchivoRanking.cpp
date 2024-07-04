#include "archivoRanking.h"
#include <iostream>
#include <cstring>
#include "score.h"


archivoRanking::archivoRanking()
{
}

void archivoRanking::ShowFile()
{
}

void archivoRanking::Max()
{
}

void archivoRanking::saveFile(int gamePoints, int i)
{
}

bool archivoRanking::CalculateFile(int Score)
{
	FILE* p;
	score score[5];

	 fopen_s (&p, "score.dat", "rb");

	if (p == NULL) {
		std::cout << "no se abrio el archivo en calculate file";
		system("pause");
	}

	for (int i = 0; i < 5; i++)
	{
		fread(&score[i], sizeof(score), 1, p);
		

		if (Score > score[i].getPoints()) {
			fclose(p);
			moveRanking(i, Score);
			
			return true;
		}

	}

	fclose(p);
	return false;
}

void archivoRanking::moveRanking(int pos, int Score)//cambiar el gamepoint para recibir la clase score
{
	int j = 0;
	int aux1 = 5, aux2 = 4;
	score aux;
	score obj[5];
	archivoRanking file;
	FILE* p;
	fopen_s(&p, "score.dat", "rb");
	if (p == NULL) {
		std::cout << "no se abrio el archivo en moveranking";
		system("pause");
	}
	fopen_s(&p, "score.dat", "rb");
	while (fread(&aux, sizeof(score), 1, p) == 1) {
		obj[j] = aux;
		j++;
	}
	fclose(p);

	switch (pos)
	{

	case 0:
		std::cout << "entro 0";
		for (int i = 0; i <= 4;i++) {

			obj[aux1--] = obj[aux2--];

		}
		obj[pos].setPoint(Score);//cambiar para hacer un = del score y no del gamepoint
		//file.mostrar();

		fopen_s(&p, "score.dat", "wb");

		for (int i = 0; i <= 4;i++) {

			fwrite(&obj[i], sizeof(score), 1, p);

		}
		fclose(p);
		break;
	case 1:
		std::cout << "entro 1";
		for (int i = 0; i <= 3;i++) {

			obj[aux1--] = obj[aux2--];

		}
		obj[pos].setPoint(Score);//cambiar para hacer un = del score y no del gamepoint
		//file.mostrar();
		fopen_s(&p, "score.dat", "wb");

		for (int i = 0; i <= 4;i++) {

			fwrite(&obj[i], sizeof(score), 1, p);

		}
		fclose(p);


		//fclose(p);
		break;
	case 2:
		std::cout << "entro 2";
		for (int i = 0; i <= 2;i++) {

			obj[aux1--] = obj[aux2--];

		}
		obj[pos].setPoint(Score);//cambiar para hacer un = del score y no del gamepoint
		//file.mostrar();
		std::cout << "aaaaaaaaaaaaaaaaaa";
		fopen_s(&p, "score.dat", "wb");

		for (int i = 0; i <= 4;i++) {

			fwrite(&obj[i], sizeof(score), 1, p);

		}
		fclose(p);


		//fclose(p);
		break;
	case 3:
		std::cout << "entro 3";
		for (int i = 0; i <= 1;i++) {

			obj[aux1--] = obj[aux2--];

		}
		obj[pos].setPoint(Score);//cambiar para hacer un = del score y no del gamepoint
		//file.mostrar();
		std::cout << "aaaaaaaaaaaaaaaaaa";
		fopen_s(&p, "score.dat", "wb");

		for (int i = 0; i <= 4;i++) {

			fwrite(&obj[i], sizeof(score), 1, p);

		}
		fclose(p);

		//fclose(p);
		break;
	case 4:
		fopen_s(&p,"score.dat", "wb");
		std::cout << "entro 4";
		obj[pos].setPoint(Score);//cambiar para hacer un = del score y no del gamepoint
		for (int i = 0; i <= 4;i++) {

			fwrite(&obj[i], sizeof(score), 1, p);

		}
		fclose(p);
	default:
		fclose(p);
		break;
	}

}

//eliminar despues

bool archivoRanking::cargar(score _score) {

	FILE* p;
	fopen_s(&p, "score.dat", "ab");
	if (p == NULL) {
		return false;
	}
	bool ok = (fwrite(&_score, sizeof(score), 1, p) == 1);
	if (!ok) {
		std::cout << "Error al escribir en el archivo" << std::endl;
	}
	fclose(p);
	return ok;

}

score archivoRanking::mostrar(int nroScore) {
	score obj;
	FILE* p;
	fopen_s(&p, "score.dat", "rb");

	if (p == NULL) {
		std::cout << "Error al abrir el archivo score.dat" << std::endl;
		return obj;
	}
	if (fseek(p, nroScore * sizeof(score), SEEK_SET) != 0) {
		std::cout << "Error al posicionar el puntero de archivo" << std::endl;
		fclose(p);
		return obj;
	}
	if (fread(&obj, sizeof(score), 1, p) != 1) {
		std::cout << "Error al leer del archivo" << std::endl;
	}
	fclose(p);
	return obj;
}


