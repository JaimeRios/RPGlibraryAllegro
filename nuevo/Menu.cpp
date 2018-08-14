//Clase Menu.h para el proyecto final
//Copyright Jaime Alberto Rios Palacio (J.shuin)
//Electronic engineering student
//version 0.1 18 Febrero 2013 09:35

#include <allegro.h>
#include "Menu.h"
#include "Definiciones.h"

Menu::Menu(const char *texto){
	Title=false;
	TMenu=0;
	Font1=load_font("Nuevo.pcx", NULL,NULL);
	titulo=load_bitmap(texto, NULL);
}

void Menu::Ejecutar_Menu(bool &done){

	while(!Title){
		blit(titulo, screen, 0, 0, 0, 0, RX, RY);
			switch(TMenu){
				case 0:
					textout_ex(screen, Font1, "NUEVO JUEGO", 450, 350, GREEN_C, -2);
					textout_ex(screen, Font1, "TUTORIAL", 450, 370, RED_C, -2);
					textout_ex(screen, Font1, "SALIR", 450, 390, RED_C, -2);
					readkey();
					if(key[KEY_ENTER]){
					done=false;
					Title=true;
					}
					break;
				case 1:
					textout_ex(screen, Font1, "NUEVO JUEGO", 450, 350, RED_C, -2);
					textout_ex(screen, Font1, "TUTORIAL", 450, 370, GREEN_C, -2);
					textout_ex(screen, Font1, "SALIR", 450, 390, RED_C, -2);
					readkey();
					break;
				case 2:
					textout_ex(screen, Font1, "NUEVO JUEGO", 450, 350, RED_C, -2);
					textout_ex(screen, Font1, "TUTORIAL", 450, 370, RED_C, -2);
					textout_ex(screen, Font1, "SALIR", 450, 390, GREEN_C, -2);
					readkey();
					if(key[KEY_ENTER]){
					done=true;
					Title=true;
					}
					break;
			}
			if(key[KEY_DOWN]){
				TMenu++;
				if(TMenu>2)
					TMenu=0;
			}
			else if(key[KEY_UP]){
				TMenu--;
				if(TMenu<0)
					TMenu=2;
			}
	}

}


