import json
from arduino_driver import *
import time

msg_character='g'
timeout= 5

print 'Setting up Driver'
arduino_start_com()
time.sleep(timeout)
print 'Calibrating...'
arduino_send_message('abcdefghijklmnop')
time.sleep(timeout)
with open('robot_lang.ro', 'r') as f:
	read_data = json.load(f)
f.closed

print "Loaded:\n"
print read_data

for move in read_data["movements"]:
	print "Move"
	if not 'X' in move :
		move["X"] = 0
			
	print "X:%s" % move["X"]
	arduino_send_message((msg_character)*(move["X"]+2))
	time.sleep(timeout)
	if not 'Y' in move :
                move["Y"] = 0
        print "Y:%s" % move["Y"]
	arduino_send_message((msg_character)*(move["Y"]+2))
	time.sleep(timeout)        
	if not 'DRAG' in move :
                move["DRAG"] = 0
        print "DRAG:%s" % move["DRAG"]
	arduino_send_message((msg_character)*(move["DRAG"]+2))
	time.sleep(timeout)	
	arduino_send_message((msg_character)*(move["DRAG"]+2))
	time.sleep(timeout)
print 'Done\n'    

