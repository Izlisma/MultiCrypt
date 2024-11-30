#ifndef _MACROS_H_
#define _MACROS_H_

#include <linux/kernel.h>

#define multicrypt_info(fmt, ...) pr_info("multicrypt: " fmt, ##__VA_ARGS__)

#define multicrypt_err(fmt, ...) pr_err("multicrypt: (%s) " fmt, __func__, ##__VA_ARGS__)

#endif