#ifndef _IOCTL_H_
#define _IOCTL_H_

#include <sys/ioctl.h>

#include "../../../pkg/shared_data.h"

#define IOCTL_CREATE_FS _IOWR('M', 'a', struct multicrypt_ioctl_struct *)
#define IOCTL_SAVE_FS _IOWR('M', 'b', struct multicrypt_ioctl_struct *)
#define IOCTL_MOUNT_FS _IOWR('M', 'c', struct multicrypt_ioctl_struct *)
#define IOCTL_UNMOUNT_FS _IOWR('M', 'd', struct multicrypt_ioctl_struct *)

#endif