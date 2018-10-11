#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
	char *data;
	int bytes = (1024*1024);
	for(int i = 0; i<10; i++){
		data = (char*) malloc(10*bytes);
		memset(data, 0, 10*bytes );
		printf("%d\n",i);
		sleep(1);
	}
	return 0;
}