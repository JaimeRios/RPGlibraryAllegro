//Clase Pintor.h para el proyecto final
//Copyright Jaime Alberto Rios Palacio (J.shuin)
//Electronic engineering student
//version 0.1 23 Diciembre 2012 15:10

#ifndef PINTOR_H
#define PINTOR_H
#include <allegro.h>
#include "Mapa.h"

class Pintor{
	private:
	BITMAP *Origen[17];
	BITMAP *Figuras[10];
	public:
	Pintor(void);
	~Pintor(){};
	//todas las cosas que se pintan tiene las posiciones de x,y referenciadas a columnas y filas de una matriz que tiene como base un
	//cuadro de 32x32 pixeles
	void Casa(Mapa &lienzo, int posx, int posy, int E_E);//pinta una casa en el mapa lienzo en la posicion (posx,posy) 
	void Tienda(Mapa &lienzo, int posx, int posy, int tipo);	//pinta una Tienda tipo=0 Armas, tipo=1 Objetos en el mapa lienzo en 										la posicion (posx,posy) 
	void Arbol(Mapa &lienzo, int posx, int posy);//pinta un Arbol en el mapa lienzo en la posicion (posx,posy)
	void Academia(Mapa &lienzo, int posx, int posy);//pinta un Academia en el mapa lienzo en la posicion (posx,posy)
	void Camino(Mapa &lienzo, int posx, int posy, int TamX, int TamY);	//pinta un sendero en el mapa lienzo en la posicion 											(posx,posy), 32*TamX*32*TamY
	void Fuente(Mapa &lienzo, int posx, int posy);//pinta un fuente en el mapa lienzo en la posicion (posx,posy)
	void Lampara(Mapa &lienzo, int posx, int posy);//pinta un Lampara en el mapa lienzo en la posicion (posx,posy)
	void BorInCa(Mapa &lienzo, int posx, int posy, int lonx, int lony, int E_E);//pinta bordes internos de casa en el mapa lienzo en la posicion (posx,posy)
	void MenuCombate(void);
	void MenuCombateObjetos(void);
	void GameOver(void);
	void Pueblo(Mapa &lienzo, int posx, int posy);
	void Montana(Mapa &lienzo, int posx, int posy);
	void Bosque(Mapa &lienzo, int posx, int posy);
	void Bosque(Mapa &lienzo, int posx, int posy, int Tamx, int Tamy);
	void Pueblo_Sin_Entrada(Mapa &lienzo, int posx, int posy, int tipo);
	void Pequena_Construccion(Mapa &lienzo, int posx, int posy, int tipo);
	void Arbol_Exterior(Mapa &lienzo, int posx, int posy, int tipo);
	void Paredes_Rocosas(Mapa &lienzo, int posx, int posy, int cuantos);
	void Escaleras(Mapa &lienzo, int posx, int posy, int cuantos);
	void Furnishing(Mapa &lienzo, int posx, int posy, int Tipo);
};


#endif
