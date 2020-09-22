/*
Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

Example 1:
Input: A = "ab", B = "ba"
Output: true

Example 2:
Input: A = "ab", B = "ab"
Output: false

Example 3:
Input: A = "aa", B = "aa"
Output: true

Example 4:
Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true

Example 5:
Input: A = "", B = "aa"
Output: false

Constraints:
0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist only of lowercase letters.
*/

import java.util.Arrays;

class Solution {
    public boolean buddyStrings(String A, String B) {
        if(A.length() != B.length()) return false;
        int[] arr1 = new int[26];
        int[] arr2 = new int[26];
        for(int i=0; i<A.length(); i++) {
            arr1[A.charAt(i)-'a'] += 1;
        }
        for(int i=0; i<B.length(); i++) {
            arr2[B.charAt(i)-'a'] += 1;
        }
        if(A.equals(B)) {
            for(int num : arr1) {
                if(num>=2) return true;
            }
            return false;
        }
        else {
            if(!Arrays.equals(arr1, arr2)) return false;
            else {
                int swapCounter = 2;
                for(int i=0; i<A.length(); i++) {
                    if(A.charAt(i) != B.charAt(i)) {
                        swapCounter--;
                        if(swapCounter < 0) return false;
                    }
                }
                return true;
            }
        }
    }
}