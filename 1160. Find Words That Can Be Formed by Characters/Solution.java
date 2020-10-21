/*
You are given an array of strings words and a string chars.
A string is good if it can be formed by characters from chars (each character can only be used once).
Return the sum of lengths of all good strings in words.

Example 1:
Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation:
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.

Example 2:
Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation:
The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.

Note:
1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
All strings contain lowercase English letters only.
*/

class Solution {
    public int countCharacters(String[] words, String chars) {
        int count = 0;
        int[] charsMap = new int[26];
        for(int i=0; i<chars.length(); i++) {
            charsMap[chars.charAt(i)-'a'] = charsMap[chars.charAt(i)-'a'] + 1;
        }
        for(int i=0; i<words.length; i++) {
            count += checkIfContain(charsMap, words[i]);
        }
        return count;
    }

    public int checkIfContain(int[] charsMap, String word) {
        int[] charsInWord = new int[26];
        for(int i=0; i<word.length(); i++) {
            charsInWord[word.charAt(i)-'a'] = charsInWord[word.charAt(i)-'a'] + 1;
        }
        for(int i=0; i<charsMap.length; i++) {
            if(charsInWord[i] > charsMap[i]) {
                return 0;
            }
        }
        return word.length();
    }
}