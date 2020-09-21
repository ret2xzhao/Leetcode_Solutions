/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return
true if the ransom note can be constructed from the magazines; otherwise, it will return false.
Each letter in the magazine string can only be used once in your ransom note.

Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:
Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:
Input: ransomNote = "aa", magazine = "aab"
Output: true

Constraints:
You may assume that both strings contain only lowercase letters.
*/

class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] arr1 = new int[26];
        int[] arr2 = new int[26];
        for(int i=0; i<ransomNote.length(); i++) {
            arr1[ransomNote.charAt(i)-'a'] += 1;
        }
        for(int i=0; i<magazine.length(); i++) {
            arr2[magazine.charAt(i)-'a'] += 1;
        }
        for(int i=0; i<arr1.length; i++) {
            if(arr1[i] > arr2[i]) {
                return false;
            }
        }
        return true;
    }
}