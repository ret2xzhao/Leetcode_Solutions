/*
Given an input string, reverse the string word by word.

Example 1:
Input: "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

Note:
A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
*/

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

class Solution {
    public String reverseWords1(String s) {
        s = " " + s.replaceAll("\\s+", " ") + " ";
        String res = "";
        String word = "";
        for (int i=0; i<s.length(); i++) {
            if (s.charAt(i) == ' ') {
                res = word + " " + res;
                word = "";
            }
            else {
                word = word + s.charAt(i);
            }
        }
        return res.trim();
    }

    public String reverseWords2(String s) {
        s = s.trim();
        List<String> wordList = Arrays.asList(s.split("\\s+"));
        Collections.reverse(wordList);
        return String.join(" ", wordList);
    }
}