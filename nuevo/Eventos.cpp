//Clase Eventos.h para el proyecto final
//Copyright Jaime Alberto Rios Palacio (J.shuin)
//Electronic engineering student
//version 0.1 12 Febrero 2013 23:59

#include <allegro.h>
#include "Eventos.h"
#include "Definiciones.h"
#include "Mapa.h"
#include "Pintor.h"

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


//los tipos de eventos que se presentan son 1; void ActualizarMapaEventos(int F, int C, bool valor, int TE=1, int TEE);

Eventos::Eventos(int NumeroPersonajes,const char *texto1, const char *texto2, const char *texto3,const char *texto4){
	Font1=load_font("Nuevo.pcx", NULL,NULL);
	NPC[0]=load_bitmap("../npcs/Aldeana.tga", NULL);
	for(int i=0;i<NumeroPersonajes;i++){
		if(i==0)
			Personajes[0] = load_bitmap(texto1, NULL);
		else if(i==1)
			Personajes[1] = load_bitmap(texto2, NULL);
		else if(i==2)
			Personajes[2] = load_bitmap(texto3, NULL);
		else if(i==3)
			Personajes[3] = load_bitmap(texto4, NULL);
	}

};

void Eventos::Crear_NPC(Mapa &lienzo, int posx, int posy, int TEE_E,int npc, int Posicion_Personaje){
	if(Posicion_Personaje==0){
		lienzo.PintarEnMapa(NPC[npc], Lado, 0, posx*Lado, posy*Lado, Lado, Lado, 1);
		lienzo.ActualizarMapaEventos(posx, posy+1, true, 1, TEE_E);
	}
	else if(Posicion_Personaje==1){
		lienzo.PintarEnMapa(NPC[npc], Lado, Lado, posx*Lado, posy*Lado, Lado, Lado, 1);
		lienzo.ActualizarMapaEventos(posx-1, posy, true, 1, TEE_E);
	}
	else if(Posicion_Personaje==2){
		lienzo.PintarEnMapa(NPC[npc], Lado, 2*Lado, posx*Lado, posy*Lado, Lado, Lado, 1);
		lienzo.ActualizarMapaEventos(posx+1, posy, true, 1, TEE_E);
	}
	else if(Posicion_Personaje==3){
		lienzo.PintarEnMapa(NPC[npc], Lado, 3*Lado, posx*Lado, posy*Lado, Lado, Lado, 1);
		lienzo.ActualizarMapaEventos(posx, posy-1, true, 1, TEE_E);
	}
	lienzo.ActualizarMapaMovimiento(posy, posx);
};

void Eventos::Crear_Cambio_Mapa(Mapa &lienzo, int posx, int posy, int TEE_E){
	lienzo.ActualizarMapaEventos(posx, posy, true, 0, TEE_E);
};


void Eventos::Crear_Evento(Mapa &lienzo, int posx, int posy, int TEE_E){
	lienzo.ActualizarMapaEventos(posx, posy, true, 1, TEE_E);
};

void Eventos::Historia(BITMAP *Fondo, const char *texto){
	blit(Fondo, screen, 0, 0, 0, 0, RX, RY);
	fd = open (texto, O_RDONLY);
	int j, k=50;
	do{
		j=read(fd,buf,54);
		if(j<54)
		buf[j-1]='\0';
		textout_ex(screen, Font1, buf, 50, k, RED_C, -2);
		clear_keybuf();
		readkey();
		k=k+25;
		if(k==425){
			blit(Fondo, screen, 0, 0, 0, 0, RX, RY);
			k=50;
		}
	}while(j==54);
	close(fd);
	
};

void Eventos::conversacion(int _Personaje, const char *texto, int Posicion ){
	Mi_Pintor_Eventos.MenuCombate();
	masked_blit(Personajes[_Personaje-1], screen, 0, 0, Lado/2 , (10*Lado)-169, 160, 169);
	textout_ex(screen, Font1, texto, 50, 325, RED_C, -2);
	clear_keybuf();
	readkey();
};

void Eventos::trigger(void){

};
