/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/

class Solution {
    public String reverseWords(String s) {
        String[] splited = s.split("\\s+");
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<splited.length; i++) {
            sb.append(reverseWord(splited[i]));
        }
        return sb.toString().trim();
    }

    public String reverseWord(String word) {
        StringBuilder sb = new StringBuilder();
        for(int i=word.length()-1; i>=0; i--) {
            sb.append(word.charAt(i));
        }
        return sb.toString()+" ";
    }
}