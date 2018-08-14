//Clase Peleas.h para el proyecto final
//Copyright Jaime Alberto Rios Palacio (J.shuin)
//Electronic engineering student
//version 0.1 24 Enero 2013 20:53

#ifndef PELEAS_H
#define PELEAS_H
#include "Definiciones.h" 
#include "Personaje.h"
#include "Pintor.h"
#include <cstdlib>
#include <allegro.h>

class Peleas{
	private:
	FONT *Font1;
	BITMAP *Fondo_Batalla;
	Luchador *Pe[3], *En[3];
	SAMPLE *MusicP;
	SAMPLE *MusicV;
	Pintor Mi_Pintor_P;
	bool pel;
	int ba,ba1,ba_I,ba_I2,N_Pocion[3],Me_P[3],Me_E[3],baF[3],Mom_Pe,Turno;
	//Mom_Pe=Momento de la pelea de 0 a 2. 0 escoge accion, 1 escoge objetivo,2 defensa 3 items 
	//ba es para el menu de escoger opcion, atacar defender o items
	//ba1 es para el menu escoger a quien se va a atacar
	//ba_I es para el menu escoger el item que se va a usar
	//ba_I2 es para el menu escoger sobre quien se va a usar el item
	//N_Pocion es para saber el numero de la pocion que se va a usar se guarda respectivamente en la posicion del personaje
	//Me_P es para saber sobre que personaje se hace la accion respectiva
	//Me_E es para saber sobre que enemigo se hace la accion respectiva
	//baF es para para la opcion que se ha esogido al final
	//Turno es para limitar los ataque a los personajes que se estan controlando
	public:
	Peleas(void);
	void Actualizar(void);
	void Lucha(bool &Game_Over, Luchador &Peleador1, Luchador &Peleador2, Luchador &Peleador3, Luchador &Enemigo1, Luchador &Enemigo2, Luchador &Enemigo3);
	~Peleas(){};
};

#endif
