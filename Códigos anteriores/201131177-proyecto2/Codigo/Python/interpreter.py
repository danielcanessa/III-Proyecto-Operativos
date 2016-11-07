#!/usr/bin/env python

import ctypes
import configparser
import os

Lib = ctypes.cdll.LoadLibrary(os.getcwd()+'/myRobotLibrary.so')

config = configparser.ConfigParser()
config.read("languaje.ini")
config.sections()

# dump entire config file
for section in config.sections():
    print (section)

    if(section == "CONF"):
        for option in config.options(section):
            #print (" ", option, "=", config.get(section, option))
            #print ("sendAction("+option+")")
            Lib.sendAction(option);
            var1 = ""
            maxS = int(config.get(section, option))
            for num in range(0,maxS):
                var1 += "a"
            ##print ("sendNum("+var1+")")
            Lib.sendNum(var1);
            
        Lib.sendAction("&");
    
    else:
        for option in config.options(section):
            #print (" ", option, "=", config.get(section, option))
            if(option == "action"):
                #print ("sendAction("+config.get(section, option)+")")
                Lib.sendAction(config.get(section, option));
            else:
                #print ("sendDir("+option+")")
                Lib.sendDir(option);
                #print ("sendMove("+config.get(section, option)+")")
                Lib.sendMove(config.get(section, option));
                
        Lib.sendAction("*");
