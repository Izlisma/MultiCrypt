#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#include "ioctl_driver/include/chardev.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Humzak711 && SynclonSec");
MODULE_DESCRIPTION("MultiCrypt - an open source encrypted filesystem management software");
MODULE_VERSION("1.0");

static int major_number = -1;
#define DEVICE_NAME "multicrypt"

static int __init multicrypt_init(void)
{
    int ret = 0;
    printk(KERN_INFO "multicrypt: Driver successfully loaded\n");

    major_number = register_chrdev(0, DEVICE_NAME, &multicrypt_fops);
    if (major_number < 0) {
        printk(KERN_ERR "multicrypt: Failed to register character device driver, error: %d\n", major_number);
        return major_number;
    }

    printk(KERN_INFO "multicrypt: Driver successfully initialized with major number %d\n", major_number);
    return ret;
}

static void __exit multicrypt_exit(void)
{
    if (major_number >= 0) {
        unregister_chrdev(major_number, DEVICE_NAME);
        printk(KERN_INFO "multicrypt: Driver successfully unloaded\n");
    } else {
        printk(KERN_ERR "multicrypt: Unregistering character device driver failed, invalid major number: %d\n", major_number);
    }
}

module_init(multicrypt_init);
module_exit(multicrypt_exit);
