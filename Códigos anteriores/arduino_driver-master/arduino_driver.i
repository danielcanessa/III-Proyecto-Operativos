/* example.i */
%module arduino_driver
%{
/* Put header files here or function declarations like below */
extern int arduino_send_message (char stringToSend[256]);
extern int arduino_start_com();
%}
extern int arduino_send_message (char stringToSend[256]);
extern int arduino_start_com();
