//Clase Mapa.cpp para el proyecto final
// Copyright Jaime Alberto Rios Palacio (J.shuin)
// Electronic engineering student
// version 0.1 23 Diciembre 2012 15:42

#include "Definiciones.h" 
#include "Mapa.h"
#include <allegro.h>

Mapa::Mapa(int Filas, int Columnas,  const char *filename, BITMAP *Suelo, int px, int py){
	//Todos los mapas empiezan siendo sin peleas
	Con_Peleas=false;
	Numero_Peleas=0;
	Contador_Peleas=0;
	//asigna tamaño de las capas
	fil=Filas;
	col=Columnas;
	for(int i=0;i<5;i++){
		Capas[i]=create_bitmap(Lado*Columnas,Lado*Filas);
	}
	//asigna la musica principal
	Musica=load_sample(filename);
	//asigna tamaño de obstaculos
	Mov = new int*[Filas+2];
	for (int i=0; i<Filas+2; i++)
	{
		Mov[i] = new int[Columnas+2];
 	}
	//inicializa los extremos para que el personaje no se salga del mapa
	//111111111
	//1       1  Ejemplo de un mapa de 4x7 
	//1       1
	//1       1
	//1       1
	//111111111	
	for(int i=0;i<Filas+2;i++){
		for(int j=0;j<Columnas+2;j++){
			if(i==0)
			Mov[i][j]=1;
			else if(i==Filas+1)
			Mov[i][j]=1;
			else if(j==0)
			Mov[i][j]=1;
			else if(j==Columnas+1)
			Mov[i][j]=1;
			else
			Mov[i][j]=0;
		}	
	}
	
	//Asigna matrix de eventos 0 = no hay evento, 1 = hay evento
	Eventos = new bool*[Filas];
	for (int i=0; i<Filas; i++)
	{
		Eventos[i] = new bool[Columnas];
 	}

	for(int i=0;i<Filas;i++){
		for(int j=0;j<Columnas;j++){
			Eventos[i][j]=false;
		}
	}

	//Asigna matrix de los eventos con numeros enteros que identifican el tipo de evento
	TipoEvento = new int*[Filas];
	for (int i=0; i<Filas; i++)
	{
		TipoEvento[i] = new int[Columnas];
 	}

	//Asigna matrix de los eventos especificos con numeros enteros que identifican el evento especifico
	Especifico = new int*[Filas];
	for (int i=0; i<Filas; i++)
	{
		Especifico[i] = new int[Columnas];
 	}

	BITMAP *Origen = load_bitmap("../paisajes/paisajesE.tga", NULL);

	
	for(int i=0;i<5;i++){
		for(int j=0;j<Filas;j++){
			for(int k=0;k<Columnas;k++){
				if(i==0)
				blit(Suelo, Capas[i], px, py, k*Lado, j*Lado, Lado, Lado);
				else
				blit(Origen, Capas[i], 0, 32, k*Lado, j*Lado, Lado, Lado);

			}
		}	
	}
}

Mapa::~Mapa(){
	for(int i=0;i<fil+2;i++){
		delete Mov[i];
	}
	delete Mov;

	for(int i=0;i<fil;i++){
		delete Eventos[i];
	}
	delete Eventos;

	for(int i=0;i<fil;i++){
		delete TipoEvento[i];
	}
	delete TipoEvento;

	for(int i=0;i<fil;i++){
		delete Especifico[i];
	}
	delete Especifico;
}

void Mapa::TocarMusica(void){
	try{
		if(Musica!=nullptr)
		play_sample(Musica, 255, 127, 1000, true);
	}catch(int e){
	
	}
}

void Mapa::PararMusica(void){
	stop_sample(Musica);
}

void Mapa::Pintarmapa(BITMAP *Destino){
	masked_blit(Capas[0], Destino, 0, 0, 0, 0, Lado*col, Lado*fil);
	masked_blit(Capas[1], Destino, 0, 0, 0, 0, Lado*col, Lado*fil);
	masked_blit(Capas[2], Destino, 0, 0, 0, 0, Lado*col, Lado*fil);
	masked_blit(Capas[3], Destino, 0, 0, 0, 0, Lado*col, Lado*fil);
	masked_blit(Capas[4], Destino, 0, 0, 0, 0, Lado*col, Lado*fil);
}

void Mapa::Pintarmapa(BITMAP *Destino, int capa, int x, int y){
masked_blit(Capas[capa], Destino, x, y, 0, 0, Lado*col, Lado*fil);
}

//pintar objetos en el mapa, sera llamada generalmente por el objeto de la clase Pintor
void Mapa::PintarEnMapa(BITMAP *Origen, int d_x, int d_y, int e_x, int e_y, int t_x, int t_y, int capa){
	masked_blit(Origen, Capas[capa], d_x, d_y, e_x, e_y, t_x, t_y);
}

//Funcion que asiste cuando se pinta un objeto para saber en que posiciones puede moverse el personaje
void Mapa::ActualizarMapaMovimiento(int F, int C, int valor){
	Mov[F+1][C+1]=valor;
}

void Mapa::ActualizarMapaEventos(int F, int C, bool valor, int TE, int TEE){
	Eventos[F][C]=valor;
	TipoEvento[F][C]=TE;
	Especifico[F][C]=TEE;
}

void Mapa::RadarEventos(bool &Hay, int &Tipo, int &Espe, int y, int x){
Hay=Eventos[y][x];
Tipo=TipoEvento[y][x];
Espe=Especifico[y][x];
}


void Mapa::RadarMov(bool &Arriba, bool &Abajo, bool &Derecha, bool &Izquierda, int y, int x){
//detectar donde se puede mover
		if(Mov[y-1][x]==1)
		Arriba=false;
		else
		Arriba=true;

		if(Mov[y+1][x]==1)
		Abajo=false;
		else
		Abajo=true;

		if(Mov[y][x+1]==1)
		Derecha=false;
		else
		Derecha=true;

		if(Mov[y][x-1]==1)
		Izquierda=false;
		else
		Izquierda=true;

}

int Mapa::GetTamX(void){
	return (col*32);
}

int Mapa::GetTamY(void){
	return (fil*32);
}

void Mapa::mapmov(void){
	cout<<endl;
	for(int i=0;i<fil+2;i++){
		for(int j=0;j<col+2;j++){
			cout<<Mov[i][j];
		}
		cout<<endl;
	}	
}

void Mapa::Activa_Modo_Pelea(int Pasos){ 
	Con_Peleas=true;
	Numero_Peleas=Pasos;
	Contador_Peleas=Pasos;
}

void Mapa::Desactiva_Modo_Pelea(void){
	Con_Peleas=false;
	Numero_Peleas=0;
	Contador_Peleas=0;
}

void Mapa::Decrementar(bool &Pelee){
	if(Con_Peleas){
		Contador_Peleas--;
		if(Contador_Peleas==0){
			Contador_Peleas=Numero_Peleas;
			Pelee=true;
		}
		else{Pelee=false;}
	}
}
