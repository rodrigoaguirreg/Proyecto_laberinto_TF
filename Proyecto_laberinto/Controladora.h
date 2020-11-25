#pragma once
#define _CONTROLADORA_H_
#define _CONTROLADORA_H_

#include "laberinto.h"
#include "protagonista.h"
#include "aliados.h"
#include "enemigos.h"
class CControladora
{
public:
	CControladora() {
		Mapa = new CMapa();
		oProta = new Cprotagonista(50, 50);
		oAliados = new CAliados(50, 50);
		oAsesino = new CAsesino();
	}

	~CControladora() {}
	void MapaAleatoria() {
		Mapa->generarMatriz();
	}
void dibujar(Graphics^ g, Bitmap^ base, Bitmap^ solido, Bitmap^ camino,Bitmap^ prota, Bitmap^aliados, Bitmap^corrupto, Bitmap^Asesino, int **matriz){

		Mapa->PintarBase(g, base);
		//Mapa->oAliadosMatriz(g, solido, camino);
		oProta->moverProta(g, prota);
		oAliados->moverAliados(g, aliados);
		oAsesino->dibujar(g, Asesino, corrupto, matriz);
		}

	Cprotagonista* getoProta() {
		return oProta;
	}
	
    	CAsesino* getoAsesino() {
		return oAsesino;
	}
	CAliados* getoAliados() {
		return oAliados;
	}
private:
	CMapa* Mapa;
	Cprotagonista* oProta;
	CAliados* oAliados;
	CAsesino* oAsesino;
};