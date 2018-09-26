#include <stdio.h>
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 

int main(){

	int rw1[2];
	int rw2[2];
	pid_t p;


	char str1[] = "Some text";
	

	if(pipe(rw1) == -1){
		return -1;
	}
	if(pipe(rw2) == -1){
		return -1;
	}

	p = fork();
	if(p > 0 ){
		char str2[] = "";

		close(rw1[0]);
		write(rw1[1], str1, strlen(str1) + 1);
		close(rw1);

		wait(NULL);

		close(rw2[1]);

		read(rw2[0], str2, strlen(str1) + 1);
		printf("Super puper ugraded: %s\n", str2 );
		close(rw2[0]);

		
	} else if(p==0){
		char str2[] = "";

		close(rw1[1]);
		read(rw1[0], str2, strlen(str1) + 1);

		close(rw1[0]);
		close(rw2[0]);

		write(rw2[1],str2, strlen(str1) + 1);
		close(rw2[1]);
		exit(0);


	}
	
}