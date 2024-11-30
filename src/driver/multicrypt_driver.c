#include <linux/module.h>
#include <linux/kernel.h>

#include "ioctl_driver/include/chardev.h"
#include "helpers/macros.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Humzak711 && SynclonSec");
MODULE_DESCRIPTION("MultiCrypt - an open source encrypted virtual filesystem management software");
MODULE_VERSION("1.0");

static int major_number = -1;

static int __init multicrypt_init(void)
{
    int ret = 0;
    multicrypt_info("successfully loaded the driver\n");

    major_number = register_chrdev(0, DEVICE_NAME, &multicrypt_fops);
    if (major_number < 0) {
        multicrypt_err("Failed to register character device driver, error: %d\n", major_number);
        return major_number;
    }

    multicrypt_info("Driver successfully initialized with major number %d\n", major_number);
    return ret;
}

static void __exit multicrypt_exit(void)
{
    if (major_number >= 0) 
        unregister_chrdev(major_number, DEVICE_NAME);

    multicrypt_info("Driver successfully unloaded\n");
}

module_init(multicrypt_init);
module_exit(multicrypt_exit);
