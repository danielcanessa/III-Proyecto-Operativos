#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>

#define MIN(a,b) (((a) <= (b)) ? (a) : (b))
#define BULK_EP_OUT 0x04
#define BULK_EP_IN 0x83
#define MAX_PKT_SIZE 64



MODULE_LICENSE("GPL");            ///< The license type -- this affects available functionality
MODULE_AUTHOR("Oscar Montes");    ///< The author -- visible when you use modinfo
MODULE_DESCRIPTION("A simple usb driver para myRobot");  ///< The description -- see modinfo
MODULE_VERSION("0.1");            ///< A version number to inform users


static struct usb_device *device; /// Container device handle
static struct usb_class_driver class;
static unsigned char bulk_buf[MAX_PKT_SIZE];

static int pen_open(struct inode *i, struct file *f)
{
    return 0;
}
static int pen_close(struct inode *i, struct file *f)
{
    return 0;
}
static ssize_t pen_read(struct file *f, char __user *buf, size_t cnt, loff_t *off)
{
    int retval;
    int read_cnt;
 
    /* Read the data from the bulk endpoint */
    retval = usb_bulk_msg(device, usb_rcvbulkpipe(device, BULK_EP_IN),
            bulk_buf, MAX_PKT_SIZE, &read_cnt, 5000);
    if (retval)
    {
        printk(KERN_ERR "Bulk message returned %d\n", retval);
        return retval;
    }
    if (copy_to_user(buf, bulk_buf, MIN(cnt, read_cnt)))
    {
        return -EFAULT;
    }
    
    
    return MIN(cnt, read_cnt);
}
static ssize_t pen_write(struct file *f, const char __user *buf, size_t cnt, loff_t *off)
{
    int retval;
    int wrote_cnt = MIN(cnt, MAX_PKT_SIZE);
 
    if (copy_from_user(bulk_buf, buf, MIN(cnt, MAX_PKT_SIZE)))
    {
		printk(KERN_INFO "Escritura InCorrecta\n");
        return -EFAULT;
    }
 
    /* Write the data into the bulk endpoint */
    retval = usb_bulk_msg(device, usb_sndbulkpipe(device, BULK_EP_OUT),
            bulk_buf, MIN(cnt, MAX_PKT_SIZE), &wrote_cnt, 5000);
    if (retval)
    {
        printk(KERN_ERR "Bulk message returned %d\n", retval);
        return retval;
    }
    
 
    return wrote_cnt;
}
 
static struct file_operations fops =
{
    .open = pen_open,
    .release = pen_close,
    .read = pen_read,
    .write = pen_write,
};

 
static int pen_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
    int retval;
 
    device = interface_to_usbdev(interface);
 
    class.name = "usb/myRobot%d";
    class.fops = &fops;
    if ((retval = usb_register_dev(interface, &class)) < 0)
    {
        /* Something prevented us from registering this driver */
        printk(KERN_INFO "Not able to get a minor for this device.");
    }
    else
    {
        printk(KERN_INFO "Minor obtained: %d\n", interface->minor);
    }
 
    return retval;
}
 
static void pen_disconnect(struct usb_interface *interface)
{
    printk(KERN_INFO "myRobot con #interfaz: %d drive se removio\n",
    interface->cur_altsetting->desc.bInterfaceNumber);
    usb_deregister_dev(interface, &class);
}
 
static struct usb_device_id pen_table[] =
{
    { USB_DEVICE(0x2341, 0x0001) },
    {} /* Terminating entry */
};
MODULE_DEVICE_TABLE (usb, pen_table);
 
static struct usb_driver myRobot_driver =
{
    .name = "myRobot_driver",
    .id_table = pen_table,
    .probe = pen_probe,
    .disconnect = pen_disconnect,
};
 
static int __init myRobot_init(void)
{
    return usb_register(&myRobot_driver);
}
 
static void __exit myRobot_exit(void)
{
    usb_deregister(&myRobot_driver);
}
 
module_init(myRobot_init);
module_exit(myRobot_exit);
 
