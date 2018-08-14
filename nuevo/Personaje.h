//Clase Personaje.h para el proyecto final
// Copyright Jaime Alberto Rios Palacio (J.shuin)
// Electronic engineering student
// version 0.1 16 Enero 2013 13:21

#ifndef PERSONAJE_H
#define PERSONAJE_H
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

class Enemigo: public Luchador{
	private:
	int Lox,Loy;
	public:
	Enemigo(int _HP, int _MP, int _STR, int _MAG, int _DEF, int _MDEF, const char *_Nombre, BITMAP *PELEA, int Tamx, int Tamy);
	~Enemigo(){};
	void Pintar_pelea(int x, int y){
	masked_blit(Lucha, screen, 0, 0, x, y, Lox, Loy);
	}
};

class Personaje: public Luchador{
	private:
	int EXP,LVL;
	public:
	Personaje(int _HP, int _MP, int _STR, int _MAG, int _DEF, int _MDEF, const char *_Nombre, BITMAP *PELEA, int Tamx, int Tamy);
	~Personaje(){};
	void Pintar_pelea(int x, int y){
	masked_blit(Lucha, screen, 0, Lado, x, y, Lado, Lado);
	}
};

#endif
