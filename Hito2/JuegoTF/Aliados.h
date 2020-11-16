#pragma once
#pragma once

#include"Soldado.h"

enum  SpriteAliados
{
	alCaminarArriba,
	alCaminarDerecha,
	alCaminarAbajo,
	alCaminarIzquierda,


};

class Aliados : public Entidad {     //creamos la clase de aliados que nos ayudara en el laberinto.
private:                      
                                      //ponemos private para restringis ciertas funciones.

	Rectangle CDerecha;
	Rectangle CIzquierda;
	SpriteAliados accion;
	Rectangle CHorizontal;
	Rectangle CVertical;
public:
                                    // Definimos las propiedades las cuales tendra al momennto de manifestarse en el mapa.
	Aliados(Bitmap^ img) {
		x = 16;
		y = 200;
		dx = dy = 1;
		alto = img->Height / 4;
		ancho = img->Width / 9;
		IdX = 0;
		accion = alCaminarAbajo;
	}


	//Hace que los enemigos sigan al personaje a través del mapa.
	void Mover(Soldado* soldado) {
		if (x == soldado->getX()) {
			x += dx;
		}
		else if (x > soldado->getX()) {
			x -= dx;
			accion = alCaminarDerecha;
		}
		else if (x < soldado->getX()) {
			x += dx;
			accion = alCaminarIzquierda;
		}
		if (y == soldado->getY()) {
			y += 0;

		}
		else if (y > soldado->getY()) {
			y -= dy;
			accion = alCaminarArriba;

		}
		else if (y < soldado->getY()) {
			y += dy;
			accion = alCaminarAbajo;

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

