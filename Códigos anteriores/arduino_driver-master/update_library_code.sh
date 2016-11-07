#!/bin/bash
#gcc -c arduino_driver.c
#ar rs libarduinodriver.a arduino_driver.o
gcc -c -fpic arduino_driver.c
gcc -shared -o libarduinodriver.so arduino_driver.o
export LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH
