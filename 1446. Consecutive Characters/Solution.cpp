/*
The power of the string is the maximum length of a non-empty substring that contains only one unique character.
Given a string s, return the power of s.

Example 1:
Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.

Example 2:
Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.

Constraints:
1 <= s.length <= 500
s consists of only lowercase English letters.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    size_t maxPower(std::string s) {
        size_t maximum=1, tmp=1;
        for(size_t i=1; i<s.size(); ++i) {
            if(s[i]==s[i-1]) {
                ++tmp;
                maximum = max(maximum, tmp);
            }
            else {
                maximum = max(maximum, tmp);
                tmp = 1;
            }
        }
        return maximum;
    }
};
