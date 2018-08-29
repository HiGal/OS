#include <stdio.h>
#include <string.h>

void fig1();

int main(){
    int n;
    char str[100];
    scanf("%s",str);
    sscanf(str,"%d",&n);
    for(int i = 1; i <=n; i++){
        for(int k = 0; k<=n-i;k++){
            printf(" ");
        }
        for(int j = 0; j<2*i-1;j++){
            printf("*");
        }
        printf("\n");
    }
    fig1(n);
}

void fig1(int n){
    for(int i = 1; i <=n; i++){
        for(int j = 0; j<2*i-1;j++){
            printf("*");
        }
        printf("\n");
    }
}
