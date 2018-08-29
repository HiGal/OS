#include <stdio.h>
#include <string.h>

void swap(int * n1, int * n2);

int main(){
    char str1[256];
    char str2[256];
    int a;
    int b;

    printf("Write a variable a \n");
    scanf("%s",str1);
    sscanf(str1,"%d",&a);

    printf("Write a variable b \n");
    scanf("%s",str2);
    sscanf(str2,"%d",&b);

    printf("Before swapping\na=%d\nb=%d\n", a,b);

    swap(&a,&b);

    printf("After swapping\na=%d\nb=%d\n", a,b);
}

void swap(int * n1, int * n2)
{
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
