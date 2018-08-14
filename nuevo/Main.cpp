//Clase Main.cpp para el proyecto final
// Copyright Jaime Alberto Rios Palacio (J.shuin)
// Electronic engineering student
// version 0.1 02 Enero 2012 15:42

#include "Definiciones.h"
#include "Mapa.h"
#include "Pintor.h"
#include "GestorMapas.h"
#include "Personaje.h"
#include "Peleas.h"
#include "Eventos.h"
#include "Menu.h"
#include <allegro.h>
#include <cstdlib>



int main(){
	// Initializing Allegro
	allegro_init(); 
	install_keyboard();
	install_timer();
	install_mouse(); 
	set_color_depth(16); 
	install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, "A");
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, RX, RY, 0, 0);
	set_window_title("Las Cronicas de los ejecutores: Xhon");
	BITMAP *BufferFinal = create_bitmap(RX, RY);

	//Cargar canciones
	const char *cancion1=M_Piano;
	const char *cancion2=M_Batalla;
	const char *cancion3=M_Metalworks;
	const char *cancion4=M_Selbina;
	const char *cancion5=M_Sound_of_the_wind;
	const char *cancion6=M_Fanfare;
	const char *cancion7=M_Windaria;

	//variable mapa
	BITMAP *Pisos = load_bitmap("../pueblo/pueblo1.tga", NULL);
	BITMAP *Pisos1 = load_bitmap("../paisajes/Exterior2.tga", NULL);	
	Mapa pueblo(34,48,cancion4,Pisos,0,Lado);

	Mapa casa1pp(15,19,cancion4,Pisos,0,0);
	Mapa Mundo(15,19,cancion5,Pisos1,5*Lado,0);
	Mundo.Activa_Modo_Pelea(15);
	Mapa Montana(25,24,cancion7,Pisos,0,Lado);
	Mapa *ApuM;
	Pintor Mi_Pintor;
	ApuM= &pueblo;

	GestorMapas Juego(ApuM);
	//posicion inicial
	//Juego.ActualizarMov(12,24);
	bool done=false;
	//crear el menu
	Menu Mi_Menu("../pueblo/Titulo3.tga");	

	//crear eventos
	Eventos Mis_Eventos(3,Joshua_Cara,Felicia_Cara,Xhon_Cara);
	BITMAP *Fondo = load_bitmap("../paisajes/ciudad.tga", NULL);
	Mis_Eventos.Crear_Evento(pueblo, 1, 1, 0);	

	//pintar casa Interna
	Mi_Pintor.BorInCa(casa1pp, 1, 2, 15, 9, 1);
	Mi_Pintor.Furnishing(casa1pp, 2, 5, 0);//cama doble
	Mi_Pintor.Furnishing(casa1pp, 5, 3, 1);//ventana
	Mi_Pintor.Furnishing(casa1pp, 7, 3, 2);//cuadro
	Mi_Pintor.Furnishing(casa1pp, 7, 5, 5);//cocina

	//Pintar y eventos montaña
	Mi_Pintor.Paredes_Rocosas(Montana, 2, 2, 23);
	Mi_Pintor.Paredes_Rocosas(Montana, 0, 7, 5);
	Mi_Pintor.Paredes_Rocosas(Montana, 0, 7, 5);
	Mi_Pintor.Paredes_Rocosas(Montana, 0, 12, 2);
	Mi_Pintor.Paredes_Rocosas(Montana, 4, 12, 10);
	Mi_Pintor.Paredes_Rocosas(Montana, 0, 17, 7);
	Mi_Pintor.Paredes_Rocosas(Montana, 9, 17, 6);
	Mi_Pintor.Paredes_Rocosas(Montana, 17, 17, 5);
	Mi_Pintor.Paredes_Rocosas(Montana, 0, 22, 11);
	Mi_Pintor.Paredes_Rocosas(Montana, 13, 22, 11);
	Mi_Pintor.Escaleras(Montana, 11, 23, 2);
	Mi_Pintor.Escaleras(Montana, 0, 3, 2);
	Mis_Eventos.Crear_Cambio_Mapa(Montana, 24, 11, 4);
	Mis_Eventos.Crear_Cambio_Mapa(Montana, 24, 12, 4);

	//Pintar y eventos mapa mundi
	Mi_Pintor.Pueblo(Mundo,10,10);
	Mi_Pintor.Montana(Mundo,14,2);
	Mi_Pintor.Bosque(Mundo,1,1);
	Mi_Pintor.Bosque(Mundo,3,3,3,3);
	Mi_Pintor.Bosque(Mundo,14,12,5,3);
	Mi_Pintor.Pueblo_Sin_Entrada(Mundo, 2, 10, 5);
	Mi_Pintor.Pueblo_Sin_Entrada(Mundo, 9, 3, 3);
	Mi_Pintor.Pequena_Construccion(Mundo, 8, 8, 0);//molino
	Mi_Pintor.Pequena_Construccion(Mundo, 1, 5, 1);//pueblo
	Mi_Pintor.Pequena_Construccion(Mundo, 4, 4, 4);//templo
	Mi_Pintor.Pequena_Construccion(Mundo, 5, 2, 7);//torre1
	Mi_Pintor.Pequena_Construccion(Mundo, 10, 2, 8);//torre2
	Mi_Pintor.Arbol_Exterior(Mundo, 1, 2, 2);
	Mi_Pintor.Arbol_Exterior(Mundo, 17, 6, 2);
	Mi_Pintor.Arbol_Exterior(Mundo, 14, 8, 2);
	Mi_Pintor.Arbol_Exterior(Mundo, 18, 8, 2);

	for(int i=10;i<14;i++){
		for(int j=10;j<12;j++){
			Mis_Eventos.Crear_Cambio_Mapa(Mundo, j, i, 2);//para entrar al pueblo
		}
	}
	
	//Eventos del pueblo
	Mis_Eventos.Crear_Cambio_Mapa(pueblo, 33, 24, 3);
	Mis_Eventos.Crear_Cambio_Mapa(pueblo, 33, 25, 3);
	pueblo.ActualizarMapaEventos(0, 0, true, 1, 1);
	Mis_Eventos.Crear_NPC(pueblo, 1, 0, 0 ,0, 0);

	//pintar
	Mi_Pintor.Tienda(pueblo,2,8,1);
	Mi_Pintor.Tienda(pueblo,2,2,0);
	Mi_Pintor.Academia(pueblo,17,0);
	Mi_Pintor.Fuente(pueblo,24,19);
	int j=18;
	for(int i=0;i<5;i++){	
	Mi_Pintor.Camino(pueblo,j,9,2,3);
	j=j+3;
	}
	Mi_Pintor.Camino(pueblo,18,12,14,1);
	Mi_Pintor.Camino(pueblo,24,13,2,3);
	Mi_Pintor.Camino(pueblo,20,16,10,2);
	Mi_Pintor.Camino(pueblo,20,22,10,2);
	Mi_Pintor.Camino(pueblo,20,18,2,4);
	Mi_Pintor.Camino(pueblo,28,18,2,4);
	Mi_Pintor.Camino(pueblo,24,24,2,10);
	Mi_Pintor.Casa(pueblo,5,16,0);
	Mi_Pintor.Lampara(pueblo,22,18);
	Mi_Pintor.Lampara(pueblo,27,18);
	Mi_Pintor.Lampara(pueblo,17,11);
	Mi_Pintor.Lampara(pueblo,32,11);

	Mi_Pintor.Lampara(pueblo,23,23);
	Mi_Pintor.Lampara(pueblo,23,31);
	Mi_Pintor.Lampara(pueblo,26,23);
	Mi_Pintor.Lampara(pueblo,26,31);
	
	Mi_Pintor.Arbol(pueblo,20,25);	
	Mi_Pintor.Arbol(pueblo,25,25);
	Mi_Pintor.Arbol(pueblo,20,11);	
	Mi_Pintor.Arbol(pueblo,25,11);
	
	FONT *Font1=load_font("Nuevo.pcx", NULL,NULL);

	
	//creacion de personajes y enemigos
	BITMAP *P1 = load_bitmap(Joshua_Caminar, NULL);//96x128
	BITMAP *P2 = load_bitmap(Xhon_Caminar, NULL);//96x128
	BITMAP *P3 = load_bitmap(Felicia_Caminar, NULL);//96x128
	BITMAP *E1 = load_bitmap("../enemigos/Enemigo.tga", NULL);//74x111
	BITMAP *E2 = load_bitmap("../enemigos/Angel.tga", NULL);//142x100
	BITMAP *E3 = load_bitmap("../enemigos/AngelM.tga", NULL);//148x111
	BITMAP *E4 = load_bitmap("../enemigos/Demon.tga", NULL);//77x111
	BITMAP *E5 = load_bitmap("../enemigos/Dragon.tga", NULL);//158x111
	BITMAP *E6 = load_bitmap("../enemigos/Semiangel.tga", NULL);//74x111

	Personaje Joshua(700,100,70,30,20,10,"Joshua",P1,96,128);
	Personaje Xhon(500,200,70,30,20,10,"Xhon",P2,96,128);
	Personaje Felicia(400,400,70,30,20,10,"Felicia",P3,96,128);
	Enemigo Vampiro1(300,20,50,10,20,10,"Vampiro",E1,74,111);
	Enemigo Vampiro2(300,20,50,10,20,10,"Vampiro",E1,74,111);
	Enemigo Vampiro3(300,20,50,10,20,10,"Vampiro",E1,74,111);
	Enemigo Dragon1(520,20,80,10,20,10,"Dragon",E5,158,111);
	Enemigo Dragon2(520,20,80,10,20,10,"Dragon",E5,158,111);
	Enemigo Dragon3(520,20,80,10,20,10,"Dragon",E5,158,111);
	Enemigo Angel1(1500,20,110,10,20,10,"Angel",E6,142,100);
	Enemigo Angel2(1300,20,90,10,20,10,"Mjr Angel",E3,148,111);
	Enemigo Angel3(1450,20,80,10,20,10,"Gran Angel",E2,74,111);
	Enemigo Demonio(2000,20,150,10,20,10,"Gran Angel",E4,77,111);
	Enemigo Demonio1(500,20,150,10,20,10,"Gran Angel",E4,77,111);
	Enemigo Zombie1(0,20,80,10,20,10,"Zombie",E2,74,111);
	Enemigo Zombie2(0,20,150,10,20,10,"Zombie",E4,77,111);



	Peleas Mi_Pelea;
	
	//menu
	Mi_Menu.Ejecutar_Menu(done); 

	ApuM->mapmov();
	ApuM->TocarMusica();

	//ApuM= &casa1pp;
	bool H_E=false;
	bool Pelear=false;
	int T_E=0;
	int E_E=0;

	//CICLO DEL JUEGO
	while(!done){
		
		if(key[KEY_ESC])
		done = true;
	
		Juego.Moverse(Pelear);
		if(Pelear){//si hay peleas
				Juego.Parar_Musica();
				int jp;
				jp=(rand() % 3);
				if(jp==0)
				Mi_Pelea.Lucha(done,Joshua,Xhon,Felicia,Vampiro1,Vampiro2,Vampiro3);
				if(jp==1)
				Mi_Pelea.Lucha(done,Joshua,Xhon,Felicia,Dragon1,Dragon2,Dragon3);
				if(jp==2)
				Mi_Pelea.Lucha(done,Joshua,Xhon,Felicia,Demonio1,Zombie1,Zombie2);

				Pelear=false;
				if(!done)
				Juego.Reproducir_Musica();
				if(done){
					Mi_Pintor.GameOver();
				}
		}
		Juego.Evento(H_E,T_E,E_E);
		cout<<H_E<<" "<< T_E<<" "<<E_E<<endl;
		if(H_E){
			switch(T_E){
				//CAMBIO DE MAPA
				case 0:	
					switch(E_E){
						case 0://pueblo->casa1pp
							if(key[KEY_ENTER]){
							ApuM= &casa1pp;
							Juego.CambioMapa(ApuM,false);
							Juego.ActualizarMov(10,12);							
							}
							break;
						case 1://casa1pp->pueblo
							ApuM= &pueblo;
							Juego.CambioMapa(ApuM,false);
							Juego.ActualizarMov(9,24);
							break;
						case 2://Mundo->pueblo
							ApuM=&pueblo;
							Juego.CambioMapa(ApuM,true);
							Juego.ActualizarMov(25,33);
							break;
						case 3://pueblo->Mundo
							ApuM=&Mundo;
							Juego.CambioMapa(ApuM,true);
							Juego.ActualizarMov(12,13);
							break;
						case 4://Montaña->Mundo
							ApuM=&Mundo;
							Juego.CambioMapa(ApuM,true);
							Juego.ActualizarMov(15,6);
							break;
						case 5://Mundo->Monaña
							if(key[KEY_ENTER]){
							ApuM=&Montana;
							Juego.CambioMapa(ApuM,true);
							Juego.ActualizarMov(12,24);}
							break;
					}
					break;

				//EVENTO TEXTOS
				case 1: //	
					switch(E_E){
						case 0:
							if(key[KEY_ENTER]){
							Mis_Eventos.conversacion(2, "Sabias que hay un camino oculto para entra a la montana", 0 );
							Mis_Eventos.Crear_Cambio_Mapa(Mundo, 4, 14, 5);//para entrar a la montaña
							Mis_Eventos.Crear_Cambio_Mapa(Mundo, 4, 15, 5);//para entrar a la montaña*/
//							Mis_Eventos.Historia(Fondo, "../historias/Historia1");
//							pueblo.ActualizarMapaEventos(1, 1, false, 1, 0);
							}
							break;
						case 1:
							if(key[KEY_ENTER]){
							Mis_Eventos.Historia(Fondo, "../historias/Historia1");}
							//pueblo.ActualizarMapaEventos(0, 0, false, 1, 1);
							break;
					}
					break;

				//EVENTO TIENDAS
				case 2:
					break;
		
			}
		}
	}
	//readkey();
	ApuM->PararMusica();
	return 0;
}

END_OF_MAIN()
