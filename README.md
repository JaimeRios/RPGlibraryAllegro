# RPGlibraryAllegro
A project for Library RPG with allegro.

0. update first before install all the needed packages

sudo apt-get update 

1. To install the very minimun to compile, do:

sudo apt-get install libgl1-mesa-dev libglu1-mesa-dev cmake build-essential make libxcursor-dev

sudo apt-get install -y cmake g++ freeglut3-dev libxcursor-dev libjpeg-dev libfreetype6-dev libgtk2.0-dev libasound2-dev libpulse-dev libopenal-dev libflac-dev libdumb1-dev libvorbis-dev libphysfs-dev

2. Install allegro:

2.1. Way 1

	- Download Allegro allegro5.2
	- Decompress
	- cd allegro5
	- mkdir build
	- cd build
	- cmake ..
	- make
	- sudo make install
	if you're able to compile but the executable complains about not finding some libraries, you'll need to create linksto them:
	- sudo ldconfig

2.2 Way 2 (terminal)

	- sudo add-apt-repository ppa:allegro/5.2
	- sudo apt-get update 
	- sudo apt-get install liballegro5-dev

3. Run and play	

	- cd ./RPGlibraryAllegro/src
	- g++  Eventos.cpp GestorMapas.cpp Main.cpp Mapa.cpp Menu.cpp Peleas.cpp Personaje.cpp Pintor.cpp  -o Juego `allegro-config --libs`
