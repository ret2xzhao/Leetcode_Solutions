#include <iostream>
#include <cstring>

//./Q3 one two three
//eerht owt eno
int main(int argc, char ** argv){
    // printf("There are %d arguments.\n", argc);
    for(int i=argc-1; i>0; i--){
        int index = strlen(argv[i])-1;
        for(int j=index; j>=0; j--){
            printf("%c", argv[i][j]);
        }
        printf(" ");
    }
    printf("\n");
}