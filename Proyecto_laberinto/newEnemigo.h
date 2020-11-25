#pragma once
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System;
class enemigoBeta {

private:
	int x;
	int y;
	int dx;
	int dy;
	int alto;
	int ancho;
	int indiceX;
	int indiceY;
	bool colision;
public:
	enemigoBeta() {
		Random r;
		colision = false;
		int x1 = r.Next(0, 500);
		int y1 = r.Next(0, 400);
		int dx1 = r.Next(1, 4);
		int dy1 = r.Next(1, 4);
		this->x = x1;
		this->y = y1;
		ancho = 74;
		this->dx = dx1;
		this->dy = dy1;
		alto = 130;
		indiceX = 0;
		indiceY = 0;
	}
	~enemigoBeta() {}
	void animar() {
		if (dx < 0)
		{
			indiceY = 1;
			if (indiceX == 5)
				indiceX = 0;
			indiceX++;
		}
		if (dx > 0)
		{
			indiceY = 0;
			if (indiceX == 5)
				indiceX = 0;
			indiceX++;
		}
	}
	void dibujar(Graphics^ g, Bitmap^ bmp) {

		Rectangle porcionUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle aumento = Rectangle(x, y, ancho / 1.5, alto / 1.5);
		g->DrawImage(bmp, aumento, porcionUsar, GraphicsUnit::Pixel);
		mover(g, bmp);
		animar();
	}
	void mover(Graphics^ g, Bitmap^ bmp) {

		int maxX = int(g->VisibleClipBounds.Width);
		int maxY = int(g->VisibleClipBounds.Height);

		if (x + dx <= 0 || x + ancho / 1.5 >= maxX)
			dx *= -1;

		x += dx;


	}

	Rectangle getRectangulo() {
		return Rectangle(x, y, ancho / 4, alto / 4);
	}
	void setColision(bool x) {
		colision = x;
	}
	bool getColision() {
		return colision;
	}
};