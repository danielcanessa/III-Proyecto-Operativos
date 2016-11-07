#!/usr/bin/env python

import ctypes
import os
import time

my_test_lib = ctypes.cdll.LoadLibrary(os.getcwd()+"/myRobotLibrary.so")
#my_test_lib.sendDir("up");
#my_test_lib.sendDir("down");
#my_test_lib.sendDir("right");
#my_test_lib.sendDir("left");

#time.sleep(0.10)    
#my_test_lib.sendMove("1");
#time.sleep(0.10)    
#my_test_lib.sendDir("up");
#time.sleep(0.10)    
#my_test_lib.sendMove("2");
#my_test_lib.sendMove("3");
    
#my_test_lib.sendAction("press");
#my_test_lib.sendAction("over");
#my_test_lib.sendAction("click");
#time.sleep(0.010)
#my_test_lib.sendAction("*");


#my_test_lib.sendNum("aaaaaaaaaaaaaaaaaaaaaaaaaaaaa");


def writeNum(maxS):
	var1 = ""
	for num in range(0,maxS):
		var1 += "a"
	Lib.sendNum(var1)
	time.sleep(0.10)
    return

#my_test_lib.sendAction("&");
#time.sleep(0.10)  
my_test_lib.sendAction("x_conf");
time.sleep(0.10)  
writeNum(26)
my_test_lib.sendAction("y_conf");
time.sleep(0.10)  
writeNum(29)
my_test_lib.sendAction("z_conf");
time.sleep(0.10) 
writeNum(18)

my_test_lib.sendAction("x_conf");
time.sleep(0.10) 
my_test_lib.sendAction("x_conf");
time.sleep(0.10) 
my_test_lib.sendAction("x_conf");
time.sleep(0.10) 



