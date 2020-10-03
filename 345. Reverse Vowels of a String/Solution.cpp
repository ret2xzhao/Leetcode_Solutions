/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Input: "hello"
Output: "holle"

Example 2:
Input: "leetcode"
Output: "leotcede"

Note:
The vowels does not include the letter "y".
*/

class Solution {
public:
    string reverseVowels(string s) {
        int l=0, r=s.length()-1;
        while (l<r) {
            if (!(tolower(s[l]) == 'a' || tolower(s[l]) == 'e' || tolower(s[l]) == 'i' || tolower(s[l]) == 'o' || tolower(s[l]) == 'u')) {
                l++;
                continue;
            }
            if (!(tolower(s[r]) == 'a' || tolower(s[r]) == 'e' || tolower(s[r]) == 'i' || tolower(s[r]) == 'o' || tolower(s[r]) == 'u')) {
                r--;
                continue;
            }
            swap(s[l++], s[r--]);
        }
        return s;
    }
};