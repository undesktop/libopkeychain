#include <openssl/conf.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <string.h>
#include "shared.h"

int base64_decode
(char *src, bytes *dest)
{
	BIO *bio, *b64;
	unsigned int max_len = strlen(src) * 0.75;

	dest->data = malloc(max_len);
	if (dest->data == NULL) return -1;

	b64 = BIO_new(BIO_f_base64());
	bio = BIO_new_mem_buf(src, -1);
	bio = BIO_push(b64, bio);
	dest->length = (int)BIO_read(bio, dest->data, max_len);
	BIO_free_all(bio);

	return 0;
}

int base64_encode
(char *src, int src_len, char **dest)
{
	return -1;
}
