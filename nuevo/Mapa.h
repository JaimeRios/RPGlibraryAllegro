//Clase Mapa.h para el proyecto final
// Copyright Jaime Alberto Rios Palacio (J.shuin)
// Electronic engineering student
// version 0.1 23 Diciembre 2012 15:10

#ifndef MAPA_H
#define MAPA_H
#include <allegro.h>
#include <iostream>
using namespace std;

class Mapa{
	private:
	BITMAP *Capas[5];
	SAMPLE *Musica;
	int **Mov;//0 SE PUEDE MOVER //1 NO SE PUEDE MOVER
	bool **Eventos;//0 NO HAY EVENTO //1 HAY EVENTO
	int **TipoEvento;//0,1,2,... TIPO DE EVENTO //0 PASO DE MAPA //1 TEXTO //2 
	int **Especifico;//1,2,3,.... ESPECIFICACION DE LOS EVENTOS	
	int fil,col;
	bool Con_Peleas;//si es mapa es con o sin peleas
	int Numero_Peleas, Contador_Peleas;//Numero de pasos aproximados para pelea y decrementador de los pasos para proxima pelea
	public:
	Mapa(int Filas, int Columnas, const char* filename, BITMAP *Suelo, int px, int py);
	void TocarMusica(void);
	void PararMusica(void);
	void Pintarmapa(BITMAP *Destino);
	void Pintarmapa(BITMAP *Destino, int capa, int x, int y);
	void PintarEnMapa(BITMAP *Origen, int d_x, int d_y, int e_x, int e_y, int t_x, int t_y, int capa);
	void ActualizarMapaMovimiento(int F, int C, int valor=1);
	void ActualizarMapaEventos(int F, int C, bool valor, int TE, int TEE);
	void RadarMov(bool &Arriba, bool &Abajo, bool &Derecha, bool &Izquierda, int y, int x);
	void RadarEventos(bool &Hay, int &Tipo, int &Espe, int y, int x);
	int GetTamX(void);
	int GetTamY(void);
	void mapmov(void);
	void Activa_Modo_Pelea(int Pasos);
	void Desactiva_Modo_Pelea(void);
	void Decrementar(bool &Pelee);//metodo para disminuir las pasos para proxima pelea
	~Mapa();

};

#endif
