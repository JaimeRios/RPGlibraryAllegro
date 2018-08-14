//Clase Menu.h para el proyecto final
//Copyright Jaime Alberto Rios Palacio (J.shuin)
//Electronic engineering student
//version 0.1 18 Febrero 2013 09:35

#ifndef MENU_H
#define MENU_H
#include <allegro.h>
#include "Definiciones.h"

class Menu{
	private:
	bool Title;
	int TMenu;
	FONT *Font1;
	BITMAP *titulo;
	public:
	Menu(const char *texto);
	void Ejecutar_Menu(bool &done);

};

#endif
