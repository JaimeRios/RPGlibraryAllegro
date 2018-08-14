//Clase Personaje.h para el proyecto final
// Copyright Jaime Alberto Rios Palacio (J.shuin)
// Electronic engineering student
// version 0.1 16 Enero 2013 13:21

#include "Definiciones.h" 
#include "Personaje.h"
#include <allegro.h>

//clase luchador
Luchador::Luchador(int _HP, int _MP, int _STR, int _MAG, int _DEF, int _MDEF, const char *_Nombre, BITMAP *PELEA, int Tamx, int Tamy):HP(_HP),MP(_MP),STR(_STR),MAG(_MAG),DEF(_DEF),MDEF(_MDEF),M_HP(_HP),M_MP(_MP){
	Lucha=create_bitmap(Tamx,Tamy);
	blit(PELEA, Lucha, 0, 0, 0, 0, Tamx, Tamy);
	strcpy ( Nombre, _Nombre);
}

int Luchador::GetStatus(const char *s1){
	if(!strcmp(s1,"HP"))
		return HP;
	else if(!strcmp(s1,"MP"))
		return MP;
	else if(!strcmp(s1,"STR"))
		return STR;
	else if(!strcmp(s1,"MAG"))
		return MAG;
	else if(!strcmp(s1,"DEF"))
		return DEF;
	else if(!strcmp(s1,"MDEF"))
		return MDEF;
	else{return -1;}
}


void Luchador::Ataque(Luchador *Peleador, const char *s1){
	int dis;
	if(!strcmp(s1,"STR"))
		dis=Peleador->GetStatus(s1)-DEF;
	else if(!strcmp(s1,"MAG"))
		dis=Peleador->GetStatus(s1)-DEF;
	if(dis<0){
	dis=0;}
	HP=HP-dis;
	if(HP<0){HP=0;}
}

void Luchador::Item(int pocion){
	HP+=pocion*250;
	if(HP>M_HP)
		HP=M_HP;

}

void Luchador::Recargar(void){
	HP=M_HP;
}



//clase Enemigo
Enemigo::Enemigo(int _HP, int _MP, int _STR, int _MAG, int _DEF, int _MDEF, const char *_Nombre, BITMAP *PELEA, int Tamx, int Tamy):Luchador(_HP, _MP, _STR, _MAG, _DEF, _MDEF, _Nombre, PELEA, Tamx, Tamy){

	Lox=Tamx;
	Loy=Tamy;

}

//clase Personaje
Personaje::Personaje(int _HP, int _MP, int _STR, int _MAG, int _DEF, int _MDEF, const char *_Nombre, BITMAP *PELEA, int Tamx, int Tamy):Luchador(_HP, _MP, _STR, _MAG, _DEF, _MDEF, _Nombre, PELEA, Tamx, Tamy){
EXP=0;
LVL=1;

}

