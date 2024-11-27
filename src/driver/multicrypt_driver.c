#include <linux/module.h>
#include <linux/kernel.h>
#include <stdint.h>

#include "ioctl_driver/include/chardev.h"

MODULE_NAME("multicrypt");
MODULE_DESCRIPTION("MultiCrypt - an open source encrypted filesystem management software");
MODULE_AUTHOR("Humzak711 && SynclonSec");
MODULE_VERSION("1.0");
MODULE_LICENSE("GPL");

static int major_number = -1;

static int __init constructor(void)
{
    int ret = 0;
    printk(KERN_INFO "multicrypt: Driver successfully loaded\n");
    
    major_number = register_chrdev(0, DEVICE_NAME, &multicrypt_fops);
    if (major_number < 0) {
        printk(KERN_ERR "multicrypt: Failed to register character device driver\n");
        return major_number;
    }

    printk(KERN_INFO "multicrypt: Driver successfully initialized\n");
    return ret;
}

static void __exit destructor(void)
{   
    if (major_number >= 0) 
        unregister_chrdev(major_number, DEVICE_NAME);

    printk(KERN_INFO "multicrypt: Driver successfully unloaded\n");
}

module_init(constructor);
module_exit(destructor);