#pragma once


#include"Soldado.h"

enum  SpriteAsesinos
{
	asCaminarArriba,
	asCaminarDerecha,
	asCaminarAbajo,
	asCaminarIzquierda,


};

class Asesino : public Entidad {   //creamos la clase de asesinos que se encargara que quitarnos las vidas.
private:

	Rectangle CDerecha;
	Rectangle CIzquierda;
	SpriteAsesinos accion;
	Rectangle CHorizontal;
	Rectangle CVertical;

public:

	Asesino(Bitmap^ img) {
		x = 500;
		y = 500;
		dx = dy = rand() % 2 + 2;//;
		alto = img->Height / 4;
		ancho = img->Width / 9;
		IdX = 0;
		accion = asCaminarAbajo;
	}


	//Hace que los enemigos sigan al personaje a través del mapa
	void Mover(Soldado* soldado) {
		if (x == soldado->getX()) {
			x += dx;
		}
		else if (x > soldado->getX()) {
			x -= dx;
			accion = asCaminarDerecha;
		}
		else if (x < soldado->getX()) {
			x += dx;
			accion = asCaminarIzquierda;
		}
		if (y == soldado->getY()) {
			y += 0;

		}
		else if (y > soldado->getY()) {
			y -= dy;
			accion = asCaminarArriba;

		}
		else if (y < soldado->getY()) {
			y += dy;
			accion = asCaminarAbajo;

		}
		IdX++;
		if (IdX > 8)IdX = 0;


	}

	void ValidarPaso(bool** matrix) {
		int X1, Y1 = 0;
		for (int i = 0; i < 21; i++) {
			X1 = 0;
			for (int j = 0; j < 21; j++) {
				Rectangle bloque = Rectangle(j * 32, i * 32, 32, 32);
				if (matrix[i][j] == 0) {
					if (CHorizontal.IntersectsWith(bloque))	x -= dx;
					if (CVertical.IntersectsWith(bloque))	y -= dy;
				}
			}
		}
	}

	//Muestra al enemigo en el mapa
	void Mostrar(Graphics^ g, Bitmap^ img, bool** matriz) {
		CHorizontal = Rectangle(x + (ancho / 4) + 2 + dx, y + (alto / 2) + 10, 24, 20);//Colision en el eje horizontal
		CVertical = Rectangle(x + (ancho / 4) + 2, y + (alto / 2) + 10 + dy, 24, 20);//Colision en el eje vertical

		ValidarPaso(matriz);

		Rectangle corte = Rectangle(IdX * ancho, accion * alto, ancho, alto);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
				
	}


};

