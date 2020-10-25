/*
Given a word, you need to judge whether the usage of capitals in it is right or not.
We define the usage of capitals in a word to be right when one of the following cases holds:
All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.

Example 1:
Input: "USA"
Output: True

Example 2:
Input: "FlaG"
Output: False

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/

class Solution {
    public boolean detectCapitalUse(String word) {
        if(areCapitals(word) || areNotCapitals(word) || firstLetterCapital(word)) {
            return true;
        }
        return false;
    }

    public boolean areCapitals(String word) {
        if(word.toUpperCase().equals(word)) {
            return true;
        }
        return false;
    }

    public boolean areNotCapitals(String word) {
        if(word.toLowerCase().equals(word)) {
            return true;
        }
        return false;
    }

    public boolean firstLetterCapital(String word) {
        if((word.substring(0, 1).toUpperCase()+word.substring(1, word.length()).toLowerCase()).equals(word)) {
            return true;
        }
        return false;
    }
}