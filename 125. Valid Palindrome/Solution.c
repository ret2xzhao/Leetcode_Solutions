#include <ctype.h>
#include <stdbool.h>

bool isPalindrome(char str[]) {
    int left = 0, right = strlen(str)-1;
    while(left<right) {
        if(!isalnum(str[left])){
            left++;
        }
        else if(!isalnum(str[right])){
            right--;
        }
        else if(tolower(str[left])!=tolower(str[right])){
            printf("%s is Not Palindrome", str);
            return false;
        }
        else {
            left++;
            right--;
        }
    }
    printf("%s is palindrome", str);
    return true;
}

int main() {
    isPalindrome("A man, a plan, a canal: Panama");
    isPalindrome("race a car");
    isPalindrome("geeks");
    return 0;
}