#include <stdio.h>

#define dlog(stream, fmt, ...) \
	fprintf(stream, "%s [%s:%d][%s()]: " fmt "\n", \
	__DATE__, __FILE__, __LINE__, __func__, ## __VA_ARGS__)

int main(void)
{
	int code = -1;
	char *err = "Gigel nu mai e pe val!";
	dlog(stderr, "code = %d, err = %s", code, err);

    // ...
	dlog(stdout, "Gigel acum e pe val");

	return 0;
}
