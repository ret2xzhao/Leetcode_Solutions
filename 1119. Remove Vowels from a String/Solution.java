/*
Given a string S, remove the vowels 'a', 'e', 'i', 'o', and 'u' from it, and return the new string.

Example 1:
Input: "leetcodeisacommunityforcoders"
Output: "ltcdscmmntyfrcdrs"

Example 2:
Input: "aeiou"
Output: ""

Note:
S consists of lowercase English letters only.
1 <= S.length <= 1000
*/

import java.util.HashMap;

class Solution {
    public String removeVowels(String S) {
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        map.put('a', 0);
        map.put('e', 0);
        map.put('i', 0);
        map.put('o', 0);
        map.put('u', 0);
        String result = "";
        for(int i=0; i<S.length(); i++) {
            if(!map.containsKey(S.charAt(i))) {
                result += S.charAt(i);
            }
        }
        return result;
    }
}