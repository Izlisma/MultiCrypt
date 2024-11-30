#ifndef _CRYPTO_FS_H_
#define _CRYPTO_FS_H_

/* 
 * Package for handling encrypting and decrypting
 * filesystems, with support for hybrid asymmetric-symmetric
 * and PDK
 */

#include <linux/crypto.h>
#include <linux/string.h>
#include <linux/slab.h>
#include <linux/random.h>
#include <linux/errno.h>
#include <linux/err.h>
#include "../../../helpers/macros.h"

#define CRYPTO_FS_CRYPTO_ERR -1
#define CRYPTO_FS_SUCCESS 0

/*
 * AVOID CALLING THIS DIRECTLY
 *
 * For deriving keys please use multicrypt_pbkdf2
 */
int pbkdf2_raw(const char *hash_algo, size_t hash_algo_size, const char *password, 
size_t password_size, char *output_key, size_t output_key_size, 
const char *salt, unsigned int iterations);

int multicrypt_pbkdf2(const char *hash_algo const char *password, size_t password_size, 
char *output_key, size_t output_key_size, const char *salt, 
unsigned int iterations);

int generate_symmetric_key(char *output_key, size_t output_key_size);
int encrypt_symmetric(const char *algo, const char *input, size_t input_size, const char *key
size_t key_size, char *output, size_t *output_size);
int decrypt_symmetric(const char *algo, const char *input, size_t input_size, const char *key
size_t key_size, char *output, size_t *output_size);

#endif