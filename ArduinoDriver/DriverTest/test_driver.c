#include "libarduinodriver.h"

/* To shorten example, not using argp */
int main ()
{
  arduino_start_com(); //Open the file of the Arduino
  arduino_send_message ("Hola"); //Send this message to the arduino
  return 0;
}
