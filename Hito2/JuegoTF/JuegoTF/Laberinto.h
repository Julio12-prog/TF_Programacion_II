#pragma once 
#include"Dependencias.h"

enum estadoCelda { Close, Open };

class Celda
{
public:
    int x;
    int y;
    estadoCelda Izquierda;
    estadoCelda Derecha;
    estadoCelda Arriba;
    estadoCelda Abajo;
    bool Visitado;
};


class Laberinto{
private:

    bool** Matriz;

public:

Laberinto(){
    Matriz = new bool* [21];
}

~Laberinto(){

}



void Generar() {

    const int ancho = 10;
    const int alto = 10;

    Celda laberinto[ancho][alto];

    for (int y = 0; y < alto; y++) {


        for (int x = 0; x < ancho; x++)
        {
            laberinto[x][y].x = x;
            laberinto[x][y].y = y;
            laberinto[x][y].Visitado = false;
        }
    }
    
    int comienzoX = rand() % ancho;
    int comienzoY = rand() % alto;

    laberinto[comienzoX][comienzoY].Visitado = true;

    stack<Celda> camino;
    camino.push(laberinto[comienzoX][comienzoY]);

    while (!camino.empty())
    {
        Celda _celda = camino.top();

        vector<Celda> sgtePaso;
        if (_celda.x > 0 && (laberinto[_celda.x - 1][_celda.y].Visitado == false))
            sgtePaso.push_back(laberinto[_celda.x - 1][_celda.y]);
        if (_celda.x < ancho - 1 && (laberinto[_celda.x + 1][_celda.y].Visitado == false))
            sgtePaso.push_back(laberinto[_celda.x + 1][_celda.y]);
        if (_celda.y > 0 && (laberinto[_celda.x][_celda.y - 1].Visitado == false))
            sgtePaso.push_back(laberinto[_celda.x][_celda.y - 1]);
        if (_celda.y < alto - 1 && (laberinto[_celda.x][_celda.y + 1].Visitado == false))
            sgtePaso.push_back(laberinto[_celda.x][_celda.y + 1]);

        if (!sgtePaso.empty())
        {
            Celda sgte = sgtePaso[rand() % sgtePaso.size()];

            if (sgte.x != _celda.x)
            {
                if (_celda.x - sgte.x > 0)
                {
                    laberinto[_celda.x][_celda.y].Izquierda = (estadoCelda)Open;
                    laberinto[sgte.x][sgte.y].Derecha = (estadoCelda)Open;
                }
                else
                {
                    laberinto[_celda.x][_celda.y].Derecha = (estadoCelda)Open;
                    laberinto[sgte.x][sgte.y].Izquierda = (estadoCelda)Open;
                }
            }
            if (sgte.y != _celda.y)
            {
                if (_celda.y - sgte.y > 0)
                {
                    laberinto[_celda.x][_celda.y].Arriba = (estadoCelda)Open;
                    laberinto[sgte.x][sgte.y].Abajo = (estadoCelda)Open;
                }
                else
                {
                    laberinto[_celda.x][_celda.y].Abajo = (estadoCelda)Open;
                    laberinto[sgte.x][sgte.y].Arriba = (estadoCelda)Open;
                }
            }

            laberinto[sgte.x][sgte.y].Visitado = true;
            camino.push(sgte);

        }
        else
        {
            camino.pop();
        }
    }

    int ancho2 = 21,
        alto2 = 21;

    for (int i = 0; i < alto2; i++) {
        Matriz[i] = new bool[ancho2];
    }

    for (int a = 0; a < alto2; a++) {
        for (int b = 0; b < ancho2; b++) {
            this->Matriz[b][a] = 1;               //casillas vacias ,,,, camino
            if (b % 2 != 0 && a % 2 != 0) {
                this->Matriz[b][a] = 1;
            }
            if (b % 2 == 0 && a % 2 == 0) {
                this->Matriz[b][a] = 0;           //paredes 0
            }
        }
    }



    for (int i = 0; i < alto; i++)
    {
        for (int j = 0; j < ancho; j++)
        {
            if (laberinto[j][i].Arriba != (estadoCelda)Open) {                //dibuja una linea arriba
                this->Matriz[(j * 2) + 1][(i * 2)] = 0;

            }


            if (laberinto[j][i].Izquierda != (estadoCelda)Open) {          //dibuja una linea izquierda
                this->Matriz[(j * 2)][(i * 2) + 1] = 0;
            }


            if (laberinto[j][i].Derecha != (estadoCelda)Open) {               //dibuja una linea derecha
                this->Matriz[(j * 2) + 2][(i * 2) + 1] = 0;
            }

            if (laberinto[j][i].Abajo != (estadoCelda)Open) {                //dibuja una linea abajo
                this->Matriz[(j * 2) + 1][(i * 2) + 2] = 0;
            }
        }
    }

}

void Graficar(Graphics^ g, Bitmap^ bmpbloque,Bitmap^ bmptierra) {  //Sin parametros
    

    for (short i = 0; i < 21; i++) {


        for (short j = 0; j < 21; j++)
        {

            /*Brush^ brush;*/

            if (this->Matriz[i][j] == 0) { ;

                /*bmp = gcnew Bitmap("img/bloque.png");*/
            g->DrawImage(bmpbloque, j * 32, i * 32, 32, 32);
               /* brush = Brushes::Black;*/
            }
            else {
                /*brush = Brushes::White;*/

                g->DrawImage(bmptierra, j * 32, i * 32, 32, 32);
               /* bmp = gcnew Bitmap("img/tierra.png");*/
            }
            /*g->DrawImage(bmp, j * 32, i * 32, 32, 32);*/

        }
    }
}

bool** getMatriz() {
    return Matriz;
}

    

};