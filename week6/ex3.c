#include<stdio.h> 
#include<signal.h> 

void handle_signal(int sig){
	if(sig == 2)
	printf("Terminated by Ctrl+C %d\n", sig);
}

int main(){
	signal(SIGINT, handle_signal);
	while(1){

	}
	return 0;
}