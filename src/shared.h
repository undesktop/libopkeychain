/**
 * @brief Converts from base64 to a bytestring.
 * Uses OpenSSL BIO internally.
 *
 * @param[in]   src       The base64 input in null-delimited string
 * @param[out]  dest      A pointer to a pointer which will be aimed at the output bytestring
 * @param[out]  dest_len  A pointer to a pointer to an integer (for output length)
 */
int base64_decode (
	char *src,
	char **dest,
	int **dest_len
);


/**
 * @brief Converts from bytestring to base64.
 * Uses OpenSSL BIO internally.
 *
 * @param[in]   src      The bytestring to encode into base64
 * @param[in]   src_len  The bytestring's length
 * @param[out]  dest     A pointer to a pointer which will be aimed at the null-delimited output
 */
int base64_encode (
	char *src,
	int src_len,
	char **dest
);
