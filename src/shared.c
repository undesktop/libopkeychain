#include <openssl/conf.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <string.h>
#include "shared.h"

int base64_decode
(char *in, char **out, int **len)
{
	BIO *bio, *b64;
	unsigned int outlen = strlen(in) * 0.75;
	*len = malloc(sizeof(int));
	*out = malloc(outlen);
	if (*out == NULL) return -1;

	b64 = BIO_new(BIO_f_base64());
	bio = BIO_new_mem_buf(in, -1);
	bio = BIO_push(b64, bio);
	**len = BIO_read(bio, *out, outlen);
	BIO_free_all(bio);

	return 0;
}
