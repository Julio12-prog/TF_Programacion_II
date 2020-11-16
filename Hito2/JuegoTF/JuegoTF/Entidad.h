#pragma once
#include"Dependencias.h"
class Entidad {
protected:
	short x, y;
	short dx, dy;
	short ancho, alto;
	short IdX;

public:
	Entidad() {
		x = y = 0;
		dx = dy = 0;
		ancho = alto = 0;
		IdX = 0;
	}
	virtual void Mover(Graphics^ g) {
		x += dx;
		y += dy;
	}

	virtual void Mostrar(Graphics^ g, Bitmap^ img) {
		g->FillRectangle(Brushes::Black, Area());
	}

	Rectangle Area() {
		return Rectangle(x, y, ancho, alto);
	}
	Rectangle NextArea() {
		return Rectangle(x + dx, y + dy, ancho, alto);
	}

	Rectangle HitBox()
	{
		float alfa = 0.5; // 0 -> 1
		short ancho = this->ancho * alfa;
		short alto = this->alto * alfa;
		return Rectangle(x + ancho / 2, y + alto / 2, ancho, alto);
	}

	short GetX() {
		return x;
	}
	short GetY() {
		return y;
	}
	short GetDX() {
		return dx;
	}
	short GetDY() {
		return dy;
	}
	short GetIDX() {
		return IdX;
	}
	short GetAncho() {
		return ancho;
	}
	short GetAlto() {
		return alto;
	}

	void SetX(short value) {
		this->x = value;
	}
	void SetY(short value) {
		this->y = value;
	}
	void SetDX(short value) {
		this->dx = value;
	}
	void SetDY(short value) {
		this->dy = value;
	}
	void SetAncho(short value) {
		this->ancho = value;
	}
	void SetAlto(short value) {
		this->alto = value;
	}
	void SetIDX(short value) {
		this->IdX = value;
	}


};