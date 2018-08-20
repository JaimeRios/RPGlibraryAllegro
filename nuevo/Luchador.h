//Clase Luchador.h para el proyecto final
// Copyright Jaime Alberto Rios Palacio (J.shuin)
// Electronic engineering
// version 0.1 14 Agosto 2018 14:12

#ifndef LUCHADOR_H
#define LUCHADOR_H

#include <allegro.h>
#include <string.h>


class Luchador{
	protected:
	int HP,MP,STR,MAG,DEF,MDEF,M_HP,M_MP;
	char Nombre[10];
	BITMAP *Lucha;
	public:
	Luchador(int _HP, int _MP, int _STR, int _MAG, int _DEF, int _MDEF, const char *_Nombre, BITMAP *PELEA, int Tamx, int Tamy);
	~Luchador(){};
	int GetStatus(const char *s1);
	void Ataque(Luchador *Peleador, const char *s1);
	void Item(int pocion);
	void Recargar(void);
	virtual void Pintar_pelea(int i, int j){};
	const char* Get_Nombre(void){return Nombre;};
};

#endif 
