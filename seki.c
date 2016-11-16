#include <getopt.h>
#include <stdio.h>

static char const NAME[] = "seki";
static char const VERSION[] = "0.1.3";

int main(int const c, char *const v[]) {
	int opt;

	opterr = 0;
	while ((opt = getopt(c, v, "hv")) != -1) {
		switch (opt) {
		case 'h':
			printf("Usage: %1$s -h\n"
			       "       %1$s -v\n"
			       "       %1$s [desu]\n",
			       NAME);
			return 0;
		case 'v':
			printf("%s v%s\n", NAME, VERSION);
			return 0;
		case '?':
			printf("Unknown flag %s\n", v[optind - 1]);
			return 1;
		}
	}

	char const *const desu = (optind == c ? "desu" : v[optind]);

	for (;;) {
		puts(desu);
	}
}
