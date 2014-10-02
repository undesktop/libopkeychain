#pragma once
#include <stdio.h>

/**
 * @brief An error code returned by a function
 */
typedef enum {
	OP_ERR_NONE = 0,
	OP_ERR_OOM = 1
} op_err;

/**
 * @brief A complex error type consisting of an op_err and a pointer to some payload
 * The payload could be anything, it's up to you to handle that.
 *
 * Main use is for proxying errors from other frameworks (say, OpenSSL)
 */
typedef struct {
	op_err err;
	void* data;
} op_err_complex;

/**
 * @brief Convert an error code to a string representation
 */
inline char* op_err_tostring (op_err err);

/**
 * @brief Print an error's string representation to the standard error stream
 */
inline void op_err_print (op_err err);

/**
 * @brief Prints an error and dies
 * Prints the error to standard error, then terminates the program.
 */
inline void op_err_die (op_err err);
