#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int n, *arr;
    scanf("%d", &n);
    arr = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d ", arr+i);
        for(int j = 0; j < i; j++)
            if( *(arr+i) == *(arr+j) ){
                printf("NO");
                return 0;
            }
    }
    printf("YES");
    return 0;
}
