/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Note:
All given inputs are in lowercase letters a-z.
*/

import java.util.Arrays;

public class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0 || strs == null) {
            return "";
        }
        Arrays.sort(strs);
        for(int i=0; i<strs[0].length(); i++) {
            char c = strs[0].charAt(i);
            for(int j=1; j<strs.length; j++) {
                if(c != strs[j].charAt(i)) {
                    return strs[0].substring(0,i);
                }
            }
        }
        return strs[0];
    }
}