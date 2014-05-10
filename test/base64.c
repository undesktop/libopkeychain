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
int main(void) {
	const UnitTest tests[] = {
		unit_test(test_base64_decode),
	};
	return run_tests(tests);
}

