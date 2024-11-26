#include <linux/module.h>
#include <linux/kernel.h>
#include <stdint.h>

#include "ioctl_driver/include/chardev.h"

MODULE_NAME("multicrypt");
MODULE_DESCRIPTION("MultiCrypt - an open source encrypted filesystem management software");
MODULE_AUTHOR("Humzak711 && SynclonSec");
MODULE_VERSION("1.0");
MODULE_LICENSE("GPL");

static dev_t dev = 0;
static struct class *multicrypt_class = NULL;
static struct cdev *multicrypt_cdev = NULL;

// 8 bit mask to keep track of registered data
uint8_t registered_mask = REGISTERED_MASK;

static int __init constructor(void)
{
    int ret = 0;

    ret = alloc_chrdev_region(&dev, 0, 1, DEVICE_NAME);
    if (ret < 0) {
        printk(KERN_ERR "multicrypt: Failed to allocate a major number\n");
        return ret;
    }
    registered_mask |= ALLOC_CHRDEV_REGION_BIT;
    
    multicrypt_class = class_create(THIS_MODULE, DEVICE_NAME);
    if (IS_ERR(multicrypt_class)) {
        printk(KERN_ERR "multicrypt: Failed to create a device class\n");
        ret = -1;
        goto err1;
    }
    registered_mask |= CLASS_CREATE_BIT;

    multicrypt_cdev = cdev_alloc();
    if (multicrypt_cdev == NULL) {
        printk(KERN_ERR "multicrypt: Failed to allocate a cdev\n");
        goto err2;
    }
    registered_mask |= CDEV_ALLOC_BIT;

    cdev_init(multicrypt_cdev, &multicrypt_fops);
    multicrypt_cdev->owner = THIS_MODULE;
    ret = cdev_add(multicrypt_cdev, dev, 1);
    if (ret < 0) {
        printk(KERN_ERR "multicrypt: Failed to add the character device driver\n");
        goto err3;
    }
    registered_mask |= CDEV_ADD_BIT;

    if (device_create(multicrypt_class, NULL, dev, NULL, DEVICE_NAME) == NULL) {
        cdev_del(multicrypt_cdev);
        printk(KERN_ERR "multicrypt: Failed to create the character device driver\n");
        ret = -1;
        goto err3;
    }
    registered_mask |= DEVICE_CREATE_BIT;

    printk(KERN_INFO "multicrypt: successfully registered the character device driver\n");
    return ret;
    
err3:
    kfree(multicrypt_cdev);
    multicrypt_cdev = NULL;
err2:
    class_destroy(multicrypt_class);
    multicrypt_class = NULL;
err1:
    unregister_chrdev_region(dev, 1);
    return ret;
}

static void __exit destructor(void)
{   
    if (registered_mask & DEVICE_CREATE_BIT) 
        device_destroy(multicrypt_class, dev);

    if (registered_mask & CDEV_ADD_BIT) 
        cdev_del(multicrypt_cdev);
    
    if (registered_mask & CDEV_ALLOC_BIT) {
        kfree(multicrypt_cdev);
        multicrypt_cdev = NULL;
    }

    if (registered_mask & CLASS_CREATE_BIT) {
        class_destroy(multicrypt_class);
        multicrypt_class = NULL;
    }

    if (registered_mask & ALLOC_CHRDEV_REGION_BIT)
        unregister_chrdev_region(dev, 1);

    printk(KERN_INFO "multicrypt: Driver successfully unloaded\n");
}

module_init(constructor);
module_exit(destructor);