#include <stdio.h>
#include <stdbool.h>



int num_proc;
int num_res;

void read_from_file(FILE *fp,int num_proc, int num_res,int E[] ,int A[],int C[][num_res],int R[][num_res]){
	
	//reading existence resources

	for(int i = 0; i < num_res; i++){
		 fscanf(fp,"%d",&E[i]);
	}
	
	//reading available resources

	for(int i = 0; i < num_res; i++){
		 fscanf(fp,"%d",&A[i]);
	}

	//reading current matrix allocation

	for (int i = 0; i < num_proc; ++i)
	{
		for(int k = 0; k < num_res; k++){
		 	fscanf(fp,"%d",&C[i][k]);
		}
	}

	//reading request matrix
	for (int i = 0; i < num_proc; ++i)
	{
		for(int k = 0; k < num_res; k++){
		 	fscanf(fp,"%d",&R[i][k]);
		}
	}
}

void isSafe(FILE *out,int processes[], int available[], int allocation[][num_res], int request[num_proc][num_res]){

	bool finish[num_proc];

	for (int i = 0; i < num_proc; ++i)
	{
		finish[i] = 0;
	}

	int safeOrder[num_proc];

	int work[num_res];
	for(int i = 0; i < num_res; i++){
		work[i] = available[i];
	}

	int count = 0;
	while(count < num_proc){
		bool found = false;
		for (int i = 0; i < num_proc; ++i)
		{
			if(finish[i] == 0){
				int j;
				for (j = 0; j < num_res; ++j)
					if(request[i][j] > work[j])
						break;
				if(j == num_res){
					for(int k = 0; k < num_res;k++)
						work[k] += allocation[i][k];
					safeOrder[count++] = i;

					finish[i] = 1;

					found = true;
				}	
			}		
		}

		if (found == false){
			fprintf(out,"System is not in safe state\n");
			return;
		}

	}
		fprintf(out,"The sequence of process order that make system safe:\n");
		for (int i = 0; i < num_proc; ++i)
		{
			fprintf(out,"%d ",safeOrder[i]);
		}
		fprintf(out,"\n");

}	


int main()
{

	FILE  *fp_w = fopen("input_dl","r"); 
	FILE *fp_wo = fopen("input_ok","r");
	FILE *out_ok = fopen("output_ok","w");
	FILE *out_dl = fopen("output_dl","w");


	printf("Enter number of processes:\n");
	scanf("%d", &num_proc);

	printf("Enter number of resources\n");
	scanf("%d", &num_res);


	int E[num_res];
	int A[num_res];
	int C[num_proc][num_res];
	int R[num_proc][num_res];


	//numerate processes
	int processes[num_proc];
	for (int i = 0; i < num_proc; ++i)
	{
		processes[i] = i;
	}
	read_from_file(fp_wo,num_proc, num_res,E,A,C,R);
	isSafe(out_ok,processes,A,C,R);

	read_from_file(fp_w,num_proc, num_res,E,A,C,R);
	isSafe(out_dl,processes,A,C,R);
	return 0;
}

