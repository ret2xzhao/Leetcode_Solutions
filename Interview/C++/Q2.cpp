#include <iostream>
#include <cstring>

void myPrintf(char * string){
    for(int i=0; i<strlen(string); i++){
        putchar(*(string+i));
    }
    printf("\n");
}

int main(){
    char * s = "12345";
    myPrintf(s);
    return 0;
}