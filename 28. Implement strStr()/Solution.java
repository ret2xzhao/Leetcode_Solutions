/*
Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

Constraints:
haystack and needle consist only of lowercase English characters.
*/

class Solution {
    public int strStr(String haystack, String needle) {
        if(needle.length()==0){
            return 0;
        }
        if(haystack.length()==0){
            return -1;
        }
        for(int i=0; i<haystack.length(); i++){
            if(needle.length() > (haystack.length()-i)){
                return -1;
            }
            if(haystack.substring(i, i+needle.length()).equals(needle)){
                return i;
            }
        }
        return -1;
    }
}