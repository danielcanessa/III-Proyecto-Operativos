#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>

#define BUFFER_LENGTH 256 ///< The buffer length (crude but fine)
int fd;

int writeRobot(char *string){
   int ret;
   ret = write(fd, string, strlen(string)); // Send the string to the LKM
   if (ret < 0){
      printf("Fallo al escribir el mensaje en el dispositivo.");
      return 0;
   }
   //close(fd);
   return 1;
	
}

int openDevice(){
	//printf("Prueba para probar dispositivo...\n");
    fd = open("/dev/myRobot1", O_RDWR); 
    if (fd < 0) {
		printf("No pudo abrir el dispositivo...\n");
    }
    //printf("Si lo abre...\n");
    return 1;
}

int sendDir(char *dir) {
	openDevice();
    char *stringToSend;
    printf("me llego un: %c\n",dir[0]);
    switch (dir[0]){
        case 'u'://UP
            stringToSend="a";
            break;
        case 'd'://DOWN
            stringToSend="aa";
            break;
        case 'r'://RIGHT
            stringToSend="aaa";
            break;
        case 'l'://LEFT
            stringToSend="aaaa";
            break;
        default:
            //close(fd);
            return 0;
    }
    printf("Envio direccion: %s\n", stringToSend);
    writeRobot(stringToSend);
    //close(fd);
    return 1;

}

int sendMove(char *dir) {
	//openDevice();
    char *stringToSend;
    switch (dir[0]){
        case '1'://ONE
            stringToSend="a";
            break;
        case '2'://TWO
            stringToSend="aa";
            break;
        case '3'://THREE
            stringToSend="aaa";
            break;
        default:
            close(fd);
            return 0;
    }
    printf("Envio movimientos %s\n", stringToSend);
    writeRobot(stringToSend);
    //close(fd);
    return 1;

}

int sendNum(char *stringToSend) {
	openDevice();
    printf("Envio num %s\n", stringToSend);
    writeRobot(stringToSend);
    //close(fd);
    return 1;

}

int sendAction(char *dir) {
	openDevice();
    char *stringToSend;
    switch (dir[0]){
        case 'p'://PRESIONAR
            stringToSend="aaaaa";
            break;
        case 'o'://SUBIR
            stringToSend="aaaaaa";
            break;
        case 'c'://CLICK
            stringToSend="aaaaaaa";
            break;
        case '*'://FIN MOVIMIENTO
            stringToSend="aaaaaaaa";
            break;
        case '&'://FIN NUMERO
            stringToSend="aaaaaaaaa";
            break;
        case 'x'://CONF X
            stringToSend="aaaaaaaaaa";
            break;
        case 'y'://CONF Y
            stringToSend="aaaaaaaaaaa";
            break;
        case 'z'://CONF Z
            stringToSend="aaaaaaaaaaaa";
            break;
        case 'm'://MANTENER
            stringToSend="aaaaaaaaaaaaa";
            break;
        default:
      //      close(fd);
            return 0;
    }
    printf("Envio accion %s\n", stringToSend);
    writeRobot(stringToSend);
    //close(fd);
    return 1;

}



/*int main(int argc, char** argv) {

  
    sendDir("up");
    sendDir("down");
    sendDir("right");
    sendDir("left");
    
    sendMove("1");
    sendMove("2");
    sendMove("3");
    
    sendAction("press");
    sendAction("over");
    sendAction("click");
    sendAction("*");

    return (EXIT_SUCCESS);
}*/
