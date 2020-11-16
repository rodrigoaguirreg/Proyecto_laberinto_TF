#pragma once
#include "protagonista.h"
using namespace System::Drawing;
enum Direcciones { Arriba, Abajo, Izquierda, Derecha, Ninguna };
class CAliados :public Cprotagonista
{
public:
	CAliados(int x, int y) : Cprotagonista(x, y) {
		//posicion del jugador
		this->x = x;
		this->y = y;
		//mov del jugador

		dx = 0;
		dy = 0;
		//animacion del sprite

		ancho = 33; //99 /3
		alto = 46.75;//187/4

		indiceX = 0;
		indiceY = 0;
		direccion = Direcciones::Ninguna;
		ultima = Direcciones::Abajo;
	}
	~CAliados() {

	}
	void setDireccion(Direcciones direccion) {
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
		direccion == Arriba ? ancho = 45 : ancho = 46;
		switch (direccion)
		{
		case Direcciones::Arriba:
			indiceX = 3;
			if (indiceY >= 1 && indiceY < 2)
				indiceY++;
			else
				indiceY = 1;
			dx = 0;
			dy = 10;
			ultima = Direcciones::Arriba;

			break;
		case Direcciones::Abajo:
			indiceX = 0;
			if (indiceY >= 1 && indiceY < 2)
				indiceY++;
			else
				indiceY = 1;
			dx = 0;
			dy = -10;
			ultima = Direcciones::Abajo;
			break;
		case Direcciones::Izquierda:
			indiceY = 1;
			if (indiceX >= 1 && indiceX < 2)
				indiceX++;
			else
				indiceX = 1;
			dx = -10;
			dy = 0;
			ultima = Direcciones::Izquierda;
			break;
		case Direcciones::Derecha:
			indiceY = 2;
			if (indiceX >= 1 && indiceX < 2)
				indiceX++;
			else
				indiceX = 1;
			dx = 10;
			dy = 0;
			ultima = Direcciones::Derecha;
			break;
		case Direcciones::Ninguna:
			dx = dy = 0;
			if (ultima == Direcciones::Abajo) {
				indiceX = 0;
				indiceY = 2;
			}
			if (ultima == Direcciones::Arriba) {
				indiceX = 0;
				indiceY = 0;
			}
			if (ultima == Direcciones::Derecha) {
				indiceX = 1;
				indiceY = 1;
			}
			if (ultima == Direcciones::Izquierda) {
				indiceX = 1;
				indiceY = 3;
			}
			break;
		default:
			break;
		}
		dibujarProta(g, aliados);
	}
protected:
	int x;
	int y;
	int dx;//horizontal
	int dy;//vertical
	int ancho;
	float alto;
	int indiceX;//animacion
	int indiceY;//animacion

	Direcciones direccion;
	Direcciones ultima;//ultima tecla presionada para saber la posicion en la que la deje

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