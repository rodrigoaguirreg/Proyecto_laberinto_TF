#pragma once
#include<ctime>
#include<stdlib.h>
#ifndef _MAPA_H_
#define _MAPA_H_
#define Filas 15
#define Columnas 17
using namespace System::Drawing;
class CMapa
{
public:
	CMapa(){
		matriz = new int *[Filas];
	}
	~CMapa(){}
	void generarMatriz() {
		srand(time(NULL));
		for (int i = 0; i < Filas; i++) {//por cada fila tendrà ciertas columnas
			matriz[i] = new int[Columnas];
		}

		for (int i = 0; i < Filas; i++)//si i=fila-1 se llenara de 1
		{
			for (int j = 0; j < Columnas; j++)// si j=columas-1 es cero me lo llena de 1 
			{
				if (i == 0 || j == 0 || i == Filas - 1 || j == Columnas - 1) //bloques fijos en los bordes
					matriz[i][j] = 1;
				else
				{
					if (i % 2 == 0 || j % 2 == 0) //Bloques fijos del interior del mapa
						matriz[i][j] = 1;
				
				else
				{
					if (i == 1 && (j == 1 || j == 2) || (j == 1 && i == 2) || (i = Filas - 2 && (j == Columnas - 3) || (j == Columnas - 2)) || (i == Filas - 3 && j == Columnas - 2))//Zona en la que el jugador se puede mover 
						matriz[i][j] = 0; //el juegador se mueve
					else // zonas que quedan que dependiendo del valor sera camino 2
						matriz[i][j] = rand() % 2;

				}
			}
		}

	}

	}
	void PintarBase(Graphics ^g, Bitmap^base) {
		int X = 0, Y = 0;
		for (int i = 0; i < Filas; i++) {
			X = 0;
			for (int j = 0; j < Columnas; j++)
			{
				if (matriz[i][j] == 0 || matriz[i][j] == 2)
					g->DrawImage(base, X, Y, 50, 50);
				X += 50;
			}
			Y += 50;
		}
	}
	void PintarMatriz(Graphics ^g, Bitmap^solido, Bitmap^camino) {
		int X = 0, Y = 0;
		for (int i = 0; i < Filas; i++) {
			X = 0;
			for (int j = 0; j < Columnas; j++)
			{
				if (matriz[i][j] == 1)
					g->DrawImage(solido, X, Y, 50, 50);
				else{
					if (matriz[i][j] == 3)
						g->DrawImage(camino, X, Y, 50, 50);
				}
				X += 50;
			}
			Y += 50;
		}
	}

	int **getmatriz() {
		return matriz;
	}
private:
	int **matriz;

};




#endif
