//Clase Eventos.h para el proyecto final
//Copyright Jaime Alberto Rios Palacio (J.shuin)
//Electronic engineering student
//version 0.1 12 Febrero 2013 23:59

#ifndef EVENTOS_H
#define EVENTOS_H
#include <allegro.h>
#include "Definiciones.h"
#include "Mapa.h"
#include "Pintor.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>



class Eventos{//los tipos de eventos que se presentan son 1; void ActualizarMapaEventos(int F, int C, bool valor, int TE=1, int TEE);
	private:
	BITMAP *Personajes[4];
	BITMAP *NPC[5];
	FONT *Font1;
	int fd;
	Pintor Mi_Pintor_Eventos;
	char buf[50];
	public:
	Eventos(int NumeroPersonajes,const char *texto1=NULL, const char *texto2=NULL, const char *texto3=NULL,const char *texto4=NULL );
	~Eventos(){};
	void Crear_NPC(Mapa &lienzo, int posx, int posy, int TEE_E,int npc, int Posicion_Personaje);
	void Crear_Cambio_Mapa(Mapa &lienzo, int posx, int posy, int TEE_E);
	void Crear_Evento(Mapa &lienzo, int posx, int posy, int TEE_E);
	void Historia(BITMAP *Fondo, const char *texto);
	void conversacion(int _Personaje, const char *texto, int Posicion);
	void trigger(void);
};

#endif
