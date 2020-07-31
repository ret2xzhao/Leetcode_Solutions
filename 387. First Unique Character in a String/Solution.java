/*
Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:
s = "leetcode"
return 0.

s = "loveleetcode"
return 2.

Note: You may assume the string contains only lowercase English letters.
*/

import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    public int firstUniqChar1(String s) {
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        int length = s.length();
        for(int i=0; i<length; i++) {
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) + 1);
        }
        for(int j=0; j<length; j++) {
            if(map.get(s.charAt(j)) == 1) {
                return j;
            }
        }
        return -1;
    }

    public int firstUniqChar2(String s) {
        int [] charCount = new int[26];
        for(int i=0; i<s.length(); i++){
            char c = s.charAt(i);
            charCount[c-'a'] = charCount[c-'a'] + 1;
        }
        for(int i=0; i<s.length(); i++){
            char c = s.charAt(i);
            if(charCount[c-'a'] == 1){
                return i;
            }
        }
        return -1;
    }
}