/**
 * @brief Converts from base64 to a bytestring.
 * Uses OpenSSL BIO internally.
 *
 * @param[in]   src   The string to read from
 * @param[out]  dest  A pointer which will be aimed at the output bytestring
 * @param[out]  len   A pointer to a 
 */
int base64_decode (
	char *in,
	char **out,
	int **len
);


/**
 * @brief Converts from bytestring to base64.
 * Uses OpenSSL BIO internally.
 *
 * @param[in]   src   The bytestring to encode into base64
 * @param[in]   len   The bytestring's length
 * @param[out]  dest  A pointer to a pointer which will be aimed at the null-delimited output
 */
int base64_encode (
	char *src,
	int len,
	char **dest
);
