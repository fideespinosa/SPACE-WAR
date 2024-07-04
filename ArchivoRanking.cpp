#include "archivoRanking.h"
#include <iostream>
#include <cstring>
#include "score.h"


ArchivoRanking::ArchivoRanking()
{
}


bool ArchivoRanking::CalculateFile(Score _Score)
{
	FILE* p;
	Score score[5];

	 fopen_s (&p, "score.dat", "rb");

	if (p == NULL) {
		std::cout << "no se abrio el archivo en calculate file";
		system("pause");
	}

	for (int i = 0; i < 5; i++)
	{
		fread(&score[i], sizeof(score), 1, p);
		

		if (_Score.getPoints() > score[i].getPoints()) {
			fclose(p);
			moveRanking(i, _Score);
			
			return true;
		}

	}

	fclose(p);
	return false;
}

void ArchivoRanking::moveRanking(int pos, Score _Score)
{
	int j = 0;
	int aux1 = 5, aux2 = 4;
	Score aux;
	Score obj[5];
	ArchivoRanking file;
	FILE* p;
	fopen_s(&p, "score.dat", "rb");
	if (p == NULL) {
		std::cout << "no se abrio el archivo en moveranking";
		system("pause");
	}
	while (fread(&aux, sizeof(Score), 1, p) == 1) {
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
		obj[pos]=_Score;
		fopen_s(&p, "score.dat", "wb");

		for (int i = 0; i <= 4;i++) {

			fwrite(&obj[i], sizeof(Score), 1, p);

		}
		fclose(p);
		break;
	case 1:
		std::cout << "entro 1";
		for (int i = 0; i <= 3;i++) {

			obj[aux1--] = obj[aux2--];
		}
		obj[pos] = _Score;
		fopen_s(&p, "score.dat", "wb");

		for (int i = 0; i <= 4;i++) {

			fwrite(&obj[i], sizeof(Score), 1, p);

		}
		fclose(p);
		break;
	case 2:
		std::cout << "entro 2";
		for (int i = 0; i <= 2;i++) {

			obj[aux1--] = obj[aux2--];

		}
		obj[pos] = _Score;
		fopen_s(&p, "score.dat", "wb");

		for (int i = 0; i <= 4;i++) {

			fwrite(&obj[i], sizeof(Score), 1, p);

		}
		fclose(p);


		
		break;
	case 3:
		std::cout << "entro 3";
		for (int i = 0; i <= 1;i++) {

			obj[aux1--] = obj[aux2--];

		}
		obj[pos] = _Score;
		fopen_s(&p, "score.dat", "wb");

		for (int i = 0; i <= 4;i++) {

			fwrite(&obj[i], sizeof(Score), 1, p);

		}
		fclose(p);

		break;
	case 4:
		fopen_s(&p,"score.dat", "wb");
		std::cout << "entro 4";
		obj[pos] = _Score;
		for (int i = 0; i <= 4;i++) {

			fwrite(&obj[i], sizeof(Score), 1, p);

		}
		fclose(p);
	default:
		fclose(p);
		break;
	}

}

//eliminar despues

bool ArchivoRanking::cargar(Score _score) {

	FILE* p;
	fopen_s(&p, "score.dat", "ab");
	if (p == NULL) {
		return false;
	}
	bool ok = (fwrite(&_score, sizeof(Score), 1, p) == 1);
	if (!ok) {
		std::cout << "Error al escribir en el archivo" << std::endl;
	}
	fclose(p);
	return ok;

}

Score ArchivoRanking::mostrar(int nroScore) {
	Score obj;
	FILE* p;
	fopen_s(&p, "score.dat", "rb");

	if (p == NULL) {
		std::cout << "Error al abrir el archivo score.dat" << std::endl;
		return obj;
	}
	if (fseek(p, nroScore * sizeof(Score), SEEK_SET) != 0) {
		std::cout << "Error al posicionar el puntero de archivo" << std::endl;
		fclose(p);
		return obj;
	}
	if (fread(&obj, sizeof(Score), 1, p) != 1) {
		std::cout << "Error al leer del archivo" << std::endl;
	}
	fclose(p);
	return obj;
}


