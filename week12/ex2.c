#include <ctype.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	
	char ch;
	int append_mode = 0;
	while ((ch = getopt(argc, argv, "a")) != -1) {
		switch (c) {
		case 'a':
			append_mode = 1;
			break;
		default:
			abort();
			break;
		}
	}
	
	
	
	int num_files;
	char buffer[100];
	size_t len;
	char *file_mode;
	FILE *files[20];
	int i;

	if(append_mode == 1)
		file_mode = "a";
	else
		file_mode = "w";
	
	num_files = argc - optind;
	
	if (num_files > 0) {
		for (i = optind; i < argc; i++) {
			FILE *pFile = fopen(argv[i], file_mode);
			files[i - optind] = pFile; 
		}
	}
	
	FILE *other_stdin = fopen("tee.c", "r");
	len = fread(&buffer[0], 1, sizeof(buffer),other_stdin)
	while (len > 0) {
		len = fread(&buffer[0], 1, sizeof(buffer),other_stdin)
		fwrite(&buffer[0], 1, len, stdout);
		for (i = 0; i < num_files; i++) {
			fwrite(&buf[0], 1, len, files[i]);
		}
	}

	return 0;
}