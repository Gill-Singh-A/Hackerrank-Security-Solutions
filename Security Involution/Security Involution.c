#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int n, *arr;
    scanf("%d", &n);
    arr = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d ", arr+i);
    for(int i = 0; i < n; i++)
        if( *(arr+*(arr+*(arr+i)-1)-1) != *(arr+i) ){
            printf("NO");
            return 0;
        }
    printf("YES");
    return 0;
}
