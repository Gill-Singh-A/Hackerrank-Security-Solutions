#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <sys/wait.h>

int strLen(char* str){
    int i;
    for(i = 0; *(str+i); i++){};
    return i;
}
int main(){
    int d;
    char* s = (char*) malloc(10 * sizeof(char));
    scanf("%s\n%d", s, &d);
    s = realloc(s, strLen(s)+1);
    int j = strLen(s);
    for(int i = 0; i < j; i++){
        *(s+i) += d;
        if( *(s+i) > 57 )
            *(s+i) -= 10;
        printf("%c", *(s+i));
    }
    return 0;
}
