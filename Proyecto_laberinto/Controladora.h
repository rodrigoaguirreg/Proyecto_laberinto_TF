#pragma once
#define _CONTROLADORA_H_
#define _CONTROLADORA_H_
#include<time.h>
#include "laberinto.h"
#include "protagonista.h"
#include "aliados.h"
#include "enemigos.h"

class CControladora
{
public:
	CControladora(int v,int e, int t) {
		Mapa = new CMapa();
		oProta = new Cprotagonista(50, 50,3);// verificar / 3 == cantidad de vidas
		oAliados = new CAliados(50, 50);
		oAsesino = new CAsesino();
		cooldown_ataque_asesino = 0;
		tiempo=t*1000;
	}

	~CControladora() {}
	void MapaAleatoria() {
		Mapa->generarMatriz();
	}
void dibujar(Graphics^ g, Bitmap^ base, Bitmap^ solido, Bitmap^ camino,Bitmap^ prota, Bitmap^aliados, Bitmap^corrupto, Bitmap^Asesino, int **matriz){
		g->DrawString("Tiempo: "+((tiempo - clock())/1000),gcnew Font("Arial",12),Brushes::Black,0,20);
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
bool Mover(Graphics^g){

if(oAsesino->Colision(oProta->Area()) && clock() - cooldown_ataque_asesino >= 3000 ){ //restara una vida despues de 3 segundos 
	 oProta->setVidas(-1);
	//cooldown tiempo de espera para hacer otro daño
	cooldown_ataque_asesino = clock();//guarda el tiempo en milisegundos desde el ataque

	if (oProta->getVidas() == 0)
		return false;
	}
	if(clock()>=tiempo)
		return false;
	oAsesino>mover(g);
	
	oAliados->moverAliados(g,oAliados);

	return true;                                                                                  
}
private: 

	CAliados* oAliados;
	CAsesino* oAsesino;
	int coolcown_ataque_asesino;
	Cprotagonista* oProta;
	CMapa* Mapa;
	int tiempo;
	int cooldown_ataque_asesino;

};