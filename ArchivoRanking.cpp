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
		file.mostrar();

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
		file.mostrar();
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
		file.mostrar();
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
		file.mostrar();
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

void archivoRanking::cargar() {

	int n;
	FILE* p;
	score obj[5];

	fopen_s(&p, "score.dat", "wb");
	for (int i = 0; i < 5; i++)
	{
		std::cout << "valor: ";
		std::cin >> n;
		std::cout << std::endl;
		obj[i].setPoint(n);

		fwrite(&obj[i], sizeof(score), 1, p);
	}



	fclose(p);

	return;
}

void archivoRanking::mostrar() {
	FILE* p;
	score obj[5];
	int i = 0;

	fopen_s(&p, "score.dat", "rb");

	while (fread(&obj[i], sizeof(score), 1, p) == 1) {
		// std::cout<<"valor i: "<<i;
		obj[i].Show();
		i++;

	}
	fclose(p);
	return;
}

void archivoRanking::cargarAr(score reg)
{
	FILE* p;
	 fopen_s(&p, "score.dat", "ab");
	if (p == NULL) return;
	bool escribio = fwrite(&reg, sizeof reg, 1, p);
	fclose(p);
	return;
}

