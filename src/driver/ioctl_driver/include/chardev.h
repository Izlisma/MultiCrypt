#ifndef _CHARDEV_H_
#define _CHARDEV_H_

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/ioctl.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/string.h>
#include <linux/slab.h>

#include "../../../pkg/shared_data.h"

#define IOCTL_CREATE_FS _IOWR('M', 'a', struct multicrypt_ioctl_struct *)
#define IOCTL_SAVE_FS _IOWR('M', 'b', struct multicrypt_ioctl_struct *)
#define IOCTL_MOUNT_FS _IOWR('M', 'c', struct multicrypt_ioctl_struct *)
#define IOCTL_UNMOUNT_FS _IOWR('M', 'd', struct multicrypt_ioctl_struct *)

// macro's to help keep track of the device registration 
#define REGISTERED_MASK 0x00
#define	ALLOC_CHRDEV_REGION_BIT (1 << 0)
#define	CLASS_CREATE_BIT (1 << 1)
#define	CDEV_ALLOC_BIT (1 << 2)
#define	CDEV_ADD_BIT (1 << 3)
#define	DEVICE_CREATE_BIT (1 << 4)

static long multicrypt_ioctl(struct file *file, unsigned int cmd, unsigned long arg);

static struct file_operations multicrypt_fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = multicrypt_ioctl,
};

#endif