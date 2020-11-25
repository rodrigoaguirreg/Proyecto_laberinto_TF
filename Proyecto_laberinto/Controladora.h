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
	CControladora(int v,int t) {
		Mapa = new CMapa();
		oProta = new Cprotagonista(50, 50, v);
		oAliados = new CAliados(50, 50,t);
		oAsesino = new CAsesino();
		tiempo = t * 1000;
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
	bool Mover(Graphics^ g) {
		if (enemigo->Colision(oProta->Area()) && clock() - cooldownAtaqueEnemigo >= 2000) {
			oProta->setVidas(-1);
			cooldownAtaqueEnemigo = clock();
			if (oProta->getVidas() == 0)
				return false;
		}
	}
	void mostrar(Graphics^g, Bitmap^ prota, Bitmap^ aliados, Bitmap^ Asesino, Bitmap^ corrupto, int** matriz){
		g->DrawString("Tiempo: "+ clock(),gcnew Font("Arial",12),Brushes::Black,0,20);
		oProta->dibujarProta(g,prota);
		oAliados->dibujarAliados(g, aliados);
		oAsesino->dibujar(g, Asesino, corrupto,matriz);
	}
	private:
	CMapa* Mapa;
	Cprotagonista* oProta;
	CAliados* oAliados;
	CAsesino* oAsesino;
	Enemigos* enemigo;
	int tiempo;
	int cooldownAtaqueEnemigo = 0;
};