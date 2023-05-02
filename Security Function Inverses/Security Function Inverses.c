#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int position(int *arr, int n, int q){
    int i;
    for(i = 0; i < n; i++)
        if( q == *(arr+i) )
            return ++i;
    return ++i;
}
int main(){
    int n, *arr;
    scanf("%d", &n);
    arr = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d ", arr+i);
    for(int i = 0; i < n; i++)
        printf("%d\n", position(arr, n, i+1));
    return 0;
}
