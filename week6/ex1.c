#include <stdio.h>
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 

int main(){

	int rw[2];

	char str1[] = "Some text";
	char str2[] = "";

	if(pipe(rw) == -1){
		return -1;
	}
	write(rw[1], str1, strlen(str1) + 1);
	close(rw[1]);
	read(rw[0],str2,strlen(str1) + 1);
	close(rw[0]);
	printf("Second string from pipe: %s\n", str2 );

}