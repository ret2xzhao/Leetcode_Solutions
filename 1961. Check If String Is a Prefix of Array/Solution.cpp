/*
Given a string s and an array of strings words, determine whether s is a prefix string of words.
A string s is a prefix string of words if s can be made by concatenating the first k strings in words for some positive k no larger than words.length.
Return true if s is a prefix string of words, or false otherwise.

Example 1:
Input: s = "iloveleetcode", words = ["i","love","leetcode","apples"]
Output: true
Explanation:
s can be made by concatenating "i", "love", and "leetcode" together.

Example 2:
Input: s = "iloveleetcode", words = ["apples","i","love","leetcode"]
Output: false
Explanation:
It is impossible to make s using a prefix of array.

Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 20
1 <= s.length <= 1000
words[i] and s consist of only lowercase English letters.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        for(size_t i=0; i<words.size(); ++i) {
            size_t position = s.find(words[i]);
            if(position == 0) {
                s.erase(position, words[i].size());
            }
            else if(position != 0 && s.size()>0){
                return false;
            }
        }
        if(s.size()==0) {
            return true;
        }
        return false;
    }
};
