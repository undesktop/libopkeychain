#include <openssl/conf.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <string.h>
#include <stdio.h>
#include "shared.h"

int base64_decode
(char *src, bytes *dest)
{
	BIO *bio, *b64;
	unsigned int max_len = strlen(src) * 3 / 4;

	dest->data = malloc(max_len);
	if (dest->data == NULL) return -1;

	FILE* stream = fmemopen(src, strlen(src), "r");
	b64 = BIO_new(BIO_f_base64());
	bio = BIO_new_fp(stream, BIO_NOCLOSE);
	bio = BIO_push(b64, bio);
	BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
	dest->length = BIO_read(bio, dest->data, max_len);
	BIO_free_all(bio);

	return 0;
}

int base64_encode
(char *src, int src_len, char **dest)
{
	return -1;
}
