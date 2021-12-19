/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1:
Input: s = "aba"
Output: true

Example 2:
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.

Example 3:
Input: s = "abc"
Output: false

Constraints:
1 <= s.length <= 10^5
s consists of lowercase English letters.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int left  = 0;
        int right = s.size()-1;
        while(left<=right){
            if(s[left] == s[right]){
                ++left;
                --right;
            }
            else{
                if(substrPalindrome(s, left+1, right) || substrPalindrome(s, left, right-1)){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }

    bool substrPalindrome(string str, int left, int right){
        while(left<=right){
            if(str[left] == str[right]){
                ++left;
                --right;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
