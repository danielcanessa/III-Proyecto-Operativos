#include<stdio.h>
#include <unistd.h>
#include"deviceLibrary.h"

/*
  nextMove: 0 si es move, 1 si es touch, 2 si es push, 3 si es drag
*/
int processMoveDevice(int posIni, int posFin, int nextMove)
{
	printf("-> Device response new move processed: -i %d -f %d -t %d\n",posIni,posFin,nextMove);  
	//aqui va la logica de comunicacion con el device driver write
	//cuando termina tiene que hacer un read y retornar 1 si todo salió bien y 0 si palmo
	return 1; 
}

/*
 size board: 1 si es 1x1, 2 si es 2x2, 3 si es 4x4
*/
int processBoardDevice(int sizeBoard)
{
	printf("-> Device response new board processed: -b %d\n",sizeBoard);   
	//aqui va la logica de comunicacion con el device driver write
	//cuando termina tiene que hacer un read y retornar 1 si todo salió bien y 0 si palmo
	return 1; 
}
