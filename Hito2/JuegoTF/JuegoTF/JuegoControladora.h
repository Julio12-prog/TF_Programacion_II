#pragma once
#pragma once
#include"Soldado.h"
#include"Corruptos.h"
#include"Laberinto.h"
#include"Asesinos.h"
#include"Aliados.h"

//Clase referenciada para el Bitmap
ref class JuegoControladora {
private:
	Soldado* soldado;
	Corrupto* corrupto;
	Asesino* asesino;
	Aliados* aliados;

	Bitmap^ imgSoldado;
	Bitmap^ imgCorruptos;
	Bitmap^ imgasesino;
	Bitmap^ imgaliados;
	Laberinto* laberinto;
	
	//PRUEBA
	Bitmap^ imgtierra;
	Bitmap^ imgbloque;

	//PRUEBA

public:
	//Constructor
	JuegoControladora() {
		imgSoldado = gcnew Bitmap("img/soldado.png");
		soldado = new Soldado(imgSoldado);
		imgCorruptos = gcnew Bitmap("img/corrupts.png");
		corrupto = new Corrupto(imgCorruptos);
		imgasesino = gcnew Bitmap("img/assasins.png");
		asesino = new Asesino(imgasesino);
		imgaliados = gcnew Bitmap("img/aliado.png");
		aliados = new Aliados(imgaliados);
		this->laberinto = new Laberinto();

		//prueba
		imgtierra = gcnew Bitmap("img/tierra.png");
		imgbloque = gcnew Bitmap("img/bloque.png");

		//prueba
	}
	//Destructor
	~JuegoControladora() {
		delete soldado;
		delete imgCorruptos;
		delete imgSoldado;
		delete corrupto;
		delete laberinto;
		delete asesino;
		delete imgasesino;
		delete aliados;
		delete imgaliados;
		
	}
	//Movimiento del jugador con sus sprites respectivos
	void MoverJugador(bool accion, Keys key) {
		short v = 5; //velocidad
		if (accion) {
			if (key == Keys::Up) {
				soldado->SetDY(-v);
				soldado->SetAccion(CaminarArriba);
			}

			else if (key == Keys::Down) {
				soldado->SetDY(v);
				soldado->SetAccion(CaminarAbajo);
			}

			else if (key == Keys::Right) {
				soldado->SetDX(v);
				soldado->SetAccion(CaminarDerecha);
			}

			else if (key == Keys::Left) {
				soldado->SetDX(-v);
				soldado->SetAccion(CaminarIzquierda);
			}

		}

		else {
			if (key == Keys::Up)
				soldado->SetDY(0);
			else if (key == Keys::Down)
				soldado->SetDY(0);
			else if (key == Keys::Right)
				soldado->SetDX(0);
			else if (key == Keys::Left)
				soldado->SetDX(0);
		}
	}

	void GenerarLab(){
		laberinto->Generar();		
	}

	void Mover(Graphics^ g) {             // creamos la funcion que llama a las demas funciones de tipo MOVER del resto de clases.
		soldado->Mover(g, imgSoldado);
		corrupto->Mover(soldado);
		asesino->Mover(soldado);
		aliados->Mover(soldado);
	}
	void Mostrar(Graphics^ g) {            // creamos la funcion que llama a las demas funciones de tipo MOSTRAR del resto de clases.
		laberinto->Graficar(g,imgbloque,imgtierra);
		soldado->Mostrar(g, imgSoldado, laberinto->getMatriz());
		corrupto->Mostrar(g, imgCorruptos, laberinto->getMatriz());
		asesino->Mostrar(g, imgasesino, laberinto->getMatriz());
		aliados->Mostrar(g, imgaliados, laberinto->getMatriz());
	}

};

