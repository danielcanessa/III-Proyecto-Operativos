#!/bin/bash
gcc --static -I$PWD -L$PWD -o arduino_driver arduino_driver.c -larduinodriver
