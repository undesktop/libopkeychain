#pragma once
#include "error.h"
#include "types.h"

/**
 * @brief Converts from base64 to a bytestring.
 * Uses OpenSSL BIO internally.
 *
 * @param[in]   src       The base64 input in null-delimited string
 * @param[out]  dest      A pointer to a pointer to a bytestring which will be aimed at the output
 */
op_err op_base64_decode (
	char *src,
	op_blob *dest
);

/**
 * @brief Converts from bytestring to base64.
 * Uses OpenSSL BIO internally.
 *
 * @param[in]   src      The bytestring to encode into base64
 * @param[out]  dest     A pointer to a pointer which will be aimed at the null-delimited output
 */
op_err op_base64_encode (
	op_blob *src,
	char **dest
);
