/**
 * @file   testmyRobot.c
 * @author Oscar Montes
 * @date   15 Noviembre 2015
 * @version 0.1
 * @brief  A Linux user space program that communicates with the ebbchar.c LKM. It passes a
 * string to the LKM and reads the response from the LKM. For this example to work the device
 * must be called /dev/ebbchar.
 * @see http://www.derekmolloy.ie/ for a full description and follow-up descriptions.
*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>

#define BUFFER_LENGTH 256               ///< The buffer length (crude but fine)
static char receive[BUFFER_LENGTH];     ///< The receive buffer from the LKM

int main(){
   int ret, fd;
   char stringToSend[BUFFER_LENGTH];
   printf("Prueba para probar dispositivo...\n");
   fd = open("/dev/myRobot0", O_RDWR);             // Open the device with read/write access
   if (fd < 0){
      perror("No pudo abir myRobot...");
      return errno;
   }
   printf("Digite un string para enviar al modulo del kernel:\n");
   scanf("%[^\n]%*c", stringToSend);                // Read in a string (with spaces)
   printf("Escribiendo el mensaje en el dispositivo: %s.\n", stringToSend);
   ret = write(fd, stringToSend, strlen(stringToSend)); // Send the string to the LKM
   if (ret < 0){
      perror("Fallo al escribir el mensaje en el dispositivo.");
      return errno;
   }

   printf("Fin del programa\n");
   return 0;
}
