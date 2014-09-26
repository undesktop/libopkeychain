#include <openssl/conf.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "shared.h"

op_err op_base64_decode
(char *src, op_bytes *dest)
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

	return OP_ERR_NONE;
}

op_err op_base64_encode
(op_bytes *src, char **dest)
{
	BIO *bio, *b64;
	unsigned int enc_len = 4 * ceil((double)src->length / 3);

	dest = malloc(enc_len + 1);
	if (dest == NULL) return -1;

	FILE* stream = fmemopen(dest, enc_len + 1, "w");
	b64 = BIO_new(BIO_f_base64());
	bio = BIO_new_fp(stream, BIO_NOCLOSE);
	bio = BIO_push(b64, bio);
	BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
	BIO_write(bio, src->data, src->length);
	BIO_flush(bio);
	BIO_free_all(bio);
	fclose(stream);

	return OP_ERR_NONE;
}
