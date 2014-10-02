/**
 * @brief A length-delimited bytestring
 */
typedef struct {
	size_t length;
	char data[];
} op_blob;

/**
 * @brief An inline function to initialize an op_blob of a given length
 *
 * @param[out]  blob     Pointer to the op_blob that will be initialized
 * @param[in]   length   Length to be allocated in bytes
 */
inline op_err op_blob_init
(op_blob *blob, size_t length)
{
	op_blob *temp;
	blob = malloc(sizeof(size_t) + length);
	if (blob == NULL) return OP_ERR_OOM;
	blob->length = length;
	return OP_ERR_NONE;
}
