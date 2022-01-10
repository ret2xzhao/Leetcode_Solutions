/*
You are given a string title consisting of one or more words separated by a single space, where each word consists of English letters.
Capitalize the string by changing the capitalization of each word such that:
If the length of the word is 1 or 2 letters, change all letters to lowercase.
Otherwise, change the first letter to uppercase and the remaining letters to lowercase.
Return the capitalized title.

Example 1:
Input: title = "capiTalIze tHe titLe"
Output: "Capitalize The Title"
Explanation:
Since all the words have a length of at least 3, the first letter of each word is uppercase, and the remaining letters are lowercase.

Example 2:
Input: title = "First leTTeR of EACH Word"
Output: "First Letter of Each Word"
Explanation:
The word "of" has length 2, so it is all lowercase.
The remaining words have a length of at least 3, so the first letter of each remaining word is uppercase, and the remaining letters are lowercase.

Example 3:
Input: title = "i lOve leetcode"
Output: "i Love Leetcode"
Explanation:
The word "i" has length 1, so it is lowercase.
The remaining words have a length of at least 3, so the first letter of each remaining word is uppercase, and the remaining letters are lowercase.

Constraints:
1 <= title.length <= 100
title consists of words separated by a single space without any leading or trailing spaces.
Each word consists of uppercase and lowercase English letters and is non-empty.
*/

#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;

class Solution {
public:
    string capitalizeTitle(string title) {
        string result = "";
        vector<string> words;
        char delimiter = ' ';
        int position = 0;
        while((position = title.find(delimiter)) != std::string::npos) {
            words.push_back(title.substr(0, position));
            title.erase(0, position+1);
        }
        words.push_back(title);
        for(auto word : words) {
            result += modifyWord(word) + " "; 
        }
        return result.substr(0, result.length()-1);
    }

    string modifyWord(string& word) {
        string result = "";
        if(word.size()<=2) {
            for(int i=0; i<word.size(); ++i) {
                result += tolower(word[i]);
  	        }
        }
        else{
            result += toupper(word[0]);
            for(int i=1; i<word.size(); ++i) {
                result += tolower(word[i]);
            }
        }
        return result;
    }
};
