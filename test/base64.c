#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/shared.c"

/* A test case that does nothing and succeeds. */
static void test_un_base64 (void unused **state) {
	char *in = "YWJjZGVmZ2hpamtsbW5vcHFyc3R1dnd4eXo=";
	char *out_expected = "abcdefghijklmnopqrstuvwxyz";
	char **out;
	int **len;

	un_base64(in, out, len);
	assert_string_equal(&out, out_expected);
}
int main(void) {
	const UnitTest tests[] = {
		unit_test(test_un_base64),
	};
	return run_tests(tests);
}

