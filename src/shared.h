/**
 * @brief Converts from base64 to a bytestring.
 * Uses OpenSSL BIO internally.
 *
 * @param[in]   src   The string to read from
 * @param[out]  dest  A pointer which will be aimed at the output bytestring
 * @param[out]  len   A pointer to a 
 */
int un_base64 (
	char *in,
	char **out,
	int **len
);
