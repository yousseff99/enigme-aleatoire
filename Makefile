
game:main.o aleatoire.o
	gcc main.o aleatoire.o -o game  -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g 
main.o:main.c
	gcc main.c -c  -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
aleatoire.o:aleatoire.c
	gcc aleatoire.c -c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
