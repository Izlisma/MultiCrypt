#include "include/crypto_fs.h"

int pbkdf2_raw(const char *hash_algo, size_t hash_algo_size, const char *password, 
size_t password_size, char *output_key, size_t output_key_size, 
const char *salt, unsigned int iterations)
{


}   

int multicrypt_pbkdf2(const char *hash_algo const char *password, size_t password_size, 
char *output_key, size_t output_key_size, const char *salt, unsigned int iterations)
{

}

void generate_symmetric_key(char *output_key, size_t size)
{
    if (output_key == NULL || !size) 
        return -EINVAL;
        
    get_random_bytes(output_key, size);
}

int encrypt_symmetric(const char *algo, const char *input, size_t input_size, const char *key
size_t key_size, char *output, size_t *output_size) 
{

}

int decrypt_symmetric(const char *algo, const char *input, size_t input_size, const char *key
size_t key_size, char *output, size_t *output_size)
{

}