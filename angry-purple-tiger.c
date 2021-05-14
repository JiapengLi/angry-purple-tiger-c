#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "md5.h"
#include "word.h"

static void compress(const uint8_t *buf, int len, uint8_t *dest)
{
    int i, block_size;
    dest[0] = 0;
    dest[1] = 0;
    dest[2] = 0;

    i = 0;
    block_size = len / 3;

    while (len > 0){
        *dest ^= *buf++;
        i++;
        len--;
        if ((i == block_size) && (len >= block_size)) {
            dest++;
            i = 0;
        }
    }
}

const char *animal_name(const uint8_t *str, int len)
{
    uint8_t digest[16];
    uint8_t dest[3];
    char *s;
    int slen;

    MD5_CTX md5ctx;

    MD5_Init(&md5ctx);
    MD5_Update(&md5ctx, str, len);
    MD5_Final(digest, &md5ctx);

    compress(digest, 16, dest);

    slen = strlen(ADJECTIVES[dest[0]]) + strlen(COLORS[dest[1]]) + strlen(ANIMALS[dest[2]]) + 3 + 1;
    s = malloc(slen);
    snprintf(s, slen, "%s-%s-%s", ADJECTIVES[dest[0]], COLORS[dest[1]], ANIMALS[dest[2]]);

    return s;
}
