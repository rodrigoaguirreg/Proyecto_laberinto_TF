#pragma once
#define _PROTAGONISTA_H_
using namespace System::Drawing;
enum Direcciones { Arriba, Abajo, Izquierda, Derecha, Ninguna };
 class Cprotagonista
{
    public:
		Cprotagonista(int x, int y, int v){
		//posicion del jugador
		this->x = x;
		this->y = y;
		//mov del jugador

		dx = 0;
		dy = 0;
		//animacion del sprite

		ancho = 46; //138 /3
		alto = 65;//260/4
		vidas=1;
		indiceX = 0;
		indiceY = 0;
		direccion = Direcciones::Ninguna;
		ultima = Direcciones::Abajo;
	}
	~Cprotagonista() {
	}

	void setVidas(int value) {//vidas de adicion 
		vidas += value;
	}
	int getVidas() {
		return vidas;
	}
	void setDireccion(Direcciones direccion ) {
		this->direccion = direccion;
	}
	int Area() {
		return ancho * alto;
	}
		return ancho * alto;
	}
		return ancho * alto;
	}
		return ancho * alto;
	}
		return ancho * alto;
	}
	void dibujarProta(Graphics^g, Bitmap^prota) {
		Rectangle PorcionAUsar = Rectangle(indiceX*ancho, indiceY* alto, ancho, alto);
		Rectangle Aumento = Rectangle(x, y, ancho*3, alto*3);
		g->DrawImage(prota, Aumento, PorcionAUsar, GraphicsUnit::Pixel);
			x += dx;
			y += dy;
		g->DrawString("Vidas:  " + vidas,gcnew Font("Arial", 12), Brushes::Black,0,0);
	}
	void moverProta(Graphics^g, Bitmap^prota) {
		direccion == Arriba ? ancho = 45 : ancho = 46;
		switch (direccion)
		{
		case Direcciones::Arriba:
			indiceY = 0;
				if (indiceX >= 1 && indiceX < 2)
					indiceX++;
				else
					indiceX = 1;
			dx = 0;
			dy = -10;
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
			indiceY =3;
			if (indiceX>= 1 && indiceX < 2)
				indiceX++;
			else
				indiceX = 1;
			dx = -10;
			dy = 0;
			ultima = Direcciones::Izquierda;
			break;
		case Direcciones::Derecha:
			indiceY = 1;
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
		dibujarProta(g, prota);
	}

protected:
	int x;
	int y;
	int dx;//horizontal
	int dy;//vertical
	int ancho;
	int alto;
	int indiceX;//animacion
	int indiceY;//animacion
	int vidas;

	Direcciones direccion;
	Direcciones ultima;//ultima tecla presionada para saber la posicion en la que la deje
};

