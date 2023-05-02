#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strLen(char *s){
    int i;
    for(i = 0; *(s+i); i++){};
    return i;
}
void removeDuplicate(char *s){
    int l = strLen(s);
    for(int i = 0; i < l; i++)
        for(int j = i+  1; j < l; j++)
            if( *(s+i) == *(s+j) )
                for(int k = j; k < l; k++)
                    *(s+k) = *(s+k+1);
}
int main(){
    int n;
    char **k, **t, **d, **ds;
    scanf("%d", &n);
    k = (char**) malloc(n * sizeof(char*));
    t = (char**) malloc(n * sizeof(char*));
    d = (char**) malloc(n * sizeof(char*));
    ds = (char**) malloc(n * sizeof(char*));
    for(int i = 0; i < n; i++){
        *(k+i) = malloc(8 * sizeof(char));
        *(t+i) = malloc(300 * sizeof(char));
        *(d+i) = malloc(26 * sizeof(char));
        scanf("%s\n%[^\n]%*c", *(k+i), *(t+i));
        removeDuplicate(*(k+i));
        *(k+i) = realloc(*(k+i), strLen(*(k+i))+1);
        *(t+i) = realloc(*(t+i), strLen(*(t+i))+1);
        int l = strLen(*(k+i));
        char a = 65;
        for(int j = 0; a != 91; j++, a++){
            *(*(d+i)+j) = a;
            for(int m = 0; m < l; m++)
                if( *(*(k+i)+m) == a ){
                    j--;
                    break;
                }
        }
        *(ds+i) = malloc((l+strLen(*(d+i))) * sizeof(char));
        int z = (strLen(*(d+i))/l)+1;
        for(int a = 0; a < l; a++){
            for(int b = 1; b < l; b++){
                if( *(*(k+i)+b-1) > *(*(k+i)+b) ){
                    char temp = *(*(k+i)+b-1);
                    *(*(k+i)+b-1) = *(*(k+i)+b);
                    *(*(k+i)+b) = temp;
                    for(int c = 0; c <= z; c++){
                        int f = l*c;
                        temp = *(*(d+i)+f+b-1);
                        *(*(d+i)+f+b-1) = *(*(d+i)+f+b);
                        *(*(d+i)+f+b) = temp;
                    }
                }
            }
        }
        int p = 0;
        for(int a = 0; a <= l; a++)
            for(int b = 0; b < z; b++, p++)
                if( b == 0 )
                    *(*(ds+i)+p) = *(*(k+i)+a);
                else if( b == z-1 && *(*(d+i)+(b*l)+a) != '\0' ){
                    *(*(ds+i)+p) = *(*(d+i)+((b-1)*l)+a);
                    p++;
                    *(*(ds+i)+p) = *(*(d+i)+(b*l)+a);
                } else
                    *(*(ds+i)+p) = *(*(d+i)+((b-1)*l)+a);
    }
    free(k);
    free(d);
    for(int i = 0; i < n; i++){
        int m = strLen(*(t+i));
        for(int j = 0; j < m; j++)
            if( *(*(t+i)+j) == ' ' )
                printf(" ");
            else{
                int position, z;
                for(position = 0; ; position++)
                    if( *(*(ds+i)+position) == *(*(t+i)+j) )
                        break;
                char a = 65;
                for(z = 0; z < position; z++, a++){}
                *(*(t+i)+j) = a;
                printf("%c", *(*(t+i)+j));
            }
        printf("\n");
    }
    return 0;
}