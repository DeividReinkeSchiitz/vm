//
// Created by deivid on 12/15/22.
//

#pragma once

#include <openssl/evp.h>
#include <openssl/hmac.h>
#include <openssl/sha.h>

#include <stdio.h>
#include <string.h>


char *sha256_decode(char *str, char *key);
char *sha512_decode(char *str, char *key);
