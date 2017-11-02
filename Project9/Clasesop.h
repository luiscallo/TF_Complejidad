#pragma once
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <string>
#include <list>

#define ALTO 32
#define ANCHO 32

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
enum Direcciones { ninguna, Arriba, Abajo, Derecha, Izquierda };

/*class CMusica
{
private:
public:
CMusica();
~CMusica();
int Reproducir();
};

CMusica::CMusica() {}
CMusica::~CMusica() {}
int CMusica::Reproducir()
{
PlaySound(TEXT("BomberBoi.wav"), NULL, SND_ASYNC);
return 0;
}*/

struct posicion {
	int x;
	int y;
public:
	posicion() :x(x), y(y) {};
};

class Bomba {
	int tiempo;
	int temp;
	int Rango;
	posicion pos;
	int tem;
public:
	Bomba();
	~Bomba();
	void aumentarRango();
	void aumentarTiempo();
	void explotar(BufferedGraphics ^buffer, Bitmap^ img, int x, int y, int** map);
};

Bomba::Bomba() {
	this->tiempo = 20;
	this->temp = this->tiempo;
	this->Rango = 2;
	this->pos.x = NULL;
	this->pos.y = NULL;
	this->tem = 10;
}
Bomba::~Bomba() {}
void Bomba::aumentarRango() {
	Rango += 2;
}
void Bomba::aumentarTiempo() {
	tiempo += 2;
	temp += 2;
}
void Bomba::explotar(BufferedGraphics ^buffer, Bitmap^ img, int x, int y, int** map) {
	pos.x = x;

	pos.y = y;
	if (tiempo != 0) {
		System::Drawing::Rectangle porcion = System::Drawing::Rectangle(119, 100, 20, 20);
		System::Drawing::Rectangle aumento = System::Drawing::Rectangle(pos.x, pos.y, ANCHO, ALTO);
		buffer->Graphics->DrawImage(img, aumento, porcion, System::Drawing::GraphicsUnit::Pixel);
		tiempo--;
	}
	else if (tiempo == 0) {
		if (tem != 0) {
			System::Drawing::Rectangle porcion2 = System::Drawing::Rectangle(139, 101, 20, 20);
			System::Drawing::Rectangle aumento = System::Drawing::Rectangle(pos.x, pos.y, ANCHO, ALTO);
			buffer->Graphics->DrawImage(img, aumento, porcion2, System::Drawing::GraphicsUnit::Pixel);

			if (map[pos.y / 32][(pos.x / 32) + 1] != 5) {
				if (map[pos.y / 32][(pos.x / 32) + 1] == 1) {
					map[pos.y / 32][(pos.x / 32) + 1] = 5;
				}
			}
			else {
				map[pos.y / 32][(pos.x / 32) + 1] = 8;
				System::Drawing::Rectangle porcion2 = System::Drawing::Rectangle(139, 101, 20, 20);
				System::Drawing::Rectangle aumento = System::Drawing::Rectangle(pos.x + 32, pos.y, ANCHO, ALTO);
				buffer->Graphics->DrawImage(img, aumento, porcion2, System::Drawing::GraphicsUnit::Pixel);
			}
			if (map[pos.y / 32][(pos.x / 32) - 1] != 5) {
				if (map[pos.y / 32][(pos.x / 32) - 1] == 1) {
					map[pos.y / 32][(pos.x / 32) - 1] = 5;
				}
			}
			else {
				map[pos.y / 32][(pos.x / 32) - 1] = 8;
				System::Drawing::Rectangle porcion2 = System::Drawing::Rectangle(139, 101, 20, 20);
				System::Drawing::Rectangle aumento = System::Drawing::Rectangle(pos.x - 32, pos.y, ANCHO, ALTO);
				buffer->Graphics->DrawImage(img, aumento, porcion2, System::Drawing::GraphicsUnit::Pixel);
			}
			if (map[(pos.y / 32) - 1][(pos.x / 32)] != 5) {
				if (map[(pos.y / 32) - 1][(pos.x / 32)] == 1) {
					map[(pos.y / 32) - 1][(pos.x / 32)] = 5;
				}
			}
			else {
				map[(pos.y / 32) - 1][(pos.x / 32)] = 8;
				System::Drawing::Rectangle porcion2 = System::Drawing::Rectangle(139, 101, 20, 20);
				System::Drawing::Rectangle aumento = System::Drawing::Rectangle(pos.x, pos.y - 32, ANCHO, ALTO);
				buffer->Graphics->DrawImage(img, aumento, porcion2, System::Drawing::GraphicsUnit::Pixel);
			}
			if (map[(pos.y / 32) + 1][(pos.x / 32)] != 5) {
				if (map[(pos.y / 32) + 1][(pos.x / 32)] == 1) {
					map[(pos.y / 32) + 1][(pos.x / 32)] = 5;
				}
			}
			else {
				map[(pos.y / 32) + 1][(pos.x / 32)] = 8;
				System::Drawing::Rectangle porcion2 = System::Drawing::Rectangle(139, 101, 20, 20);
				System::Drawing::Rectangle aumento = System::Drawing::Rectangle(pos.x, pos.y + 32, ANCHO, ALTO);
				buffer->Graphics->DrawImage(img, aumento, porcion2, System::Drawing::GraphicsUnit::Pixel);
			}
			tem--;

		}
		else {
			tem = 10;
			tiempo = 20;
			map[pos.y / 32][pos.x / 32] = 5;
			if (map[(pos.y / 32) + 1][(pos.x / 32)] != 0) { map[(pos.y / 32) + 1][(pos.x / 32)] = 5; }
			if (map[(pos.y / 32) - 1][(pos.x / 32)] != 0) { map[(pos.y / 32) - 1][(pos.x / 32)] = 5; }
			if (map[(pos.y / 32)][(pos.x / 32) - 1] != 0) { map[(pos.y / 32)][(pos.x / 32) - 1] = 5; }
			if (map[(pos.y / 32)][(pos.x / 32) + 1] != 0) { map[(pos.y / 32)][(pos.x / 32) + 1] = 5; }
		}
	}

}

class Jugador {
	Bomba* Bomb;
	posicion pos;
	int puntaje;
	int vidas;
	int cantMaxBomb;
	int cantBomb;
	bool activado;
	Direcciones Direc;
	bool quieto;
	int Indice;
	int dx;
	int dy;
	Direcciones ultima;
	int Indx;
	int Indy;
public:
	Jugador();
	Jugador(int x, int y, bool act);
	~Jugador();
	void Mover(BufferedGraphics ^buffer, Bitmap^ jug, int** map, list<int**>* li);
	void NuevaBomba(int **map);
	void ColocarBomb(BufferedGraphics ^buffer, Bitmap^ img, int x, int y, int** map);
	void SetDirec(Direcciones Dir);
	void moverse(bool mov);
	posicion GetPos();
	bool colision(int pX, int pY, Bitmap^ img);
	System::Drawing::Rectangle returnrec();
	int get_dx();
	int get_dy();
	int get_vidas();
	void set_dx(int dx);
	void set_dy(int dy);
	void SetPos(int x, int y);
};
Jugador::Jugador() {}
Jugador::Jugador(int x, int y, bool act) {
	this->cantBomb = 1;
	this->pos.x = x;
	this->pos.y = y;
	this->vidas = 3;
	this->activado = act;
	this->quieto = true;
	this->Indice = 0;
	this->Bomb = new Bomba();
	this->Direc = ninguna;
	this->Indx = 4;
	this->Indy = 0;
	this->dx = 0;
	this->dy = 0;
}
Jugador::~Jugador() {}
void Jugador::Mover(BufferedGraphics ^buffer, Bitmap^ jug, int** map, list<int**>* li) {
	int x = pos.x, y = pos.y;
	int monedasfalt = 0;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (map[i][j] == 2) monedasfalt += 1;
		}
	}
	if (monedasfalt == 0) {
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				if (map[i][j] == 6) map[i][j] = 5;
			}
		}
	}
	/*if(map[(pos.y)/32][(pos.x)/32]==8){
	vidas -= 1;
	pos.x = 33;
	pos.y = 33;
	}*/
	switch (Direc)
	{
	case Direcciones::Arriba:
	{

		Indy = 0;

		if (Indx >= 6 && Indx <8) {
			Indx++;
		}
		else { Indx = 6; }/*(map->front()[pos.x][(pos.y + dy) / 32] != 5)*/
		dy = -6;
		dx = 0;
		//esta es una opcion
		if (map[(pos.y) / 32][(pos.x + 16) / 32] == 0 || map[(pos.y) / 32][(pos.x + 16) / 32] == 1 || map[(pos.y) / 32][(pos.x + 16) / 32] == 6)
			this->dy = 0;
		if (map[(pos.y + 32) / 32][pos.x / 32] == 2) {
			map[(pos.y + 32) / 32][pos.x / 32] = 5;
		}
		if (map[(pos.y + 32) / 32][pos.x / 32] == 3) {
			cantBomb += 1;
			cantMaxBomb += 1;
			map[(pos.y + 32) / 32][pos.x / 32] = 5;
		}
		if (map[(pos.y + 32) / 32][pos.x / 32] == 4) {
			pos.x = 33;
			pos.y = 33;
			if (!li->empty())
				li->pop_front();
		}
		if (map[(pos.y + 32) / 32][pos.x / 32] == 8) {
			vidas -= 1;
			pos.x = 33;
			pos.y = 33;

		}
		ultima = Arriba;
		break;
	}
	case Direcciones::Abajo:
	{

		Indy = 0;

		if (Indx >= 3 && Indx <5) {
			Indx++;
		}
		else { Indx = 3; }
		dy = 6;
		dx = 0;
		//esta es otra
		if (map[(pos.y + 32) / 32][(pos.x + 16) / 32] == 0 || map[(pos.y + 32) / 32][(pos.x + 16) / 32] == 1 || map[(pos.y + 32) / 32][(pos.x + 16) / 32] == 6)
			dy = 0;
		if (map[(pos.y + 32) / 32][pos.x / 32] == 2) {
			map[(pos.y + 32) / 32][pos.x / 32] = 5;
		}
		if (map[(pos.y + 32) / 32][pos.x / 32] == 3) {
			cantBomb += 1;
			cantMaxBomb += 1;
			map[(pos.y + 32) / 32][pos.x / 32] = 5;
		}
		if (map[(pos.y + 32) / 32][pos.x / 32] == 4) {
			pos.x = 33;
			pos.y = 33;
			if (!li->empty())
				li->pop_front();
		}
		if (map[(pos.y + 32) / 32][pos.x / 32] == 8) {
			vidas -= 1;
			pos.x = 33;
			pos.y = 33;
		}
		ultima = Abajo;
		break;
	}
	case Direcciones::Derecha:
	{

		Indy = 0;

		if (Indx >= 9 && Indx <= 10) {
			Indx++;
		}
		else { Indx = 9; }
		dy = 0;
		dx = 6;
		if (map[(pos.y + 16) / 32][(pos.x + 32) / 32] == 0 || map[(pos.y + 16) / 32][(pos.x + 32) / 32] == 1 || map[(pos.y + 16) / 32][(pos.x + 32) / 32] == 6)
			dx = 0;
		if (map[(pos.y) / 32][(pos.x + 32) / 32] == 2) {
			map[(pos.y) / 32][(pos.x + 32) / 32] = 5;
		}
		if (map[(pos.y) / 32][(pos.x + 32) / 32] == 3) {
			cantBomb += 1;
			cantMaxBomb += 1;
			map[(pos.y) / 32][(pos.x + 32) / 32] = 5;
		}
		if (map[(pos.y) / 32][(pos.x + 32) / 32] == 4) {
			pos.x = 33;
			pos.y = 33;
			if (!li->empty())
				li->pop_front();
		}
		if (map[(pos.y) / 32][(pos.x + 32) / 32] == 8) {
			vidas -= 1;
			pos.x = 33;
			pos.y = 33;
		}
		ultima = Derecha;
		break;

	}
	case Direcciones::Izquierda:
	{
		Indy = 0;

		if (Indx >= 0 && Indx < 2) {
			Indx++;
		}
		else { Indx = 0; }
		dy = 0;
		dx = -6;
		if (map[(pos.y + 16) / 32][(pos.x) / 32] == 0 || map[(pos.y + 16) / 32][(pos.x) / 32] == 1 || map[(pos.y + 16) / 32][(pos.x) / 32] == 6)
			dx = 0;
		if (map[(pos.y) / 32][(pos.x) / 32] == 2)
			map[(pos.y) / 32][(pos.x) / 32] = 5;
		if (map[(pos.y) / 32][(pos.x) / 32] == 3) {
			cantBomb += 1;
			cantMaxBomb += 1;
			map[(pos.y) / 32][(pos.x) / 32] = 5;
		}
		if (map[(pos.y) / 32][(pos.x) / 32] == 4) {
			pos.x = 33;
			pos.y = 33;
			if (!li->empty())
				li->pop_front();
		}
		if (map[(pos.y) / 32][(pos.x) / 32] == 8) {
			vidas -= 1;
			pos.x = 33;
			pos.y = 33;
		}

		ultima = Izquierda;
		break;
	}
	case Direcciones::ninguna: {

		dx = 0; dy = 0;
		switch (ultima)
		{
		case Arriba:
			Indx = 7;
			Indy = 0;
			break;
		case Abajo:
			Indx = 4;
			Indy = 0;
			break;
		case Derecha:
			Indx = 10;
			Indy = 0;
			break;
		case Izquierda:
			Indx = 1;
			Indy = 0;
			break;
		default:
			break;
		}
		break;
	}
	}

	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(Indx * 20, Indy * 28, 20, 28);
	System::Drawing::Rectangle aumento = System::Drawing::Rectangle(pos.x, pos.y, ANCHO - 2, ALTO - 2);
	buffer->Graphics->DrawImage(jug, aumento, porcion, System::Drawing::GraphicsUnit::Pixel);
	pos.x += dx; pos.y += dy;
}
void Jugador::SetPos(int x, int y) {
	pos.x = x;
	pos.y = y;
}
void Jugador::NuevaBomba(int **map) {
	map[(pos.y + 15) / 32][(pos.x + 15) / 32] = 7;
}
void Jugador::ColocarBomb(BufferedGraphics ^buffer, Bitmap^ img, int x, int y, int** map) {

	if (cantBomb != 0) {

		Bomb->explotar(buffer, img, x, y, map);
	}
}
void Jugador::SetDirec(Direcciones Dir) {
	this->Direc = Dir;
}
void Jugador::moverse(bool mov) {
	this->quieto = mov;
}

posicion Jugador::GetPos() {
	return this->pos;
}
bool Jugador::colision(int pX, int pY, Bitmap^ img) {

	return (pX >= pos.x + 32 || pX <= pos.x) &&
		(pY >= pos.y || pY <= pos.y + img->Height);

}
System::Drawing::Rectangle Jugador::returnrec() {
	System::Drawing::Rectangle rec;
	rec = System::Drawing::Rectangle(pos.x, pos.y, ANCHO - 2, ALTO - 2);
	return rec;
}
int Jugador::get_dx() { return dx; }
int Jugador::get_dy() { return dy; }
int Jugador::get_vidas() { return vidas; }
void Jugador::set_dx(int dx) { this->dx = dx; }
void Jugador::set_dy(int dy) { this->dy = dy; }
class Moneda {
	posicion pos;
public:
	Moneda();
	Moneda(int x, int y);
	~Moneda();
	void dibujar(BufferedGraphics ^buffer, Bitmap^ moneda);
};
Moneda::Moneda() {}
Moneda::Moneda(int x, int y) {
	this->pos.x = x;
	this->pos.y = y;
}
Moneda::~Moneda() {}
void Moneda::dibujar(BufferedGraphics ^buffer, Bitmap^ moneda) {
	System::Drawing::Rectangle porcion8 = System::Drawing::Rectangle(0, 0, 32, 32);
	System::Drawing::Rectangle aumento = System::Drawing::Rectangle(pos.x, pos.y, 32, 32);
	buffer->Graphics->DrawImage(moneda, aumento, porcion8, System::Drawing::GraphicsUnit::Pixel);
}

class Pared {
	bool destruible;
	posicion pos;
public:
	Pared();
	Pared(int x, int y);
	void dibujar(BufferedGraphics ^buffer, Bitmap^ img, bool destruye);
	~Pared();

};
Pared::Pared() {
}
Pared::Pared(int x, int y) {
	this->pos.x = x;
	this->pos.y = y;
}
void Pared::dibujar(BufferedGraphics ^buffer, Bitmap^ img, bool destruye) {
	System::Drawing::Rectangle porcion9 = System::Drawing::Rectangle(0, 0, 32, 32);
	System::Drawing::Rectangle aumento = System::Drawing::Rectangle(pos.x, pos.y, 32, 32);
	buffer->Graphics->DrawImage(img, aumento, porcion9, System::Drawing::GraphicsUnit::Pixel);
}
Pared::~Pared() {}
class Salida {
	posicion pos;
	bool abierto;
public:
	Salida();
	Salida(int x, int y);
	~Salida();
	void dibujar(BufferedGraphics ^buffer, Bitmap^ img);
	void pasarNivel(int x, int y, int nivel);
};
Salida::Salida() {}
Salida::Salida(int x, int y) {
	pos.x = x;
	pos.y = y;
}
Salida::~Salida() {}
void Salida::dibujar(BufferedGraphics ^buffer, Bitmap^ img) {
	System::Drawing::Rectangle porcion10 = System::Drawing::Rectangle(0, 0, 32, 32);
	System::Drawing::Rectangle aumento = System::Drawing::Rectangle(pos.x, pos.y, 32, 32);
	buffer->Graphics->DrawImage(img, aumento, porcion10, System::Drawing::GraphicsUnit::Pixel);
}
void Salida::pasarNivel(int x, int y, int nivel) {
	if (abierto && pos.x == x && pos.y == y) {
		nivel++;
	}
}

class Powerup {
	int tipo;
	posicion pos;
public:
	Powerup();
	Powerup(int x, int y);
	~Powerup();
	void dibujar(BufferedGraphics ^buffer, Bitmap^ img);
};
Powerup::Powerup() {}
Powerup::Powerup(int x, int y) {
	this->pos.x = x;
	this->pos.y = y;
}
Powerup::~Powerup() {}
void Powerup::dibujar(BufferedGraphics ^buffer, Bitmap^ img) {
	System::Drawing::Rectangle porcion11 = System::Drawing::Rectangle(0, 0, 32, 32);
	System::Drawing::Rectangle aumento = System::Drawing::Rectangle(pos.x, pos.y, 32, 32);
	buffer->Graphics->DrawImage(img, aumento, porcion11, System::Drawing::GraphicsUnit::Pixel);
}



class Mapa {
private:
	int nivel;
	Pared* Pared1;
	Pared* Pared2;
	Moneda* Mon;
	Powerup* Pup;
	Salida* salida;
	Jugador* P1;
	Jugador* P2;
	bool esColi;
	list<int**>* mapas;
	//int mapa[15][15];
public:
	Mapa(int i);
	~Mapa();
	Jugador* Getjug(int i);
	int** map();
	bool Mapa::colicion(int pX, int pY, Bitmap^ img);
	void Dibujar(BufferedGraphics ^buffer, Bitmap^P1, Bitmap^muro, Bitmap^Pared, Bitmap^monedas, Bitmap^PU, Bitmap^alida, int nivel, bool dosP, Bitmap^Fondo);
	bool get_coli();
	void set_coli(bool coli);
	void sigmapa();
};
Mapa::Mapa(int i) {

	this->mapas = new list<int**>();
	ifstream iu;
	if (i == 1) {
	 iu.open("Mapas.csv");
	}
	else
	 iu.open("Mapas2V2.csv");
	string aux;

	for (int i = 0; i < 10; i++) {
		int** mapa = new int*[15];
		for (int j = 0; j < 15; j++) {
			mapa[j] = new int[15];
		}
		for (int j = 0; j < 15; j++) {
			for (int k = 0; k < 15; k++) {
				getline(iu, aux, ',');
				mapa[j][k] = atoi(aux.c_str());
			}
		}
		mapas->push_front(mapa);
	}
	P1 = new Jugador(32, 32, true);
	if (i == 1)
		P2 = nullptr;
	if (i != 1)
		P2 = new Jugador(416, 416, true);
	this->esColi = false;
}
Mapa::~Mapa() {}
Jugador* Mapa::Getjug(int i) {
	if (i == 1)
		return P1;
	else
		return P2;
}
int** Mapa::map() {
	return mapas->front();
}
void Mapa::sigmapa() {
	if (mapas->size() > 1) { mapas->pop_front(); }
	else { return; }
}
void Mapa::Dibujar(BufferedGraphics ^buffer, Bitmap^Player, Bitmap^muro, Bitmap^pared, Bitmap^monedas, Bitmap^PU, Bitmap^alida, int nivel, bool dosP, Bitmap^Fondo) {
	System::Drawing::Rectangle porcion12 = System::Drawing::Rectangle(0, 0, 32 * 15 - 1, 32 * 15 - 1);
	System::Drawing::Rectangle aumento9 = System::Drawing::Rectangle(0, 0, 32 * 15, 32 * 15);
	buffer->Graphics->DrawImage(Fondo, aumento9, porcion12, System::Drawing::GraphicsUnit::Pixel);
	int X = 0, Y = 0;
	System::Drawing::Rectangle aumento;
	System::Drawing::Rectangle p1;
	System::Drawing::Rectangle p2;
	for (int i = 0; i < 15; i++)
	{
		X = 0;
		for (int j = 0; j < 15; j++)
		{

			switch (mapas->front()[i][j]) {
			case 0:
				Pared1 = new Pared(X, Y);
				Pared1->dibujar(buffer, muro, false);
				p1 = System::Drawing::Rectangle(X, Y, 32, 32);

				break;
			case 1:
				Pared2 = new Pared(X, Y);
				Pared2->dibujar(buffer, pared, true);
				aumento = System::Drawing::Rectangle(X, Y, 32, 32);
				break;
			case 2:
				Mon = new Moneda(X, Y);
				Mon->dibujar(buffer, monedas);
				aumento = System::Drawing::Rectangle(X, Y, 32, 32);
				break;
			case 3:
				Pup = new Powerup(X, Y);
				Pup->dibujar(buffer, PU);
				aumento = System::Drawing::Rectangle(X, Y, 32, 32);
				break;
			case 4:
				salida = new Salida(X, Y);
				salida->dibujar(buffer, alida);
				aumento = System::Drawing::Rectangle(X, Y, 32, 32);
				break;
			case 5:
				//buffer->Graphics->DrawRectangle(Pens::Yellow, X, Y, 32, 32);
				break;
			case 6:
				Pared1 = new Pared(X, Y);
				Pared1->dibujar(buffer, muro, false);
				aumento = System::Drawing::Rectangle(X, Y, 32, 32);
				break;
			case 7:
				P1->ColocarBomb(buffer, Player, X, Y, mapas->front());
				break;
			case 8:
				System::Drawing::Rectangle porcion2 = System::Drawing::Rectangle(139, 101, 20, 20);
				System::Drawing::Rectangle aumento = System::Drawing::Rectangle(X, Y, ANCHO, ALTO);
				buffer->Graphics->DrawImage(Player, aumento, porcion2, System::Drawing::GraphicsUnit::Pixel);
				break;
			}
			/*if (aumento.IntersectsWith(P1->returnrec())) {
			P1->moverse(true);
			}*/

			X += 32;
		}
		Y += 32;
	}


	P1->Mover(buffer, Player, mapas->front(), mapas);
	if (P2 != nullptr)
		P2->Mover(buffer, Player, mapas->front(), mapas);
}
bool Mapa::colicion(int pX, int pY, Bitmap^ img) {

	return (pX >= P1->GetPos().x + 32 || pX <= P1->GetPos().x) &&
		(pY >= P1->GetPos().y || pY <= P1->GetPos().y + img->Height);
}
bool Mapa::get_coli() { return esColi; }
void Mapa::set_coli(bool coli) { esColi = coli; }

/*class Controladora {
Mapa map;
public:
Controladora();
void Iniciar();
void Iniciar2v2();
void terminar();
};*/

