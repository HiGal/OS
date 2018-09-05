#include <stdio.h>

void swap(int* a, int* b);
void bubble_sort(int arr[], int size);
void printArray(int arr[], int size);

int main(){
	int arr[] = {10,64,1,0,-1,2};
	size_t size = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, size);
	printArray(arr, size);
	printf("\n");
	return 0;
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int arr[], int size){
	int i, j;
    for (i = 0; i < size-1; i++)        
       for (j = 0; j < size-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

void printArray(int arr[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
}