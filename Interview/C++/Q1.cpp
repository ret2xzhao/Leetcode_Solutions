#include <iostream>
#include <string>

int main(){
    char * s = "12345";
    printf("%d\n",      s);
    printf("%d\n",     *s);
    printf("%c\n",     *s);
    printf("%c\n", *(s+1));
    printf("%s\n",      s);
    printf("%s\n",     *s);
    return 0;
}