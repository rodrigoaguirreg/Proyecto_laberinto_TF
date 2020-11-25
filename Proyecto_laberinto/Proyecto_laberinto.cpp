#include "pch.h"
#include "MyForm.h"
#include <iostream>

using namespace System;
using namespace std;
using namespace Proyectolaberinto;

void main() {
    Application::EnableVisualStyles();
    Application::Run(gcnew MyForm());

}

/*
class Personajes {
protected:
    int x, y, dx, dy;
private:
    Personajes(int x,int y,int dx,int dy) {
        this->x = x;
        this->y = y;
        this->dx = dx;
        this->dy = dy;
    }
protected:
    int set_x() { this->x = x; }
    int set_y() { this->y = y; }
    int get_x() { return this->x; }
    int get_y() { return this->y; }
    void mostrar() {};
    void mover() {};

};

class Protagonista : public Personajes
{

public:
    Protagonista();
    ~Protagonista();



};
//Empieza aliados
class Aliados : public Personajes
{
public:
    Aliados();
    ~Aliados();

private:

};
//Empieza corruptos

class Corruptos : public Personajes
{
public:
    Corruptos();
    ~Corruptos();

private:

};
//Empieza asesinos
class Assesinos : public Personajes
{
public:
    Assesinos();
    ~Assesinos();

private:

};
*/