#pragma once
#ifndef _CONTROLADORA_H_
#define _CONTROLADORA_H_
#include "Mapa.h"
#include "protagonista.h"
class CControladora
{
public:
	CControladora(){
		Mapa = new CMapa();
        oProta = new CProta(50,50);
	}
	~CControladora(){}
	void MapaAleatoria() {
		Mapa->generarMatriz();
	}
	void dibujar(Graphics^ g,Bitmap^base ,Bitmap^solido, Bitmap^camino) {
		Mapa->PintarBase(g, base);
		Mapa->PintarMatriz(g, solido, camino);
        	oProta->moverProta(g, prota);
	}
     CProta* getoProta() {
		return oProta;
	}
private:
	CMapa* Mapa;
    CProta* oProta;
};


#endif // !_CONTROLADORA_H_