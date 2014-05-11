#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/shared.c"

/* A test case that does nothing and succeeds. */
static void test_base64_decode (void **state) {
	char *in = "YWJjZGVmZ2hpamtsbW5vcHFyc3R1dnd4eXo=";
	char *out_expected = "abcdefghijklmnopqrstuvwxyz";
	char **out;
	int **len;

	base64_decode(in, out, len);
	assert_int_equal(**len, 26);
	assert_memory_equal(*out, out_expected, **len);
}

static void test_base64_encode (void **state) {
	char *in = "abcdefghijklmnopqrstuvwxyz";
	char *out_expected = "YWJjZGVmZ2hpamtsbW5vcHFyc3R1dnd4eXo=";
	char **out;

	base64_encode(in, 26, out);
	assert_string_equal(*out, out_expected);
}

int main(void) {
	const UnitTest tests[] = {
		unit_test(test_base64_decode),
		unit_test(test_base64_encode),
	};
	return run_tests(tests);
}

