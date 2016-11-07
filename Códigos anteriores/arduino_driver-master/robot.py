import json
from arduino_driver import *
import time
import getopt, sys

try:
	opts, args = getopt.getopt(sys.argv[1:], "c:v", ["conf", "conf="])
except getopt.GetoptError as err:
	# print help information and exit:
	print str(err) # will print something like "option -a not recognized"
	sys.exit(2)
output = None
verbose = False
for o, a in opts:
	if o in ("-c", "--conf"):
		config_file = a
	else:
		assert False, "unhandled option"

msg_character='g'
timeout= 5

if not config_file:
	print "Missing Conf File"
	sys.exit(2)

print "Using File %s" % (config_file)

print 'Setting up Driver'
arduino_start_com()
time.sleep(timeout)
print 'Calibrating...'
arduino_send_message('abcdefghijklmnop')
time.sleep(timeout)
with open(config_file, 'r') as f:
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