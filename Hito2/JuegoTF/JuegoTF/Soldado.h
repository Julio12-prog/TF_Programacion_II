#pragma once
#include"Entidad.h"

enum SpriteJugador {
	Celebrar,

	CaminarArriba,
	CaminarIzquierda,
	CaminarAbajo,
	CaminarDerecha,

	Morir
};


class Soldado : public Entidad { //Creamos la clase Soldado la que el jugador va a controlar
private:
	//Variables en privadas porque no heredan a nadie
	SpriteJugador accion;
	short vida;
	Rectangle CHorizontal;
	Rectangle CVertical;

public:
	//El constructor de Soldado recibe el sprite a mostrar
	Soldado(Bitmap^ img) {
		//Inicializacion de variables
		x = 16;
		y = 2;
		dx = dy = 0;
		ancho = img->Width / 9;
		alto = img->Height / 6;

		accion = CaminarArriba;
		vida = 5;
	}

	


	void Mover(Graphics^ g, Bitmap^ img) {             //Función que permite al jugador desplazarse por el form
		if (x + dx >= 0 && x + dx + ancho < g->VisibleClipBounds.Width)
			x += dx;
		if (y + dy >= 0 && y + dy + alto < g->VisibleClipBounds.Height)
			y += dy;
	}

	void ValidarPaso(bool** matrix) {
		int X1, Y1 = 0;
		for (int i = 0; i < 21; i++) {
			X1 = 0;
			for (int j = 0; j < 21; j++) {
				Rectangle bloque = Rectangle(j*32, i*32, 32, 32);
				if (matrix[i][j] == 0) {
					if (CHorizontal.IntersectsWith(bloque))	x-=dx;
					if (CVertical.IntersectsWith(bloque))	y-=dy;
				}
				//X1 += 50;
			}
			//Y1 += 50;
		}
	}

	void Mostrar(Graphics^ g, Bitmap^ img, bool** matriz) {           // Función que permite que el jugador pueda ser visible en el formulario
		CHorizontal = Rectangle(x + (ancho / 4) + 2 + dx, y + (alto / 2) + 10, 24, 20);//Colision en el eje horizontal
		CVertical = Rectangle(x + (ancho / 4) + 2, y + (alto / 2) + 10 + dy, 24, 20);//Colision en el eje vertical

		ValidarPaso(matriz);

	
		Rectangle corte = Rectangle(IdX * ancho, accion * alto, ancho, alto);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);

		if (dx != 0 || dy != 0) {
			if (accion >= CaminarArriba && accion <= CaminarDerecha)
				IdX = (IdX + 1) % 9;
		}


	}

	void SetAccion(SpriteJugador valor) {
		if (accion != valor)
			IdX = 0;
		accion = valor;
	}
	SpriteJugador GetAccion() {
		return accion;
	}
	short GetVidas() {
		return vida;
	}
	void SetVidas(short valor) {
		this->vida = valor;
	}
	short getX() {
		return x;
	}
	short getY() {
		return y;
	}



};

