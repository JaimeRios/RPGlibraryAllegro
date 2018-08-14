//Clase Peleas.cpp para el proyecto final
//Copyright Jaime Alberto Rios Palacio (J.shuin)
//Electronic engineering student
//version 0.1 24 Enero 2013 21:07

#include "Definiciones.h" 
#include "Personaje.h"
#include "Peleas.h"
#include "Pintor.h"
#include <cstdlib>
#include <allegro.h>

Peleas::Peleas(void){
	MusicP=load_sample(M_Batalla);
	MusicV=load_sample(M_Fanfare);
	Fondo_Batalla = load_bitmap("../pueblo/batalla.tga", NULL);
	Font1=load_font("Nuevo.pcx", NULL,NULL);
}
void Peleas::Actualizar(void){
	blit(Fondo_Batalla, screen, 0, 0, 0, 0, RX, RY);
	Pe[0]->Pintar_pelea(514,200);//514,200
	Pe[1]->Pintar_pelea(530,240);//530,240
	Pe[2]->Pintar_pelea(546,280);//546,280
	Mi_Pintor_P.MenuCombate();
	textout_ex(screen, Font1, "Enemigos HP", 175, 325, RED_C, -2);
	textout_ex(screen, Font1, "Personajes  HP", 400, 325, RED_C, -2);
	if((En[0]->GetStatus("HP"))!=0){//si esta "muerto" no lo pinte
		En[0]->Pintar_pelea(10,200);
	 	textprintf_ex(screen, Font1, 250, 350, RED_C,-1, "%d", En[0]->GetStatus("HP"));
		textout_ex(screen, Font1, En[0]->Get_Nombre(), 150, 350, RED_C, -2);
	}
	if((En[1]->GetStatus("HP"))!=0){
		En[1]->Pintar_pelea(100,100);
		textprintf_ex(screen, Font1, 250, 375, RED_C,-1, "%d", En[1]->GetStatus("HP"));
		textout_ex(screen, Font1, En[1]->Get_Nombre(), 150, 375, RED_C,-2);
	}
	if((En[2]->GetStatus("HP"))!=0){
		En[2]->Pintar_pelea(200,200);
	 	textprintf_ex(screen, Font1, 250, 400, RED_C,-1, "%d", En[2]->GetStatus("HP"));
		textout_ex(screen, Font1, En[2]->Get_Nombre(), 150, 400, RED_C, -2);
		}
	textprintf_ex(screen, Font1, 500, 350, RED_C,-1, "%d", Pe[0]->GetStatus("HP"));
	textprintf_ex(screen, Font1, 500, 375, RED_C,-1, "%d", Pe[1]->GetStatus("HP"));
	textprintf_ex(screen, Font1, 500, 400, RED_C,-1, "%d", Pe[2]->GetStatus("HP"));
	textout_ex(screen, Font1, Pe[0]->Get_Nombre(), 400, 350, RED_C, -2);
	textout_ex(screen, Font1, Pe[1]->Get_Nombre(), 400, 375, RED_C, -2);
	textout_ex(screen, Font1, Pe[2]->Get_Nombre(), 400, 400, RED_C, -2);
}

void Peleas::Lucha(bool &Game_Over, Luchador &Peleador1, Luchador &Peleador2, Luchador &Peleador3, Luchador &Enemigo1, Luchador &Enemigo2, Luchador &Enemigo3){
	//actualizacion datos para la batalla
	ba=0;
	ba1=0;
	ba_I=0;
	ba_I2=0;
	Mom_Pe=0;
	Turno=0;	//carga a los luchadores
	Pe[0]=&Peleador1;
	Pe[1]=&Peleador2;
	Pe[2]=&Peleador3;
	En[0]=&Enemigo1;
	En[1]=&Enemigo2;
	En[2]=&Enemigo3;
	//pinta pantalla
	this->Actualizar();
	//carga la musica
	play_sample(MusicP, 255, 127, 1000, true);
	pel=false;
	if((Pe[Turno]->GetStatus("HP"))==0){
		Turno++;
	}
	if((Pe[Turno]->GetStatus("HP"))==0){
		Turno++;
	}
	while(!pel){
		do{
		switch(Mom_Pe){

			case 0://escoger opcion
				if(key[KEY_UP]){
					ba-=1;
					if(ba<0){ba=0;}		
				}
				else if(key[KEY_DOWN]){
					ba+=1;
					if(ba>2){ba=2;}		
				}
				switch (ba){
					case 0:
						Mi_Pintor_P.MenuCombate();
						textout_ex(screen, Font1, "Enemigos HP", 175, 325, RED_C, -2);
						textout_ex(screen, Font1, "Personajes  HP", 400, 325, RED_C, -2);
						textout_ex(screen, Font1, "ATAQUE", 50, 325, GREEN_C, -2);
						textout_ex(screen, Font1, "DEFENSA", 50, 350, RED_C, -2);
						textout_ex(screen, Font1, "OBJETOS", 50, 375, RED_C, -2);
						if((En[0]->GetStatus("HP"))!=0){
						 	textprintf_ex(screen, Font1, 250, 350, RED_C,-1, "%d", En[0]->GetStatus("HP"));
							textout_ex(screen, Font1, En[0]->Get_Nombre(), 150, 350, RED_C, -2);
						}
						if((En[1]->GetStatus("HP"))!=0){
					 		textprintf_ex(screen, Font1, 250, 375, RED_C,-1, "%d", En[1]->GetStatus("HP"));
							textout_ex(screen, Font1, En[1]->Get_Nombre(), 150, 375, RED_C,-2);
						}
						if((En[2]->GetStatus("HP"))!=0){
						 	textprintf_ex(screen, Font1, 250, 400, RED_C,-1, "%d", En[2]->GetStatus("HP"));
							textout_ex(screen, Font1, En[2]->Get_Nombre(), 150, 400, RED_C, -2);
						}
			 			textprintf_ex(screen, Font1, 500, 350, RED_C,-1, "%d", Pe[0]->GetStatus("HP"));
			 			textprintf_ex(screen, Font1, 500, 375, RED_C,-1, "%d", Pe[1]->GetStatus("HP"));
			 			textprintf_ex(screen, Font1, 500, 400, RED_C,-1, "%d", Pe[2]->GetStatus("HP"));
						textout_ex(screen, Font1, Pe[0]->Get_Nombre(), 400, 350, RED_C, -2);
						textout_ex(screen, Font1, Pe[1]->Get_Nombre(), 400, 375, RED_C, -2);
						textout_ex(screen, Font1, Pe[2]->Get_Nombre(), 400, 400, RED_C, -2);
						readkey();
						break;
					case 1:
						Mi_Pintor_P.MenuCombate();
						textout_ex(screen, Font1, "Enemigos HP", 175, 325, RED_C, -2);
						textout_ex(screen, Font1, "Personajes  HP", 400, 325, RED_C, -2);
						textout_ex(screen, Font1, "ATAQUE", 50, 325, RED_C, -2);
						textout_ex(screen, Font1, "DEFENSA", 50, 350, GREEN_C, -2);
						textout_ex(screen, Font1, "OBJETOS", 50, 375, RED_C, -2);
						if((En[0]->GetStatus("HP"))!=0){
						 	textprintf_ex(screen, Font1, 250, 350, RED_C,-1, "%d", En[0]->GetStatus("HP"));
							textout_ex(screen, Font1, En[0]->Get_Nombre(), 150, 350, RED_C, -2);
						}
						if((En[1]->GetStatus("HP"))!=0){
					 		textprintf_ex(screen, Font1, 250, 375, RED_C,-1, "%d", En[1]->GetStatus("HP"));
							textout_ex(screen, Font1, En[1]->Get_Nombre(), 150, 375, RED_C,-2);
						}
						if((En[2]->GetStatus("HP"))!=0){
						 	textprintf_ex(screen, Font1, 250, 400, RED_C,-1, "%d", En[2]->GetStatus("HP"));
							textout_ex(screen, Font1, En[2]->Get_Nombre(), 150, 400, RED_C, -2);
						}
			 			textprintf_ex(screen, Font1, 500, 350, RED_C,-1, "%d", Pe[0]->GetStatus("HP"));
			 			textprintf_ex(screen, Font1, 500, 375, RED_C,-1, "%d", Pe[1]->GetStatus("HP"));
			 			textprintf_ex(screen, Font1, 500, 400, RED_C,-1, "%d", Pe[2]->GetStatus("HP"));
						textout_ex(screen, Font1, Pe[0]->Get_Nombre(), 400, 350, RED_C, -2);
						textout_ex(screen, Font1, Pe[1]->Get_Nombre(), 400, 375, RED_C, -2);
						textout_ex(screen, Font1, Pe[2]->Get_Nombre(), 400, 400, RED_C,-2);
						readkey();
						break;
					case 2:
						Mi_Pintor_P.MenuCombate();
						textout_ex(screen, Font1, "Enemigos HP", 175, 325, RED_C, -2);
						textout_ex(screen, Font1, "Personajes  HP", 400, 325, RED_C, -2);
						textout_ex(screen, Font1, "ATAQUE", 50, 325, RED_C, -2);
						textout_ex(screen, Font1, "DEFENSA", 50, 350, RED_C, -2);
						textout_ex(screen, Font1, "OBJETOS", 50, 375, GREEN_C, -2);
						if((En[0]->GetStatus("HP"))!=0){
						 	textprintf_ex(screen, Font1, 250, 350, RED_C,-1, "%d", En[0]->GetStatus("HP"));
							textout_ex(screen, Font1, En[0]->Get_Nombre(), 150, 350, RED_C, -2);
						}
						if((En[1]->GetStatus("HP"))!=0){
					 		textprintf_ex(screen, Font1, 250, 375, RED_C,-1, "%d", En[1]->GetStatus("HP"));
							textout_ex(screen, Font1, En[1]->Get_Nombre(), 150, 375, RED_C,-2);
						}
						if((En[2]->GetStatus("HP"))!=0){
						 	textprintf_ex(screen, Font1, 250, 400, RED_C,-1, "%d", En[2]->GetStatus("HP"));
							textout_ex(screen, Font1, En[2]->Get_Nombre(), 150, 400, RED_C, -2);
						}
			 			textprintf_ex(screen, Font1, 500, 350, RED_C,-1, "%d", Pe[0]->GetStatus("HP"));
			 			textprintf_ex(screen, Font1, 500, 375, RED_C,-1, "%d", Pe[1]->GetStatus("HP"));
			 			textprintf_ex(screen, Font1, 500, 400, RED_C,-1, "%d", Pe[2]->GetStatus("HP"));
						textout_ex(screen, Font1, Pe[0]->Get_Nombre(), 400, 350, RED_C, -2);
						textout_ex(screen, Font1, Pe[1]->Get_Nombre(), 400, 375, RED_C, -2);
						textout_ex(screen, Font1, Pe[2]->Get_Nombre(), 400, 400, RED_C, -2);			
						readkey();
						break;
				}//fin de los cases de sobresaltar opcion
				if(key[KEY_ENTER]){
					if(ba==0){//va al caso atacar
						Mom_Pe=1;
						baF[Turno]=ba;//a tenerse en cuenta en la parte final de los turnos
						ba1=0;
						if(ba==0){
							while((En[ba1]->GetStatus("HP"))==0){
								ba1++;
							}
						}
					}
					if(ba==1){//va a defenderse
						Mom_Pe=2;
						baF[Turno]=ba;
					}
					if(ba==2){//va a usar item en compañero
						Mom_Pe=3;
						baF[Turno]=ba;
					}
				}
				break;
			case 1://atacar
				if(key[KEY_UP]){
					ba1-=1;
					if(ba1<0){ba1=0;}
					if(((En[ba1]->GetStatus("HP"))==0)&&(ba1==1)){
						if((En[0]->GetStatus("HP"))==0){ba1=2;}
						else{ba1=0;}
					}
					if(((En[ba1]->GetStatus("HP"))==0)&&(ba1==0)){
						ba1=1;
					}
				}
				else if(key[KEY_DOWN]){
					ba1+=1;
					if(ba1>2){ba1=2;}
					if(((En[ba1]->GetStatus("HP"))==0)&&(ba1==1)){
						if((En[2]->GetStatus("HP"))==0){ba1=0;}
						else{ba1=2;}
					}
					if(((En[ba1]->GetStatus("HP"))==2)&&(ba1==2)){
						ba1=1;
					}
				}
				switch(ba1){
					case 0:
						if((En[0]->GetStatus("HP"))!=0)
						textout_ex(screen, Font1, En[0]->Get_Nombre(), 150, 350, GREEN_C, -2);
						if((En[1]->GetStatus("HP"))!=0)
						textout_ex(screen, Font1, En[1]->Get_Nombre(), 150, 375, RED_C, -2);
						if((En[2]->GetStatus("HP"))!=0)
						textout_ex(screen, Font1, En[2]->Get_Nombre(), 150, 400, RED_C, -2);
						readkey();
						break;
					case 1:
						if((En[0]->GetStatus("HP"))!=0)
						textout_ex(screen, Font1, En[0]->Get_Nombre(), 150, 350, RED_C, -2);
						if((En[1]->GetStatus("HP"))!=0)
						textout_ex(screen, Font1, En[1]->Get_Nombre(), 150, 375, GREEN_C, -2);
						if((En[2]->GetStatus("HP"))!=0)
						textout_ex(screen, Font1, En[2]->Get_Nombre(), 150, 400, RED_C, -2);
						readkey();
						break;
					case 2:
						if((En[0]->GetStatus("HP"))!=0)
						textout_ex(screen, Font1, En[0]->Get_Nombre(), 150, 350, RED_C, -2);
						if((En[1]->GetStatus("HP"))!=0)
						textout_ex(screen, Font1, En[1]->Get_Nombre(), 150, 375, RED_C, -2);
						if((En[2]->GetStatus("HP"))!=0)
						textout_ex(screen, Font1, En[2]->Get_Nombre(), 150, 400, GREEN_C, -2);
						readkey();
						break;
				}
				if(key[KEY_ESC]){
					Mom_Pe=0;
					if((En[0]->GetStatus("HP"))!=0)
					textout_ex(screen, Font1, En[0]->Get_Nombre(), 150, 350, RED_C, -2);
					if((En[1]->GetStatus("HP"))!=0)
					textout_ex(screen, Font1, En[1]->Get_Nombre(), 150, 375, RED_C, -2);
					if((En[2]->GetStatus("HP"))!=0)
					textout_ex(screen, Font1, En[2]->Get_Nombre(), 150, 400, RED_C, -2);
				}
				if(key[KEY_ENTER]){
					Mom_Pe=0;
					if((En[0]->GetStatus("HP"))!=0)
					textout_ex(screen, Font1, En[0]->Get_Nombre(), 150, 350, RED_C, -2);
					if((En[1]->GetStatus("HP"))!=0)
					textout_ex(screen, Font1, En[1]->Get_Nombre(), 150, 375, RED_C, -2);
					if((En[2]->GetStatus("HP"))!=0)
					textout_ex(screen, Font1, En[2]->Get_Nombre(), 150, 400, RED_C, -2);
					Me_E[Turno]=ba1;
					ba1=0;
					Turno++;
					if(((Pe[Turno]->GetStatus("HP"))==0)&&(Turno==1)){
						baF[Turno]=3;
						Turno++;
					}
					if(((Pe[Turno]->GetStatus("HP"))==0)&&(Turno==2)){
						baF[Turno]=3;
						Turno++;
					}
				}
				break;//case escoge objetivo
			case 2://defenderse
				Mom_Pe=0;
				Turno++;
				if(((Pe[Turno]->GetStatus("HP"))==0)&&(Turno==1)){
					baF[Turno]=3;
					Turno++;
				}
				if(((Pe[Turno]->GetStatus("HP"))==0)&&(Turno==2)){
					baF[Turno]=3;
					Turno++;
				}
				ba=0;
				break;
			case 3://usar Item
				Mi_Pintor_P.MenuCombateObjetos();
				switch(ba_I){
					case 0:
						textout_ex(screen, Font1, "Pocion Nivel 1", 3*Lado, 11*Lado, GREEN_C, -2);
						textout_ex(screen, Font1, "Pocion Nivel 2", 3*Lado, (11*Lado)+26, RED_C, -2);
						textout_ex(screen, Font1, "Pocion Nivel 3", 3*Lado, (11*Lado)+52, RED_C, -2);
						textout_ex(screen, Font1, "Pocion Nivel 4", 3*Lado, (11*Lado)+78, RED_C, -2);
						readkey();
						break;
					case 1:
						textout_ex(screen, Font1, "Pocion Nivel 1", 3*Lado, 11*Lado, RED_C, -2);
						textout_ex(screen, Font1, "Pocion Nivel 2", 3*Lado, (11*Lado)+26, GREEN_C, -2);
						textout_ex(screen, Font1, "Pocion Nivel 3", 3*Lado, (11*Lado)+52, RED_C, -2);
						textout_ex(screen, Font1, "Pocion Nivel 4", 3*Lado, (11*Lado)+78, RED_C, -2);
						readkey();
						break;
					case 2:
						textout_ex(screen, Font1, "Pocion Nivel 1", 3*Lado, 11*Lado, RED_C, -2);
						textout_ex(screen, Font1, "Pocion Nivel 2", 3*Lado, (11*Lado)+26, RED_C, -2);
						textout_ex(screen, Font1, "Pocion Nivel 3", 3*Lado, (11*Lado)+52, GREEN_C, -2);
						textout_ex(screen, Font1, "Pocion Nivel 4", 3*Lado, (11*Lado)+78, RED_C, -2);
						readkey();
						break;
					case 3:
						textout_ex(screen, Font1, "Pocion Nivel 1", 3*Lado, 11*Lado, RED_C, -2);
						textout_ex(screen, Font1, "Pocion Nivel 2", 3*Lado, (11*Lado)+26, RED_C, -2);
						textout_ex(screen, Font1, "Pocion Nivel 3", 3*Lado, (11*Lado)+52, RED_C, -2);
						textout_ex(screen, Font1, "Pocion Nivel 4", 3*Lado, (11*Lado)+78, GREEN_C, -2);
						readkey();
						break;
				}
				if(key[KEY_DOWN]){
					ba_I+=1;
					if(ba_I>3)
					ba_I=3;	
				}
				if(key[KEY_UP]){
					ba_I-=1;
					if(ba_I<0)
					ba_I=0;
				}
				if(key[KEY_ESC]){
					Mom_Pe=0;
				}
				if(key[KEY_ENTER]){
					Mom_Pe=4;
					N_Pocion[Turno]=ba_I+1;
					//REFRESCAR DATOS DE PELEA
					Mi_Pintor_P.MenuCombate();
					textout_ex(screen, Font1, "Enemigos HP", 175, 325, RED_C, -2);
					textout_ex(screen, Font1, "Personajes  HP", 400, 325, RED_C, -2);
					textout_ex(screen, Font1, "ATAQUE", 50, 325, RED_C, -2);
					textout_ex(screen, Font1, "DEFENSA", 50, 350, RED_C, -2);
					textout_ex(screen, Font1, "OBJETOS", 50, 375, GREEN_C, -2);
						if((En[0]->GetStatus("HP"))!=0){
						 	textprintf_ex(screen, Font1, 250, 350, RED_C,-1, "%d", En[0]->GetStatus("HP"));
							textout_ex(screen, Font1, En[0]->Get_Nombre(), 150, 350, RED_C, -2);
						}
						if((En[1]->GetStatus("HP"))!=0){
					 		textprintf_ex(screen, Font1, 250, 375, RED_C,-1, "%d", En[1]->GetStatus("HP"));
							textout_ex(screen, Font1, En[1]->Get_Nombre(), 150, 375, RED_C,-2);
						}
						if((En[2]->GetStatus("HP"))!=0){
						 	textprintf_ex(screen, Font1, 250, 400, RED_C,-1, "%d", En[2]->GetStatus("HP"));
							textout_ex(screen, Font1, En[2]->Get_Nombre(), 150, 400, RED_C, -2);
						}
			 			textprintf_ex(screen, Font1, 500, 350, RED_C,-1, "%d", Pe[0]->GetStatus("HP"));
			 			textprintf_ex(screen, Font1, 500, 375, RED_C,-1, "%d", Pe[1]->GetStatus("HP"));
			 			textprintf_ex(screen, Font1, 500, 400, RED_C,-1, "%d", Pe[2]->GetStatus("HP"));
						textout_ex(screen, Font1, Pe[0]->Get_Nombre(), 400, 350, RED_C, -2);
						textout_ex(screen, Font1, Pe[1]->Get_Nombre(), 400, 375, RED_C, -2);
						textout_ex(screen, Font1, Pe[2]->Get_Nombre(), 400, 400, RED_C, -2);
				}
				break;
			case 4://escoger sobre quien usar el item
				switch(ba_I2){
					case 0:
						textout_ex(screen, Font1, Pe[0]->Get_Nombre(), 400, 350, GREEN_C, -2);
						textout_ex(screen, Font1, Pe[1]->Get_Nombre(), 400, 375, RED_C, -2);
						textout_ex(screen, Font1, Pe[2]->Get_Nombre(), 400, 400, RED_C, -2);
						readkey();
						break;
					case 1:
						textout_ex(screen, Font1, Pe[0]->Get_Nombre(), 400, 350, RED_C, -2);
						textout_ex(screen, Font1, Pe[1]->Get_Nombre(), 400, 375, GREEN_C, -2);
						textout_ex(screen, Font1, Pe[2]->Get_Nombre(), 400, 400, RED_C, -2);
						readkey();
						break;
					case 2:
						textout_ex(screen, Font1, Pe[0]->Get_Nombre(), 400, 350, RED_C, -2);
						textout_ex(screen, Font1, Pe[1]->Get_Nombre(), 400, 375, RED_C, -2);
						textout_ex(screen, Font1, Pe[2]->Get_Nombre(), 400, 400, GREEN_C, -2);
						readkey();
						break;
				}
				if(key[KEY_DOWN]){
					ba_I2+=1;
					if(ba_I2>2)
						ba_I2=2;	
				}
				if(key[KEY_UP]){
					ba_I2-=1;
					if(ba_I2<0)
						ba_I2=0;
				}
				if(key[KEY_ESC]){
					Mom_Pe=3;
				}
				if(key[KEY_ENTER]){
					Me_P[Turno]=ba_I2;
					Mom_Pe=0;
					Turno++;
					if(((Pe[Turno]->GetStatus("HP"))==0)&&(Turno==1)){
						baF[Turno]=3;
						Turno++;
					}
					if(((Pe[Turno]->GetStatus("HP"))==0)&&(Turno==2)){
						baF[Turno]=3;
						Turno++;
					}
					ba=0;
				}
				break;
		}
		}while(Turno<3);
			//acciones
			
			if(Turno==3){
				for(int i=0;i<3;i++){
					if(!(Pe[i]->GetStatus("HP")==0)){
					if(!((En[0]->GetStatus("HP")==0)&&(En[1]->GetStatus("HP")==0)&&(En[2]->GetStatus("HP")==0))){
						switch(baF[i]){
							case 0://atacar
								if((En[Me_E[i]]->GetStatus("HP"))!=0){
									En[Me_E[i]]->Ataque(Pe[i],"STR");
									this->Actualizar();
									textprintf_ex(screen, Font1, 50, 425, RED_C,-1, "%s ataca a %s %d", 
									Pe[i]->Get_Nombre(), En[Me_E[i]]->Get_Nombre(),Me_E[i]+1);
									readkey();
								}								
								break;
							case 1://defenderse
								this->Actualizar();
								textprintf_ex(screen, Font1, 50, 425, RED_C,-1, "%s toma la posicion de defensa", Pe[i]->Get_Nombre());
								readkey();
								break;
							case 2://usar items
								Pe[Me_P[i]]->Item(N_Pocion[i]);
								this->Actualizar();
								textprintf_ex(screen, Font1, 50, 425, RED_C,-1, "%s ha usado pocion en %s ", 
								Pe[i]->Get_Nombre(), Pe[Me_P[i]]->Get_Nombre() );
								readkey();
								break;
						}//casos de pelea
					}
					}				
				}//turnos personajes
				for(int i=0;i<3;i++){//turnos enemigo
					int k;
					if(!((Pe[0]->GetStatus("HP")==0)&&(Pe[1]->GetStatus("HP")==0)&&(Pe[2]->GetStatus("HP")==0))){
						do{
							k=(rand() % 3);
						}while(!(Pe[k]->GetStatus("HP")!=0));
						if((En[i]->GetStatus("HP"))!=0){
						Pe[k]->Ataque(En[i],"STR");//enemigo k ataca a uno aleatoriamente
						this->Actualizar();
						textprintf_ex(screen, Font1, 50, 425, RED_C,-1, "Enemigo %d ataca a %s", i+1, 
						Pe[k]->Get_Nombre());
						readkey();
						}
					}
					
				}
				Turno=0;
				if(!((Pe[0]->GetStatus("HP")==0)&&(Pe[1]->GetStatus("HP")==0)&&(Pe[2]->GetStatus("HP")==0))){
					while((Pe[Turno]->GetStatus("HP")==0)){
						Turno++;
					}
				}
			}
			
			if((En[0]->GetStatus("HP")==0)&&(En[1]->GetStatus("HP")==0)&&(En[2]->GetStatus("HP")==0)){
				this->Actualizar();
				pel=true;
				stop_sample(MusicP);
				play_sample(MusicV, 255, 127, 1000, true);
				readkey();
				stop_sample(MusicV);
				for(int i=0;i<3;i++){
					En[i]->Recargar();
				}
			}
			if((Pe[0]->GetStatus("HP")==0)&&(Pe[1]->GetStatus("HP")==0)&&(Pe[2]->GetStatus("HP")==0)){
				Game_Over=true;				
				pel=true;
				stop_sample(MusicP);
				readkey();
				stop_sample(MusicV);
				for(int i=0;i<3;i++){
					En[i]->Recargar();
				}				
			}
	}

}

