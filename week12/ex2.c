#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	
	//resolve arguments
	char c;
	int append_mode = 0;
	while ((c = getopt(argc, argv, "a")) != -1) {
		switch (c) {
		case 'a':
			append_mode = 1;
			break;
		case '?':
			if (isprint(optopt))
				fprintf(stderr, "Unkonw option `-%c'.\n", optopt);
			else
				fprintf(stderr,
					"Unknown option character `\\x%x'.\n", optopt);
			return 1;
		default:
			abort();
			break;
		}
	}
	
	int i;
	FILE *files[20];
	int num_files;
	char buf[100];
	size_t len;
	char *file_mode;
	
	file_mode = (append_mode ? "a" : "w");
	num_files = argc - optind;
	
	if (num_files > 0) {
		for (i = optind; i < argc; i++) {
			FILE *pFile = fopen(argv[i], file_mode);
			files[i - optind] = pFile; /* mind the offset */
		}
	}
	
	FILE *not_stdin = fopen("tee.c", "r");
	while ((len = fread(&buf[0], 1, sizeof(buf), not_stdin)) > 0) {
		fwrite(&buf[0], 1, len, stdout);
		for (i = 0; i < num_files; i++) {
			fwrite(&buf[0], 1, len, files[i]);
		}
	}

	return 0;
}