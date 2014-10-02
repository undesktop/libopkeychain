inline char* op_err_tostring
(op_err err)
{
	switch (err) {
		case OP_ERR_OOM:     return "ERR_OOM: Out of memory";
	}
}

inline void op_err_print
(op_err err)
{
	printf("Error: %s", op_err_tostring(err));
}

inline void op_err_die
(op_err err)
{
	op_err_print(err);
	exit(err);
}
