#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include "ArduinoDriverLibrary.h"

#define BUFFER_LENGTH 256  //The buffer length

int ret, fd;   
ssize_t rd; //This is going to have the read message send from the arduino
char stringReceived[BUFFER_LENGTH]; //Buffer of the message received

/*
This function is going to send a message to the arduino file
*/
int send_message_to_arduino (char stringToSend[BUFFER_LENGTH])
{
	fd = open("/dev/RoboticFinger0", O_RDWR);
	printf("Writing message to the device [%s].\n", stringToSend);
	ret = write(fd, stringToSend, strlen(stringToSend));
	if (ret < 0){
		perror("Failed to write the message to the device.");
		return errno;
	}
	close(fd);
	return 0;
}


/*
This function is going to read a message send from the arduino 
*/
char* read_message_send_from_arduino()
{
	fd = open("/dev/RoboticFinger0", O_RDWR);
	printf("Reading message send from the Arduino.\n");
	rd = read(fd,stringReceived,50);
	while(rd = read(fd,stringReceived,50)){
		if(strcmp(stringReceived, "L") == 0){
			break;
		}
	}
	close(fd);
	printf("The message received from the Arduino is: [%s].\n", stringReceived);
	return stringReceived;
}

