/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative
positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false

Constraints:
0 <= s.length <= 100
0 <= t.length <= 10^4
s and t consist only of lowercase English letters.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()){return true;}
        if(s.size()>t.size()){return false;}
        int s_ptr=0;
        int t_ptr=0;
        while(t_ptr <= t.size()-1){
            if(s[s_ptr]==t[t_ptr]){
                ++s_ptr;
                ++t_ptr;
                if(s_ptr==s.size()){return true;}
            }
            else{
                ++t_ptr;
            }
        }
        return false;
    }
};
