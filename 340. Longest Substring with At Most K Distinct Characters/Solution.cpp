/*
Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.

Example 1:
Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.

Example 2:
Input: s = "aa", k = 1
Output: 2
Explanation: The substring is "aa" with length 2.

Constraints:
1 <= s.length <= 5 * 10^4
0 <= k <= 50
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int maxLength = 0;
        unordered_map<char, int> hs;
        for(int left=0, right=0; right<s.size(); ++right){
            ++hs[s[right]];
            while(hs.size()>k){
                --hs[s[left]];
                if(hs[s[left]]==0){
                    hs.erase(s[left]);
                }
                ++left;
            }
            maxLength = max(maxLength, right-left+1);
        }
        return maxLength;
    }
};

int main(){
    Solution solution;

    string s1 = "eceba";
    int    k1 = 2;
    std::cout<<solution.lengthOfLongestSubstringKDistinct(s1, k1)<<endl;
    
    string s2 = "aa";
    int k2 = 1;
    std::cout<<solution.lengthOfLongestSubstringKDistinct(s2, k2)<<endl;

    string s3 = "aabcbcdbca";
    int k3 = 2;
    std::cout<<solution.lengthOfLongestSubstringKDistinct(s3, k3)<<endl;
    return 0;
}