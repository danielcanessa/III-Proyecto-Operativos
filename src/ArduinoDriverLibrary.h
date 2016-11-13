#ifndef _ARDUINODRIVERLIBRARY_H_
#define _ARDUINODRIVERLIBRARY_H_

extern int send_message_to_arduino (char stringToSend[256]);
extern char* read_message_send_from_arduino ();

#endif