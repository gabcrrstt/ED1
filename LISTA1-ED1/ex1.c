#include <stdio.h>

int main(){
    int n1, n2;

    printf("digite um n para fazer a tabuada\n");
    scanf("%d", &n1);

    for(int i =0; i< 10; i++){
        printf("%d * %d = %d\n", n1, i, n1*i);
    }

    return 0;
}
