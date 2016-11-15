#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "deviceLibrary.h"
#include "ArduinoDriverLibrary.h"

#define BUFFER_LENGTH 256

/*
  processMoveDevice: this method call the device driver, it sends nextMove: 1 if the move is touch, 2 if the move is push, 3 if the move is drag, posFin and posIni a number in the range 0-9
*/
int processMoveDevice(int posIni, int posFin, int nextMove)
{
	printf("-> Device response new move processed: -i %d -f %d -t %d\n",posIni,posFin,nextMove);
	char initialPosition[20];  
	char finalPosition[20];
	char nextMovement[20];
	char* messageFromArduino;
	
	sprintf(initialPosition, "%d",posIni);
	sprintf(finalPosition, "%d",posFin);
	sprintf(nextMovement, "%d",nextMove);

	char coma1[16];
    char coma2[16];
    strcpy(coma1, ",");
    strcpy(coma2, ",");
    strcat(initialPosition, coma1);
    strcat(initialPosition, finalPosition);
    strcat(initialPosition, coma2);
    strcat(initialPosition, nextMovement);

	//aqui va la logica de comunicacion con el device driver write
	send_message_to_arduino (initialPosition); //Send this message to the arduino
    
	while(strcmp(read_message_send_from_arduino(), "L") != 0){

	}

    //cuando termina tiene que hacer un read y retornar 1 si todo salió bien y 0 si palmo
    messageFromArduino = read_message_send_from_arduino(); //Read the message send from the arduino

    if(strcmp(messageFromArduino, "L") == 0){
    	printf("Todo salio bien\n");
    	return 1; 
    }
    else{
    	printf("Hubo un error\n");
    	return 0; 
    }

	
}

/*
  processBoardDevice: this method call the device driver, it sends size board: 1 if the board is 1x1, 2 if the board is 2x2, 3 if the board is 4x4
*/
int processBoardDevice(int sizeBoard)
{
	char boardSize[20];
	char boardType[16];
	char* messageFromArduino;

	sprintf(boardSize, "%d",sizeBoard);
	strcpy(boardType, "Board:");
	strcat(boardType, boardSize);

	printf("-> Device response new board processed: -b %d\n",sizeBoard);   
	//aqui va la logica de comunicacion con el device driver write

	send_message_to_arduino (boardType); //Send this message to the arduino

	//cuando termina tiene que hacer un read y retornar 1 si todo salió bien y 0 si palmo
	messageFromArduino = read_message_send_from_arduino(); //Read the message send from the arduino
	if(strcmp(messageFromArduino, "L") == 0){
    	printf("Todo salio bien\n");
    	return 1; 
    }
    else{
    	printf("Hubo un error\n");
    	return 0; 
    }

	
}
