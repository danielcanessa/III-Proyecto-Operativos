#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_LENGTH 256               ///< The buffer length (crude but fine)

int ret, fd;
//char stringToSend[BUFFER_LENGTH];

/*
This function is going to send a message to the arduino file
*/
int arduino_send_message (char stringToSend[BUFFER_LENGTH])
{
	printf("Writing message to the device [%s].\n", stringToSend);
	//ret = write(fd, "\"Hola\"", strlen(stringToSend)); // Send the string to the LKM
	ret = write(fd, stringToSend, strlen(stringToSend));
	if (ret < 0){
		perror("Failed to write the message to the device.");
		return errno;
	}
	return 0;
}

/*
This function is going to initialize the connection
*/
int arduino_start_com(){
	printf("Starting device test code example...\n");
	fd = open("/dev/pen0", O_RDWR);             // Open the device with read/write access
	if (fd < 0){
      perror("Failed to open the device...");
      return errno;
   }
   printf("Done device test code example...\n");
   return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           