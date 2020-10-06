/*
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

Example 1:
Input: s = "abccccdd"
Output: 7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:
Input: s = "a"
Output: 1

Example 3:
Input: s = "bb"
Output: 2

Constraints:
1 <= s.length <= 2000
s consits of lower-case and/or upper-case English letters only.
*/

class Solution {
    public int longestPalindrome(String s) {
        int[] nums = new int[128];
        for(char c: s.toCharArray()) {
            nums[c]++;
        }
        int result = 0;
        for(int i=0; i<nums.length; i++) {
            result += nums[i]/2*2;
        }
        return result == s.length() ? result : result+1;
    }
}