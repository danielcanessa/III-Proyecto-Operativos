read -n1 -r -p "Press u to unMount or m to Mount " key

if [ "$key" = 'm' ]; then
    sudo rmmod cdc_acm
   
	sudo insmod Driver/USBDriver.ko
    
	sudo chown -R felipe /dev/RoboticFinger0
else
	
    sudo rmmod USBDriver
fi



