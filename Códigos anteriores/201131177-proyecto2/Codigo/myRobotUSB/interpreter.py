#!/usr/bin/env python

import ctypes
import ConfigParser
import os
import time

Lib = ctypes.cdll.LoadLibrary(os.getcwd()+'/myRobotLibrary.so')

config = ConfigParser.ConfigParser()
config.read("config.ini")
config.sections()

# dump entire config file
for section in config.sections():
    print (section)

    if(section == "CONF"):
        for option in config.options(section):
            #print (" ", option, "=", config.get(section, option))
            #print ("sendAction("+option+")")
            Lib.sendAction(option)
            time.sleep(0.10)
            var1 = ""
            maxS = int(config.get(section, option))
            for num in range(0,maxS):
                var1 += "a"
            ##print ("sendNum("+var1+")")
            Lib.sendNum(var1)
            time.sleep(0.10)
            
        Lib.sendAction("&")
        time.sleep(0.10)
    
    else:
        for option in config.options(section):
            #print (" ", option, "=", config.get(section, option))
            if(option == "action"):
                #print ("sendAction("+config.get(section, option)+")")
                Lib.sendAction(config.get(section, option))
                time.sleep(0.10)
            else:
                #print ("sendDir("+option+")")
                Lib.sendDir(option)
                time.sleep(0.10)
                #print ("sendMove("+config.get(section, option)+")")
                Lib.sendMove(config.get(section, option))
                time.sleep(0.10)
        Lib.sendAction("*")
        time.sleep(0.10)
