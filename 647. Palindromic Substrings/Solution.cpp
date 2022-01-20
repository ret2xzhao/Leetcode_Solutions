/*
Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

Example 1:
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Constraints:
1 <= s.length <= 1000
s consists of lowercase English letters.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    size_t countSubstrings(std::string s) {
        size_t count = 0;
        for(size_t i=0; i<s.size(); ++i) {
            count += extend(s, i, i);
            count += extend(s, i, i+1);
        }
        return count;
    }

    size_t extend(std::string s, int left, int right) {
        size_t result = 0;
        while(left>=0 && right<s.size() && s[left]==s[right]) {
            --left;
            ++right;
            ++result;
        }
        return result;
    }
};
