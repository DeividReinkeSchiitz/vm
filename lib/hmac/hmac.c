//
// Created by deivid on 12/15/22.
//

#include "hmac.h"

char *sha256_decode(char *str, char *key)
{
    unsigned char buffer[SHA256_DIGEST_LENGTH] = {};
    char *tmp                                  = (char *) malloc(3);

    char *result                               = (char *) malloc(SHA256_DIGEST_LENGTH * 2 + 2);
    bzero(result, SHA256_DIGEST_LENGTH * 2 + 2);


    HMAC(EVP_sha256(), key, (int) strlen(key), (unsigned char *) str, strlen(str), buffer, NULL);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        bzero(tmp, 3);
        sprintf(tmp, "%02x", buffer[i]);
        strcat(result, tmp);
    }

    free(tmp);

    return result;
}

char *sha512_decode(char *str, char *key)
{
    unsigned char buffer[SHA512_DIGEST_LENGTH] = {};
    char *tmp                                  = (char *) malloc(3);

    char *result                               = (char *) malloc(SHA512_DIGEST_LENGTH * 2 + 2);
    bzero(result, SHA512_DIGEST_LENGTH * 2 + 2);

    HMAC(EVP_sha512(), key, (int) strlen(key), (unsigned char *) str, strlen(str), buffer, NULL);

    for (int i = 0; i < SHA512_DIGEST_LENGTH; i++)
    {
        bzero(tmp, 3);
        sprintf(tmp, "%02x", buffer[i]);
        strcat(result, tmp);
    }

    free(tmp);

    return result;
}
