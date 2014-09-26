#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/shared.c"

/* A testcase for the base64-nullstring -> output-bytestring decoder */
static void test_base64_decode (void **state) {
	char *in = "YWJjZGVmZ2hpamtsbW5vcHFyc3R1dnd4eXo=";
	char *out_expected = "abcdefghijklmnopqrstuvwxyz";
	op_bytes *out = malloc(sizeof(op_bytes));

	assert_return_code(op_base64_decode(in, out), OP_ERR_NONE);
	assert_int_equal(out->length, 26);
	assert_memory_equal(out->data, out_expected, out->length);
	free(out->data);
	free(out);
}

/* A testcase for the output-bytestring -> base64-nullstring decoder */
static void test_base64_encode (void **state) {
	op_bytes in = {.data = "abcdefghijklmnopqrstuvwxyz", .length = 27};
	char *out_expected = "YWJjZGVmZ2hpamtsbW5vcHFyc3R1dnd4eXo=";
	char **out;

	assert_return_code(op_base64_encode(&in, out), OP_ERR_NONE);
	assert_string_equal(*out, out_expected);
	free(*out);
}

int main(void) {
	const UnitTest tests[] = {
		unit_test(test_base64_decode),
		unit_test(test_base64_encode),
	};
	return run_tests(tests);
}

