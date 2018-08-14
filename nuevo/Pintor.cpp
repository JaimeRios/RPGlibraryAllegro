//Clase Pintor.cpp para el proyecto final
// Copyright Jaime Alberto Rios Palacio (J.shuin)
// Electronic engineering student
// version 0.1 23 Diciembre 2012 15:42

#include "Definiciones.h" 
#include "Mapa.h"
#include "Pintor.h"
#include <allegro.h>

Pintor::Pintor(void){
	Origen[0] = load_bitmap("../pueblo/Academia.tga", NULL);
	Origen[1] = load_bitmap("../pueblo/pueblo1.tga", NULL);
	Origen[2] = load_bitmap("../pueblo/pueblo2.tga", NULL);
	Origen[3] = load_bitmap("../paisajes/paisajesE.tga", NULL);
	Origen[4] = load_bitmap("../pueblo/tiendaArmas1.tga", NULL);
	Origen[5] = load_bitmap("../pueblo/Arboles.tga", NULL);
	Origen[6] = load_bitmap("../pueblo/tiendaObjetos1.tga", NULL);
	Origen[7] = load_bitmap("../pueblo/Muros.tga", NULL);
	Origen[8] = load_bitmap("../pueblo/PuertasDobles.tga", NULL);
	Origen[9] = load_bitmap("../pueblo/Pueblo3.tga", NULL);
	Origen[10] = load_bitmap("../pueblo/Pueblo4.tga", NULL);
	Origen[11] = load_bitmap("../pueblo/Pueblo5.tga", NULL);
	Origen[12] = load_bitmap("../pueblo/Menus.tga", NULL);
	Origen[13] = load_bitmap("../pueblo/Objetos.tga",NULL);
	Origen[14] = load_bitmap("../paisajes/Exterior2.tga",NULL);
	Origen[15] = load_bitmap("../pueblo/interiores2.tga",NULL);
	Origen[16] = load_bitmap("../paisajes/GameOver.tga",NULL);
//casa
Figuras[0]=create_bitmap(Lado*7,Lado*7);
blit(Origen[2], Figuras[0], 0, 0, 0, 0, Lado*7, Lado*7);

//Tiendas
Figuras[1]=create_bitmap(Lado*4,Lado*6);
blit(Origen[4], Figuras[1], 384, 128, 0, 0, Lado*4, Lado*6);

Figuras[2]=create_bitmap(Lado*4,Lado*6);
blit(Origen[6], Figuras[2], 384, 128, 0, 0, Lado*4, Lado*6);

//Arbol
Figuras[3]=create_bitmap(Lado*5,Lado*6);
blit(Origen[5], Figuras[3], 128, 192, 0, 0, Lado*5, Lado*6);

//Academia
Figuras[4]=create_bitmap(Lado*18,Lado*8);
blit(Origen[0], Figuras[4], 0, 0, 0, 0, Lado*16, Lado*5);
blit(Origen[7], Figuras[4], 16, 3*Lado, 16*Lado, 0, Lado*1, Lado*2);
blit(Origen[7], Figuras[4], 16, 3*Lado, 17*Lado, 0, Lado*1, Lado*2);
blit(Origen[7], Figuras[4], 0, 3*Lado, 16*Lado, 2*Lado, Lado*1, Lado*2);
blit(Origen[7], Figuras[4], 1*Lado, 3*Lado, 17*Lado, 2*Lado, Lado*1, Lado*2);

blit(Origen[7], Figuras[4], 0*Lado, 1*Lado, 0*Lado, 5*Lado, Lado*1, Lado*1);
blit(Origen[7], Figuras[4], 0*Lado, (1*Lado)+16, 0*Lado, 6*Lado, Lado*1, Lado*1);
blit(Origen[7], Figuras[4], 0*Lado, 2*Lado, 0*Lado, 7*Lado, Lado*1, Lado*1);
blit(Origen[7], Figuras[4], 16, 1*Lado, 1*Lado, 5*Lado, Lado*1, Lado*1);
blit(Origen[7], Figuras[4], 16, (1*Lado)+16, 1*Lado, 6*Lado, Lado*1, Lado*1);
blit(Origen[7], Figuras[4], 16, 2*Lado, 1*Lado, 7*Lado, Lado*1, Lado*1);
blit(Origen[7], Figuras[4], 1*Lado, 1*Lado, 2*Lado, 5*Lado, Lado*1, Lado*1);
blit(Origen[7], Figuras[4], 1*Lado, (1*Lado)+16, 2*Lado, 6*Lado, Lado*1, Lado*1);
blit(Origen[7], Figuras[4], 1*Lado, 2*Lado, 2*Lado, 7*Lado, Lado*1, Lado*1);

blit(Origen[7], Figuras[4], 16, (2*Lado)+17, 3*Lado, (7*Lado)+17, Lado*1, 15);
blit(Origen[0], Figuras[4], 0, 5*Lado, 4*Lado, 5*Lado, 4*Lado, 3*Lado);
blit(Origen[9], Figuras[4], 12*Lado, 2*Lado, 3*Lado, 5*Lado, 1*Lado, 2*Lado);
blit(Origen[8], Figuras[4], 32, 10, 5*Lado-8, 6*Lado-9, 2*Lado+15, 2*Lado+10);
blit(Origen[10], Figuras[4], 0, Lado, 8*Lado, 5*Lado, Lado, Lado);

//Camino
Figuras[5]=create_bitmap(Lado,Lado);
blit(Origen[1], Figuras[5], 0, 2*Lado, 0, 0, Lado, Lado);

//menu peleas
Figuras[6]=create_bitmap(18*Lado,5*Lado);
	for(int i=0; i<3;i++){
		for(int j=0; j<9;j++){
			blit(Origen[12], Figuras[6], 0, 2*Lado, j*2*Lado, i*2*Lado, 2*Lado, 2*Lado);
		}
	}

}

void Pintor::Casa(Mapa &lienzo, int posx, int posy, int E_E){
	lienzo.PintarEnMapa(Figuras[0], 0, 0, posx*Lado, posy*Lado, 7*Lado, 3*Lado, 4);			// 0000000
	lienzo.PintarEnMapa(Figuras[0], 0, 0, posx*Lado, posy*Lado, 1*Lado, 7*Lado, 4);			// 0000000
	lienzo.PintarEnMapa(Figuras[0], Lado, 3*Lado, (posx+1)*Lado, (posy+3)*Lado, 6*Lado, 4*Lado, 1);	// 0000000
	for(int i=0;i<4;i++){										// 0111111
		for(int j=0;j<6;j++){									// 0111111
		lienzo.ActualizarMapaMovimiento(posy+i+3, posx+j+1);					// 0111111
		}											// 0110111
	}										
	lienzo.ActualizarMapaMovimiento(posy+6, posx+3,0);
	lienzo.ActualizarMapaEventos(posy+6, posx+3, 1, 0, E_E);
}

//
void Pintor::Tienda(Mapa &lienzo, int posx, int posy, int tipo){
	lienzo.PintarEnMapa(Figuras[tipo+1], 0, 0, posx*Lado, posy*Lado, 4*Lado, 6*Lado, 4);	// 0000
	for(int i=0;i<4;i++){									// 0000
		for(int j=0;j<4;j++){								// 1111
		lienzo.ActualizarMapaMovimiento(posy+i+2, posx+j);				// 1111
		}										// 1111
	}											// 1111
												
}

void Pintor::Arbol(Mapa &lienzo, int posx, int posy){
	lienzo.PintarEnMapa(Figuras[3], 0, 0, posx*Lado, posy*Lado, 5*Lado, 5*Lado, 4);		// 00000
	lienzo.PintarEnMapa(Figuras[3], 0, 5*Lado, posx*Lado, (posy+5)*Lado, 5*Lado, 1*Lado, 1);// 00000
	lienzo.ActualizarMapaMovimiento(posy+5, posx+2);					// 00000
}												// 00000
												// 00000
												// 00100

void Pintor::Camino(Mapa &lienzo, int posx, int posy, int TamX, int TamY){
	for(int i=0;i<TamX;i++){
		for(int j=0;j<TamY;j++){
			lienzo.PintarEnMapa(Figuras[5], 0, 0, (posx+i)*Lado, (posy+j)*Lado, 1*Lado, 1*Lado, 0);		
		}	
	}
}

void Pintor::Fuente(Mapa &lienzo, int posx, int posy){
	lienzo.PintarEnMapa(Origen[11], 5*Lado+16, 13*Lado+16, posx*Lado, posy*Lado, 2*Lado, 2*Lado, 1);
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			lienzo.ActualizarMapaMovimiento(posy+j, posx+i);
		}
	}
}

void Pintor::Lampara(Mapa &lienzo, int posx, int posy){
	lienzo.PintarEnMapa(Origen[2], 2*Lado, 12*Lado, posx*Lado, posy*Lado, 1*Lado, 3*Lado, 4);
	lienzo.ActualizarMapaMovimiento(posy+2, posx);
}

void Pintor::BorInCa(Mapa &lienzo, int posx, int posy, int lonx, int lony, int E_E){
	lienzo.PintarEnMapa(Origen[2], 7*Lado, Lado+9, (posx*Lado)+22, (posy*Lado)+21, 10, 11, 4);
	lienzo.PintarEnMapa(Origen[2], 7*Lado, Lado+9, (posx*Lado)+22, (posy+lony+1)*Lado, 10, 11, 4);
	lienzo.PintarEnMapa(Origen[2], 7*Lado, Lado+9, (posx+lonx+1)*Lado, (posy*Lado)+21, 10, 11, 4);
	lienzo.PintarEnMapa(Origen[2], 7*Lado, Lado+9, (posx+lonx+1)*Lado, (posy+lony+1)*Lado, 10, 11, 4);
	for(int i=1;i<lonx+1;i++){
		lienzo.PintarEnMapa(Origen[2], 7*Lado, Lado+9, (posx+i)*Lado, (posy*Lado)+21, 1*Lado, 11, 4);

		if(!(i==((lonx/2)+1))){
		lienzo.PintarEnMapa(Origen[2], 7*Lado, Lado+9, (posx+i)*Lado, (posy+lony+1)*Lado, Lado, 11, 4);
		
			if(i==((lonx/2)+2))
			lienzo.PintarEnMapa(Origen[2], Lado, 8*Lado, (posx+i)*Lado, (posy+lony+1)*Lado, 10, 1*Lado, 4);
		}
		else{
		lienzo.PintarEnMapa(Origen[2], 0*Lado+22, 7*Lado, (posx+i-1)*Lado+22, (posy+lony+1)*Lado, 10, 1*Lado, 4);
		lienzo.PintarEnMapa(Origen[2], Lado, 8*Lado, (posx+i+1)*Lado, (posy+lony+1)*Lado, 10, 1*Lado, 4);	
		}
	
		lienzo.PintarEnMapa(Origen[2], 7*Lado, 4*Lado, (posx+i)*Lado, (posy+1)*Lado, Lado, Lado, 1);
		lienzo.PintarEnMapa(Origen[2], 7*Lado, 5*Lado, (posx+i)*Lado, (posy+2)*Lado, Lado, Lado, 1);
	}

	for(int i=1;i<lony+1;i++){
		lienzo.PintarEnMapa(Origen[2], 0*Lado+22, 7*Lado, posx*Lado+22, (posy+i)*Lado, 10, 1*Lado, 4);
		lienzo.PintarEnMapa(Origen[2], Lado, 8*Lado, (posx+lonx+1)*Lado, (posy+i)*Lado, 10, 1*Lado, 4);
	}
	
	for(int i=1;i<lonx+1;i++){
		for(int j=3;j<lony+1;j++){
			lienzo.PintarEnMapa(Origen[1], 0, 5*Lado, (posx+i)*Lado, (posy+j)*Lado, Lado, Lado, 0);
		}
	}
	
	for(int i=0;i<lonx+2;i++){
		for(int j=0;j<lony+2;j++){
			if(i==0)
			lienzo.ActualizarMapaMovimiento(posy+j, posx+i);
			else if((j>=0)&&(j<=1))
			lienzo.ActualizarMapaMovimiento(posy+j, posx+i);
			else if(i==(lonx+1))
			lienzo.ActualizarMapaMovimiento(posy+j, posx+i);
			else if((j==(lony+1))&&(i==((lonx+1)/2))){
			lienzo.ActualizarMapaMovimiento(posy+j, posx+i,0);
			lienzo.ActualizarMapaEventos(posy+j, posx+i,1, 0, E_E);
			
			}
			else if(j==(lony+1))
			lienzo.ActualizarMapaMovimiento(posy+j, posx+i);
		}	
	}
}

void Pintor::MenuCombate(void){
	blit(Figuras[6], screen, 0, 0, Lado/2 , 10*Lado, 18*Lado, (5*Lado)-16);
}

void Pintor::MenuCombateObjetos(void){
this->MenuCombate();
masked_blit(Origen[13], screen, 72, 144, 2*Lado, (11*Lado), 24, 24);
masked_blit(Origen[13], screen, 24, 144, 2*Lado, (11*Lado)+26, 24, 24);
masked_blit(Origen[13], screen, 72, 168, 2*Lado, (11*Lado)+52, 24, 24);
masked_blit(Origen[13], screen, 336, 336, 2*Lado, (11*Lado)+78, 24, 24);

}
void Pintor::GameOver(void){
	blit(Origen[16], screen, 0, 0, 0, 0, RX, RY);
	rest(2000);
}

void Pintor::Pueblo(Mapa &lienzo, int posx, int posy){
	lienzo.PintarEnMapa(Origen[14], 0, 8*Lado, posx*Lado, posy*Lado, Lado, Lado, 1);
	lienzo.PintarEnMapa(Origen[14], 0, 8*Lado, posx*Lado, (posy+1)*Lado, Lado, Lado, 1);
	lienzo.PintarEnMapa(Origen[14], 2*Lado, 16*Lado, (posx+1)*Lado, posy*Lado, 2*Lado, 2*Lado, 1);
	lienzo.PintarEnMapa(Origen[14], 0, 8*Lado, (posx+3)*Lado, posy*Lado, Lado, Lado, 1);
	lienzo.PintarEnMapa(Origen[14], 0, 8*Lado, (posx+3)*Lado, (posy+1)*Lado, Lado, Lado, 1);
}

void Pintor::Pueblo_Sin_Entrada(Mapa &lienzo, int posx, int posy, int tipo){
	if(tipo==0){
		lienzo.PintarEnMapa(Origen[14], 0, 10*Lado, posx*Lado, posy*Lado, 2*Lado, 2*Lado, 1);
	}
	else if(tipo==1){
		lienzo.PintarEnMapa(Origen[14], 2*Lado, 10*Lado, posx*Lado, posy*Lado, 2*Lado, 2*Lado, 1);
	}
	else if(tipo==2){
		lienzo.PintarEnMapa(Origen[14], 4*Lado, 10*Lado, posx*Lado, posy*Lado, 2*Lado, 2*Lado, 1);
	}
	else if(tipo==3){
		lienzo.PintarEnMapa(Origen[14], 0, 12*Lado, posx*Lado, posy*Lado, 2*Lado, 2*Lado, 1);
	}
	else if(tipo==4){
		lienzo.PintarEnMapa(Origen[14], 4*Lado, 12*Lado, posx*Lado, posy*Lado, 2*Lado, 2*Lado, 1);
	}
	else if(tipo==5){
		lienzo.PintarEnMapa(Origen[14], 4*Lado, 14*Lado, posx*Lado, posy*Lado, 2*Lado, 2*Lado, 1);
	}
	lienzo.ActualizarMapaMovimiento(posy, posx);
	lienzo.ActualizarMapaMovimiento(posy+1, posx);
	lienzo.ActualizarMapaMovimiento(posy, posx+1);
	lienzo.ActualizarMapaMovimiento(posy+1, posx+1);

}
void Pintor::Montana(Mapa &lienzo, int posx, int posy){
	lienzo.PintarEnMapa(Origen[14], 6*Lado, 13*Lado, posx*Lado, posy*Lado, 2*Lado, 3*Lado, 1);
	lienzo.ActualizarMapaMovimiento(posy, posx);
	lienzo.ActualizarMapaMovimiento(posy+1, posx);
	lienzo.ActualizarMapaMovimiento(posy, posx+1);
	lienzo.ActualizarMapaMovimiento(posy+1, posx+1);
}

void Pintor::Bosque(Mapa &lienzo, int posx, int posy){
	lienzo.PintarEnMapa(Origen[14], 0, 3*Lado, posx*Lado, posy*Lado, Lado, Lado, 1);
}

void Pintor::Bosque(Mapa &lienzo, int posx, int posy, int Tamx, int Tamy){
	for(int i=0;i<Tamx;i++){
		for(int j=0;j<Tamy;j++){
			lienzo.PintarEnMapa(Origen[14], 2*Lado, 3*Lado, (posx+i)*Lado, (posy+j)*Lado, Lado, Lado, 1);
		}
	}

}

void Pintor::Pequena_Construccion(Mapa &lienzo, int posx, int posy, int tipo){
	if(tipo==0){//molino
		lienzo.PintarEnMapa(Origen[14], 0, 9*Lado, posx*Lado, posy*Lado, Lado, Lado, 1);
	}
	else if(tipo==1){//pueblito 1
		lienzo.PintarEnMapa(Origen[14], Lado, 7*Lado, posx*Lado, posy*Lado, Lado, Lado, 1);
	}
	else if(tipo==2){//pueblito 2
		lienzo.PintarEnMapa(Origen[14], 7*Lado, 6*Lado, posx*Lado, posy*Lado, Lado, Lado, 1);
	}
	else if(tipo==3){//pueblito 3
		lienzo.PintarEnMapa(Origen[14], 0, 9*Lado, posx*Lado, posy*Lado, Lado, Lado, 1);
	}
	else if(tipo==4){//templo
		lienzo.PintarEnMapa(Origen[14], 7*Lado, 7*Lado, posx*Lado, posy*Lado, Lado, Lado, 1);
	}
	else if(tipo==5){//castillo
		lienzo.PintarEnMapa(Origen[14], 0, 4*Lado, posx*Lado, posy*Lado, Lado, Lado, 1);
	}
	else if(tipo==6){//faro
		lienzo.PintarEnMapa(Origen[14], 3*Lado, 4*Lado, posx*Lado, posy*Lado, Lado, Lado, 1);
	}
	else if(tipo==7){//torre 1
		lienzo.PintarEnMapa(Origen[14], 6*Lado, 2*Lado, posx*Lado, posy*Lado, Lado, Lado, 1);
	}
	else if(tipo==8){//torre 2
		lienzo.PintarEnMapa(Origen[14], 7*Lado, 2*Lado, posx*Lado, posy*Lado, Lado, Lado, 1);
	}
	lienzo.ActualizarMapaMovimiento(posy, posx);

}

void Pintor::Arbol_Exterior(Mapa &lienzo, int posx, int posy, int tipo){
	if(tipo==0){//palmera
		lienzo.PintarEnMapa(Origen[14], 6*Lado, 3*Lado, posx*Lado, posy*Lado, Lado, Lado, 1);
	}
	else if(tipo==1){//pino
		lienzo.PintarEnMapa(Origen[14], 0, 16*Lado, posx*Lado, posy*Lado, Lado, Lado, 1);
	}
	else if(tipo==2){//arbol verano
		lienzo.PintarEnMapa(Origen[14], Lado, 16*Lado, posx*Lado, posy*Lado, Lado, Lado, 1);
	}
	else if(tipo==3){//arbol otoño
		lienzo.PintarEnMapa(Origen[14], Lado, 17*Lado, posx*Lado, posy*Lado, Lado, Lado, 1);
	}
	lienzo.ActualizarMapaMovimiento(posy, posx);
}

void Pintor::Paredes_Rocosas(Mapa &lienzo, int posx, int posy, int cuantos){
	for(int i=0;i<cuantos;i++){
		lienzo.PintarEnMapa(Origen[7], (8*Lado)+16, 12*Lado, (posx+i)*Lado, posy*Lado, Lado, 3*Lado, 1);
		lienzo.ActualizarMapaMovimiento(posy+1, posx+i);
		lienzo.ActualizarMapaMovimiento(posy+2, posx+i);
	}

}

void Pintor::Escaleras(Mapa &lienzo, int posx, int posy, int cuantos){
	for(int i=0;i<cuantos;i++){
		lienzo.PintarEnMapa(Origen[1], 4*Lado, 10*Lado, (posx+i)*Lado, posy*Lado, Lado, Lado, 1);
		lienzo.PintarEnMapa(Origen[1], 4*Lado, 10*Lado, (posx+i)*Lado, (posy+1)*Lado, Lado, Lado, 1);
	}

}

void Pintor::Furnishing(Mapa &lienzo, int posx, int posy, int Tipo){
	if(Tipo==0){//cama doble
		lienzo.PintarEnMapa(Origen[15], Lado, 10*Lado, posx*Lado, posy*Lado, 2*Lado, 2*Lado, 1);
		lienzo.ActualizarMapaMovimiento(posy, posx);
		lienzo.ActualizarMapaMovimiento(posy, posx+1);
		lienzo.ActualizarMapaMovimiento(posy+1, posx);
		lienzo.ActualizarMapaMovimiento(posy+1, posx+1);
	}
	else if(Tipo==1){//ventana
		lienzo.PintarEnMapa(Origen[15], 0, 4*Lado, posx*Lado, posy*Lado, Lado, 2*Lado, 1);
	}
	else if(Tipo==2){//cuadro1
		lienzo.PintarEnMapa(Origen[15], 14*Lado, 4*Lado, posx*Lado, (posy*Lado)+(Lado/2), 2*Lado, Lado, 1);
	}
	else if(Tipo==3){//mapa
		lienzo.PintarEnMapa(Origen[15], 12*Lado, 4*Lado, posx*Lado, (posy*Lado)+(Lado/2), 2*Lado, Lado, 1);
	}
	else if(Tipo==4){//Espejo
		lienzo.PintarEnMapa(Origen[15], 9*Lado, 4*Lado, posx*Lado, posy*Lado, Lado, 2*Lado, 1);
	}
	else if(Tipo==5){//cocina
		lienzo.PintarEnMapa(Origen[15], 0, 14*Lado, posx*Lado, posy*Lado, 4*Lado, Lado, 1);
		for(int i=0;i<4;i++)
		lienzo.ActualizarMapaMovimiento(posy, posx+i);

	}
	else if(Tipo==6){//mesa1

	}
	else if(Tipo==7){

	}
	else if(Tipo==8){

	}
	else if(Tipo==9){

	}
	else if(Tipo==10){

	}
	else if(Tipo==11){

	}
	else if(Tipo==12){

	}
	else if(Tipo==13){

	}
	else if(Tipo==14){

	}
}

void Pintor::Academia(Mapa &lienzo, int posx, int posy){
	lienzo.PintarEnMapa(Figuras[4], 0, 0, posx*Lado, (posy+5)*Lado, 16*Lado, 2*Lado, 4);			// 1111111111111111
	lienzo.PintarEnMapa(Figuras[4], 0, 2*Lado, posx*Lado, (posy+7)*Lado, 1*Lado, 3*Lado, 4);		// 1000000000000001
	lienzo.PintarEnMapa(Figuras[4], 15*Lado, 2*Lado, (posx+15)*Lado, (posy+7)*Lado, 1*Lado, 3*Lado, 4);	// 1000000000000001
	int a=3;												// 1111111111111111
	for(int i=0;i<4;i++){											// 1000000000000001
	lienzo.PintarEnMapa(Figuras[4], 3*Lado, 3*Lado, (posx+a)*Lado, (posy+8)*Lado, 1*Lado, 1*Lado, 4);	// 1000000000000001
	a=a+3;													// 1111111111111111
	}													// 1111111111111111
	lienzo.PintarEnMapa(Figuras[4], 0, 2*Lado, posx*Lado, (posy+7)*Lado, 16*Lado, 3*Lado, 1);		// 1000000000000001
														// 1001001001001001
	a=1;												
	for(int i=0;i<5;i++){											
	lienzo.PintarEnMapa(Figuras[4], 16*Lado, 0*Lado, (posx+a)*Lado, (posy+6)*Lado, 2*Lado, 2*Lado, 1);	
	a=a+3;													
	}
	a=1;												
	for(int i=0;i<7;i++){											
	lienzo.PintarEnMapa(Figuras[4], 16*Lado, 0*Lado, (posx+a)*Lado, (posy+3)*Lado, 2*Lado, 2*Lado, 4);	
	a=a+2;													
	}
	lienzo.PintarEnMapa(Figuras[4], 16*Lado, 2*Lado, posx*Lado, (posy+3)*Lado, 1*Lado, 2*Lado, 4);
	lienzo.PintarEnMapa(Figuras[4], 17*Lado, 2*Lado, (posx+15)*Lado, (posy+3)*Lado, 1*Lado, 2*Lado, 4);
	lienzo.PintarEnMapa(Figuras[4], 0*Lado, 5*Lado, posx*Lado, posy*Lado, 1*Lado, 3*Lado, 1);
	lienzo.PintarEnMapa(Figuras[4], 2*Lado, 5*Lado, (posx+15)*Lado, posy*Lado, 1*Lado, 3*Lado, 1);
	a=1;												
	for(int i=0;i<14;i++){											
		lienzo.PintarEnMapa(Figuras[4], 1*Lado, 5*Lado, (posx+a)*Lado, posy*Lado, 1*Lado, 3*Lado, 1);
		lienzo.PintarEnMapa(Figuras[4], 1*Lado, (7*Lado)+17, (posx+a)*Lado, ((posy+2)*Lado)+17, 1*Lado, 17, 4);	
	a++;													
	}
	//ventanas
	a=1;
	for(int i=0;i<5;i++){
	lienzo.PintarEnMapa(Figuras[4], 3*Lado, 5*Lado, (posx+a)*Lado+16, (posy+3)*Lado, 1*Lado, 2*Lado, 4);
	lienzo.PintarEnMapa(Figuras[4], 3*Lado, 5*Lado, (posx+a)*Lado+16, (posy+6)*Lado, 1*Lado, 2*Lado, 1);
	a=a+3;
	}
	//puerta
	lienzo.PintarEnMapa(Figuras[4], 4*Lado, 5*Lado, (posx+6)*Lado, (posy+5)*Lado, 4*Lado, 3*Lado, 1);
	lienzo.PintarEnMapa(Figuras[4], 6*Lado, 2*Lado, (posx+6)*Lado, (posy+7)*Lado, 4*Lado, 1*Lado, 4);
	//Escaleras
	lienzo.PintarEnMapa(Figuras[4], 8*Lado, 5*Lado, (posx+14)*Lado, (posy+1)*Lado, Lado, Lado, 1);

	for(int i=0;i<10;i++){									
		for(int j=0;j<16;j++){
			if((i==3)||(i==6)||(i==7)){								
				lienzo.ActualizarMapaMovimiento(posy+i, posx+j);
			}
			else if((j==0)||(j==15)){								
				lienzo.ActualizarMapaMovimiento(posy+i, posx+j);
			}
			else if(i==9){
				if((j==3)||(j==6)||(j==9)||(j==12)){
					lienzo.ActualizarMapaMovimiento(posy+i, posx+j);
				}		
			}				
		}										
	}
	lienzo.ActualizarMapaMovimiento(posy+7, posx+7,0);
	lienzo.ActualizarMapaMovimiento(posy+7, posx+8,0);
}

