#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/shared.c"

/* A testcase for the base64-nullstring -> output-bytestring decoder */
static void test_base64_decode (void **state) {
	char *in = "YWJjZGVmZ2hpamtsbW5vcHFyc3R1dnd4eXo=";
	char *out_expected = "abcdefghijklmnopqrstuvwxyz";
	char **out;
	int **len;

	int ret = base64_decode(in, out, len);
	assert_int_equal(ret, 0);
	assert_int_equal(**len, 26);
	assert_memory_equal(*out, out_expected, **len);
}

/* A testcase for the output-bytestring -> base64-nullstring decoder */
static void test_base64_encode (void **state) {
	char *in = "abcdefghijklmnopqrstuvwxyz";
	char *out_expected = "YWJjZGVmZ2hpamtsbW5vcHFyc3R1dnd4eXo=";
	char **out;

	int ret = base64_encode(in, 26, out);
	assert_int_equal(ret, 0);
	assert_string_equal(*out, out_expected);
}

int main(void) {
	const UnitTest tests[] = {
		unit_test(test_base64_decode),
		unit_test(test_base64_encode),
	};
	return run_tests(tests);
}

