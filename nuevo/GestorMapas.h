//Clase GestorMapas.h para el proyecto final
// Copyright Jaime Alberto Rios Palacio (J.shuin)
// Electronic engineering student
// version 0.1 18 Noviembre 2012 16:41

#ifndef GESTORMAPAS_H
#define GESTORMAPAS_H
#include <allegro.h>
#include "Mapa.h"

class GestorMapas{
	private:
	Mapa *MapaApun;
	BITMAP *Personaje;
	BITMAP *BufferFinal;
	int sourceX;
	int sourceY;
	bool movab, movar, movder, moviz, pvarriba, pvabajo, pvderecha, pvizquierda;
	int ColumnaActual;
	int FilaActual;
	int speed;
	int x,y,xv,yv,Px,Py;
	 
	public:
	GestorMapas(Mapa *ApunMap);	
	void CambioMapa(Mapa *Mapa_Apuntador, bool ON);
	void Moverse(bool &PELEE);
	void Posicion(void);
	void Evento(bool &Hay, int &Tipo, int &Especifico);
	void ActualizarMov(int Col, int Fil);
	void Parar_Musica(void);
	void Reproducir_Musica(void);
	~GestorMapas(){};
};

#endif
