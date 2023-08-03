#include <openssl/evp.h>

#include <stdio.h>
#include <string.h>

#define AOCYEAR 2015
#define AOCDAY 4

unsigned int count_zeros_in_hash(int i, char *prefix);

static EVP_MD_CTX *ctx;

int main(void)
{
    ctx = EVP_MD_CTX_new();
    int i = 1;

    while (count_zeros_in_hash(i, "yzbqklnj") != 5)
        i++;

    printf("%4d-%02d/%d: %d\n", AOCYEAR, AOCDAY, 1, i);

    while (count_zeros_in_hash(i, "yzbqklnj") != 6)
        i++;

    printf("%4d-%02d/%d: %d\n", AOCYEAR, AOCDAY, 2, i);

    EVP_MD_CTX_free(ctx);
    
    return 0;
}

unsigned int count_zeros_in_hash(int i, char *prefix)
{
    char buffer[32] = "";
    unsigned char md[EVP_MAX_MD_SIZE];
    unsigned int mdlen;
    unsigned int zeros = 0;

    snprintf(buffer, 20, "%s%d", prefix, i);

    EVP_DigestInit_ex(ctx, EVP_md5(), NULL);
    EVP_DigestUpdate(ctx, buffer, strlen(buffer));
    EVP_DigestFinal_ex(ctx, md, &mdlen);

    for (size_t i = 0; i < mdlen; ++i) {
        if (md[i] == 0) {
            zeros += 2;
        } else if (md[i] < 16) {
            zeros += 1;
            break;
        } else {
            break;
        }
    }

    return zeros;
}
