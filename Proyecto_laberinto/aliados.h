#pragma once
#ifndef _ALIADOS_H_
#define _ALIADOS_H_

#include "protagonista.h"

using namespace System::Drawing;
enum Direccioness { Arribaa, Abajoo, Izquierdaa, Derechaa, Ningunaa };
class CAliados :public Cprotagonista
{
public:
	CAliados(int x, int y, int t) : Cprotagonista(x,y,t) {
		//posicion del jugador
		this->x = x;
		this->y = y;
		this->tiempo = t;
		//mov del jugador

		dx = 0;
		dy = 0;
		//animacion del sprite

		ancho = 33; //99 /3
		alto = 46.75;//187/4

		indiceX = 0;
		indiceY = 0;
		direccion = Direccioness::Abajoo;
		ultima = Direccioness::Abajoo;
	}
	~CAliados() {

	}
	void setDireccionn(Direccioness direccion) {
		this->direccion = direccion;
	}
	void dibujarAliados(Graphics^ g, Bitmap^ aliados) {
		Rectangle PorcionAUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle Aumento = Rectangle(x, y, ancho * 3, alto * 3);
		g->DrawImage(aliados, Aumento, PorcionAUsar, GraphicsUnit::Pixel);
		x += dx;
		y += dy;
	}
	void moverAliados(Graphics^ g, Bitmap^ aliados) {
		direccion == Arribaa ? ancho = 45 : ancho = 46; //ni idea v,:
		switch (direccion)
		{
		case Direccioness::Arribaa:
			indiceY = 0;
				if (indiceX >= 1 && indiceX < 2)
					indiceX++;
				else
					indiceX = 1;
			dx = 0;
			dy = -10;
			ultima = Direccioness::Arribaa;

			break;
		case Direccioness::Abajoo:
			indiceX = 0;
			if (indiceY >= 1 && indiceY < 2)
				indiceY++;
			else
				indiceY = 1;
			dx = 0;
			dy = -10;
			ultima = Direccioness::Abajoo;
			break;
		case Direccioness::Izquierdaa:
			indiceY =3;
			if (indiceX>= 1 && indiceX < 2)
				indiceX++;
			else
				indiceX = 1;
			dx = -10;
			dy = 0;
			ultima = Direccioness::Izquierdaa;
			break;
		case Direccioness::Derechaa:
			indiceY = 1;
			if (indiceX >= 1 && indiceX < 2)
				indiceX++;
			else
				indiceX = 1;
			dx = 10;
			dy = 0;
			ultima = Direccioness::Derechaa;
			break;
		case Direccioness::Ningunaa:
			dx = dy = 0;
			if (ultima == Direccioness::Abajoo) {
				indiceX = 0;
				indiceY = 2;
			}
			if (ultima == Direccioness::Arribaa) {
				indiceX = 0;
				indiceY = 0;
			}
			if (ultima == Direccioness::Derechaa) {
				indiceX = 1;
				indiceY = 1;
			}
			if (ultima == Direccioness::Izquierdaa) {
				indiceX = 1;
				indiceY = 3;
			}
			break;
		default:
			break;
		}
		dibujarProta(g, aliados);
	}
private:
	int x;
	int y;
	int dx;//horizontal
	int dy;//vertical
	int ancho;
	float alto;
	int indiceX;//animacion
	int indiceY;//animacion
	int tiempo;//animacion

	Direccioness direccion;
	Direccioness ultima;

}
#endif
//ultima tecla presionada para saber la posicion en la que la deje
/*
private:
	int x;
	int y;
	int dx;//horizontal
	int dy;//vertical
	int ancho;
	int alto;
	int indiceX;//animacion
	int indiceY;//animacion

	Direcciones direccion;
	Direcciones ultima;//ultima tecla presionada para saber la posicion en la que la deje
};
*/