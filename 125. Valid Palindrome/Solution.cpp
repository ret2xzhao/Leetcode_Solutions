#include <iostream>
#include <ctype.h>
#include <string>
#include <algorithm>
using std::string;
using std::swap;

//void reverseStr(string& str) {
//    int n = str.length();
//    for (int i=0; i<n/2; i++) {
//        swap(str[i], str[n-i-1]);
//    }
//}

class Solution {
public:
    bool isPalindrome(string &s) {
        int left = 0, right = s.length()-1;
        while(left<right) {
            if(!isalnum(s[left])){
                left++;
            }
            else if(!isalnum(s[right])){
                right--;
            }
            else if(tolower(s[left])!=tolower(s[right])){
                //reverseStr(s);
                return false;
            }
            else {
                left++;
                right--;
            }
        }
        return true;
    }
};

//int main() {
//    string s = "abcd";
//    isPalindrome(s);
//    std::cout<<s<<std::endl;
//    return 0;
//}