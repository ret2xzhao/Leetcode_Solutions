/*
Given a sentence that consists of some words separated by a single space, and a searchWord, check if searchWord is a prefix
of any word in sentence.
Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word. If searchWord is a prefix
of more than one word, return the index of the first word (minimum index). If there is no such word return -1.
A prefix of a string s is any leading contiguous substring of s.

Example 1:
Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.

Example 2:
Input: sentence = "this problem is an easy problem", searchWord = "pro"
Output: 2
Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th word in the sentence, but we return 2 as it's the
minimal index.

Example 3:
Input: sentence = "i am tired", searchWord = "you"
Output: -1
Explanation: "you" is not a prefix of any word in the sentence.

Constraints:
1 <= sentence.length <= 100
1 <= searchWord.length <= 10
sentence consists of lowercase English letters and spaces.
searchWord consists of lowercase English letters.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    size_t isPrefixOfWord(std::string sentence, std::string searchWord) {
        // Split the string:
        size_t position;
        char delimiter = ' ';
        std::vector<std::string> words;
        while((position=sentence.find(delimiter)) != std::string::npos) {
            words.push_back(sentence.substr(0, position));
            sentence.erase(0, position+1);   
        }
        words.push_back(sentence);

        // Search and Check:
        for(size_t i=0; i<words.size(); ++i) {
            if(words.at(i).find(searchWord) == 0) {
                return i+1;
            }
        }
        return -1;
    }
};
