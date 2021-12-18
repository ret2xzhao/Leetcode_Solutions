/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t
(including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.
A substring is a contiguous sequence of characters within the string.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

Constraints:
m == s.length
n == t.length
1 <= m, n <= 10^5
s and t consist of uppercase and lowercase English letters.
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hs, ht;
        for (char c: t) {
            ht[c]++;
        }
        string result;
        int count = 0;
        for (int i=0, j=0; i<s.size(); i++) {
            hs[s[i]]++;
            if (hs[s[i]] <= ht[s[i]]) {
                count++;
            }
            while (hs[s[j]] > ht[s[j]]) {
                hs[s[j]]--;
                j++;
            }
            if (count == t.size()) {
                if (result.empty() || i-j+1 < result.size()) {
                    result = s.substr(j, i-j+1);
                }
            }
        }
        return result;
    }
};

int main() {
    // g++ Solution.cpp -o Solution
    Solution sltn;
    
    string s = "ADOBECODEBANC";
    string t = "ABC";
    std::cout<<sltn.minWindow(s, t)<<endl;
    return 0;
}