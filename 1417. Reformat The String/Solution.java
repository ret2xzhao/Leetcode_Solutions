/*
Given alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).
You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters
have the same type.
Return the reformatted string or return an empty string if it is impossible to reformat the string.

Example 1:
Input: s = "a0b1c2"
Output: "0a1b2c"
Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.

Example 2:
Input: s = "leetcode"
Output: ""
Explanation: "leetcode" has only characters so we cannot separate them by digits.

Example 3:
Input: s = "1229857369"
Output: ""
Explanation: "1229857369" has only digits so we cannot separate them by characters.

Example 4:
Input: s = "covid2019"
Output: "c2o0v1i9d"

Example 5:
Input: s = "ab123"
Output: "1a2b3"

Constraints:
1 <= s.length <= 500
s consists of only lowercase English letters and/or digits.
*/

class Solution {
    public String reformat(String s) {
        int strAlphabet=0, strNumber=0;
        char[] chars = s.toCharArray();
        for(char c:chars){
            if(c >= '0' && c <= '9'){strNumber++;}
            else{strAlphabet++;}
        }
        if(Math.abs(strAlphabet-strNumber)>1){
            return "";
        }
        if(strAlphabet>strNumber){
            strAlphabet = 0;
            strNumber = 1;
        }else{
            strAlphabet = 1;
            strNumber = 0;
        }
        for(char c : s.toCharArray()){
            if(c >= '0' && c <= '9'){
                chars[strNumber] = c;
                strNumber += 2;
            }
            else{
                chars[strAlphabet] = c;
                strAlphabet += 2;
            }
        }
        return new String(chars);
    }
}