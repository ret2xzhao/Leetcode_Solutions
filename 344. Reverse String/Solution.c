void reverseString(char* s, int sSize){
    /* skip null */
    if(s == 0) {
        return;
    }
    /* skip empty string */
    if (*s == 0) {
        return;
    }
    char *start = s;
    char *end = start + sSize - 1;
    char temp;
    while(start<end) {
        temp = *start;
        *start = *end;
        *end = temp;
        ++start;
        --end;
    }
}