#ifndef _SHARED_DATA_H_
#define _SHARED_DATA_H_

/* 
 * Data shared between the kernel driver and CLI,
 * this includes supported algorithms, structures,
 * macros etc
 */

#define DEVICE_NAME "multicrypt"
#define MULTICRYPT_CLI_PROCESS_NAME "multicrypt_cli"

#define MULTICRYPT_IOCTL_SUCCESS_BIT 1
#define MULTICRYPT_IOCTL_FAIL_BIT 2
#define MULTICRYPT_IOCTL_INVALID_CREDS_BIT 3

typedef unsigned long usize_t;  

struct algorithm_data {

    // specify algorithms 
    const char *uhashing_algorithm;
    const char *usymmetric1_algorithm;
    const char *usymmetric2_algorithm;

};

struct fs_data {

    // user write buffer to specify path to filesystem image
    const char *ufs_path;

    // user write buffer to specify path to mounted filesystem
    const char *ufsmnt_path;

};

struct credentials_data {

    // user write buffer to supply password
    char *upassword;

    // user write buffer to supply pin code
    char *upin;

};

/**
 * Structure of user supplied data to send to 
 * driver via ioctl
 * 
 * errmask is filled by the driver
 */
struct muticrypt_ioctl_struct {

    struct fs_data *fs;
    struct algorithm_data *algorithm;
    struct credentials_data *credentials;
    char *uread_buf;
    unsigned int errmask;

};

static const char *supported_hashing_algorithms[] = {

};

static const char *supported_symmetric_algorithms[] = {

};

#endif