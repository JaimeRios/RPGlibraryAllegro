//Clase Pintor.cpp para el proyecto final
// Copyright Jaime Alberto Rios Palacio (J.shuin)
// Electronic engineering student
// version 0.1 4 Enero 2013 15:48

#include "Definiciones.h"
#include "GestorMapas.h" 
#include "Mapa.h"
#include <allegro.h>


GestorMapas::GestorMapas(Mapa *ApunMap){
	MapaApun=ApunMap;
	Personaje=load_bitmap("../personajes/Joshua_caminando.tga", NULL);
	BufferFinal = create_bitmap(RX, RY);
	sourceX = 32;
	sourceY = 96;
	speed=8;
	movab=false;
	movar=false;
	movder=false;
	moviz=false;
	pvarriba=true;
	pvabajo=true;
	pvderecha=true;
	pvizquierda=true;
	ColumnaActual=1;
	FilaActual=1;
	x=0*Lado;
	y=0*Lado;
	xv=26*Lado;
	yv=26*Lado;
	Px=0;
	Py=0;
}

void GestorMapas::CambioMapa(Mapa *Mapa_Apuntador, bool ON){
	BITMAP *Origen = load_bitmap("../pueblo/pueblo1.tga", NULL);	
	for(int i=0;i<(RX/Lado);i++){
		for(int j=0;j<RY;j++){
		blit(Origen, screen, 0, 0, (0+j)*Lado, (0+i)*Lado, Lado, Lado);
		}
		rest(15);
	}
	if(ON)
	MapaApun->PararMusica();
	MapaApun=Mapa_Apuntador;
	if(ON)
	MapaApun->TocarMusica();
	MapaApun->mapmov();
}

//sirve para saber que pintar dependiendo de la posicion del personaje
void GestorMapas::Posicion(void){

	if((MapaApun->GetTamX())<RX){
	Px=0;
	}
	else{	
		if(x<(RX/2)){
			Px=0;
			xv=x;
		}
		else if(x>((MapaApun->GetTamX())-(RX/2))){
			Px=(MapaApun->GetTamX())-(RX);
			xv=(RX/2)+(x-((MapaApun->GetTamX())-(RX/2)));;
		}
		else{
			Px=x-(RX/2);
			xv=RX/2;
		}
	}

	if((MapaApun->GetTamY())<RY){
	Py=0;
	}
	else{	
		if(y<(RY/2)){
			Py=0;
			yv=y;
		}
		else if(y>((MapaApun->GetTamY())-(RY/2))){
			Py=(MapaApun->GetTamY())-(RY);
			yv=(RY/2)+(y-((MapaApun->GetTamY())-(RY/2)));
		}
		else{
			Py=y-((RY/2));
			yv=RY/2;
		}
	}
}

void GestorMapas::Evento(bool &Hay, int &Tipo, int &Especifico){
	MapaApun->RadarEventos(Hay, Tipo, Especifico, FilaActual-1, ColumnaActual-1);	
}

void GestorMapas::ActualizarMov(int Col, int Fil){
FilaActual=Fil;
ColumnaActual=Col;
x=(Col-1)*Lado;
y=(Fil-1)*Lado;
Px=(Col-1)*Lado;
Py=(Fil-1)*Lado;
}

//Para mover al personaje
void GestorMapas::Moverse(bool &PELEE){
		MapaApun->RadarMov(pvarriba, pvabajo, pvderecha, pvizquierda, FilaActual, ColumnaActual);
		
		if(key[KEY_UP])
		{
			if(pvarriba)
			{
			y -= speed;
			sourceY = Up;
			sourceX=64;
			movar=true;
			MapaApun->Decrementar(PELEE);//Si se presiono una tecla el debe disminuir para proxima pelea
			}
			else{sourceY=Up;sourceX=32;}
		}
		else if(key[KEY_DOWN])
		{
			if(pvabajo){
			y += speed; 
			sourceY = Down;
			sourceX=64;
			movab=true;
			MapaApun->Decrementar(PELEE);//Si se presiono una tecla el debe disminuir para proxima pelea
			}
			else{sourceY=Down;sourceX=32;}
		}
		else if(key[KEY_RIGHT])
		{
			if(pvderecha){
			x += speed; 
			sourceY = Right;
			sourceX=64;
			movder=true;
			MapaApun->Decrementar(PELEE);//Si se presiono una tecla el debe disminuir para proxima pelea
			}
			else{sourceY=Right;sourceX=32;}
		}
		else if(key[KEY_LEFT])
		{
			if(pvizquierda){
			x -= speed;
			sourceY = Left;
			sourceX=64;
			moviz=true;
			MapaApun->Decrementar(PELEE);//Si se presiono una tecla el debe disminuir para proxima pelea
			}
			else{sourceY=Left;sourceX=32;}
		}
		
		if(!key[KEY_RIGHT] && !key[KEY_LEFT] && !key[KEY_UP] && !key[KEY_DOWN])
			sourceX = 32;

	clear_bitmap(BufferFinal);
//pinta 1/4
	this->Posicion();	
	MapaApun->Pintarmapa(BufferFinal,0,Px,Py);
	MapaApun->Pintarmapa(BufferFinal,1,Px,Py);
	masked_blit(Personaje, BufferFinal, sourceX, sourceY, xv, yv, 32, 32);
	MapaApun->Pintarmapa(BufferFinal,4,Px,Py);
	masked_blit(BufferFinal, screen, 0, 0, 0, 0, RX, RY);
	
	rest(velocidad); 
	clear_bitmap(BufferFinal);

		if(movar){//coordenadas del 2
		y -= speed;
		sourceX=0;
		}
		else if(movab)
		{
			y += speed;
		sourceX=0;
		}
		else if(movder)
		{
			x += speed;
		sourceX=0; 
		}
		else if(moviz)
		{
			x -= speed;
		sourceX=0;
		}		

//pinta 2/4
	this->Posicion();	
	MapaApun->Pintarmapa(BufferFinal,0,Px,Py);
	MapaApun->Pintarmapa(BufferFinal,1,Px,Py);
	masked_blit(Personaje, BufferFinal, sourceX, sourceY, xv, yv, 32, 32);
	MapaApun->Pintarmapa(BufferFinal,4,Px,Py);
	masked_blit(BufferFinal, screen, 0, 0, 0, 0, RX, RY);
	
	rest(velocidad); 
	clear_bitmap(BufferFinal);

		if(movar){//coordenadas del 3
		y -= speed;
		sourceX=64;
		}
		else if(movab)
		{
			y += speed;
		sourceX=64; 
		}
		else if(movder)
		{
			x += speed;
		sourceX=64; 
		}
		else if(moviz)
		{
			x -= speed;
		sourceX=64;
		}		
//pinta 3/4	
	this->Posicion();
	MapaApun->Pintarmapa(BufferFinal,0,Px,Py);
	MapaApun->Pintarmapa(BufferFinal,1,Px,Py);
	masked_blit(Personaje, BufferFinal, sourceX, sourceY, xv, yv, 32, 32);
	MapaApun->Pintarmapa(BufferFinal,4,Px,Py);
	masked_blit(BufferFinal, screen, 0, 0, 0, 0, RX, RY);
	
	rest(velocidad); 
	clear_bitmap(BufferFinal);

		if(movar){//cordenadas del 4
		movar=false;
		y -= speed;
		sourceX=32;
		FilaActual--;	
		}
		else if(movab)
		{
			y += speed; 
			movab=false;
		sourceX=32;
		FilaActual++;
		}
		else if(movder)
		{
			x += speed; 
			movder=false;
		sourceX=32;
		ColumnaActual++;
		}
		else if(moviz)
		{
			x -= speed;
			moviz=false;
		sourceX=32;
		ColumnaActual--;
		}

//pinta 4/4	
	this->Posicion();
	MapaApun->Pintarmapa(BufferFinal,0,Px,Py);
	MapaApun->Pintarmapa(BufferFinal,1,Px,Py);
	masked_blit(Personaje, BufferFinal, sourceX, sourceY, xv, yv, 32, 32);
	MapaApun->Pintarmapa(BufferFinal,4,Px,Py);
	masked_blit(BufferFinal, screen, 0, 0, 0, 0, RX, RY);
	
	rest(velocidad); 
	clear_bitmap(BufferFinal);

}

void GestorMapas::Parar_Musica(void){
	MapaApun->PararMusica();
}

void GestorMapas::Reproducir_Musica(void){
	MapaApun->TocarMusica();
}
