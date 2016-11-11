#include<stdio.h>
#include <unistd.h>
#include"deviceLibrary.h"


int processMoveDevice(int posIni, int posFin, int nextMove)
{
	printf("-> Device response new move processed: -i %d -f %d -t %d\n",posIni,posFin,nextMove);  
	sleep(3);
	return 1; 
}

int processBoardDevice(int sizeBoard)
{
	printf("-> Device response new board processed: -b %d\n",sizeBoard);   
	sleep(3);
	return 1; 
}
