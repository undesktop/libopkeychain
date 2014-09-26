typedef struct {
	unsigned int length;
	char *data;
} bytes;

/**
 * @brief Converts from base64 to a bytestring.
 * Uses OpenSSL BIO internally.
 *
 * @param[in]   src       The base64 input in null-delimited string
 * @param[out]  dest      A pointer to a pointer to a bytestring which will be aimed at the output
 */
int base64_decode (
	char *src,
	bytes *dest
);


/**
 * @brief Converts from bytestring to base64.
 * Uses OpenSSL BIO internally.
 *
 * @param[in]   src      The bytestring to encode into base64
 * @param[out]  dest     A pointer to a pointer which will be aimed at the null-delimited output
 */
int base64_encode (
	bytes *src,
	char **dest
);
