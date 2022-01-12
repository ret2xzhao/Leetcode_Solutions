#include <stdio.h>

int main(){
    char* s = "12345";
    printf("%d\n",      s); // Convert the address of the string into decimal.
    printf("%d\n",     *s); // 49 - '1' in decimal.
    printf("%c\n",     *s); // 1
    printf("%c\n", *(s+1)); // 2
    printf("%s\n",      s); // 12345
    printf("%s\n",     *s); // warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘int’ [-Wformat=]
    return 0;
}
