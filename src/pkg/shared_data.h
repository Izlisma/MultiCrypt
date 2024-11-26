#ifndef _SHARED_DATA_H_
#define _SHARED_DATA_H_

/* 
 * Data shared between the kernel driver and CLI,
 * this includes supported algorithms, structures,
 * codes etc
 */

#define DEVICE_NAME "multicrypt"

#define ALGO_TYPE_HYBRID_SYM_ASYM 1
#define ALGO_TYPE_PASSWORD_DERIVED_KEY 2

#define SUCCESS 0
#define EINVAL_ALGORITHM -1
#define EINVAL_KEY -2
#define EINVAL_FSPATH -3

typedef unsigned long usize_t;  

struct algorithm_data {

    // code to specify algorithm type
    int algorithm_type;

    // specify algorithms for PDK type
    const char *updk_algorithm;

    // specify algorithms for hybrid asymmetric-symmetric
    const char *uasymmetric_algorithm;
    const char *usymmetric_algorithm;

};

struct fs_data {

    // user write buffer to specify path to filesystem image
    const char *ufs_path;
    usize_t ufs_path_size;

    // user write buffer to specify path to mounted filesystem
    const char *ufsmnt_path;
    usize_t ufsmnt_path_size;

};

struct rw_data {

    // user read buffer
    char *uread_buf;
    usize_t uread_buf_size;

    // user write buffer
    const char *uwrite_buf;
    usize_t uwrite_buf_size;

};

/* 
 * Structure of user supplied data to send to 
 * driver via ioctl
 *
 * For sending data to kernel space, if there
 * is not a field explicitly defined for that data
 * then send it via rw.uwrite_buf 
 *
 * Data received from kernel space will be stored in
 * rw.uread_buf
 */
struct muticrypt_ioctl_struct {

    struct fs_data fs;
    struct algorithm_data algorithm;
    struct rw_data rw;
    int errcode;

};

static const char *supported_pdk_algorithm[] = {

};

static const char *supported_asymmetric_algorithm[] = {

};

static const char *supported_symmetric_algorithm[] = {

};

#endif