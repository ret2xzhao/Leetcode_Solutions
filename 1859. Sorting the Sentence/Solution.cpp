/*
A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and
uppercase English letters.
A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.
For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.

Example 1:
Input: s = "is2 sentence4 This1 a3"
Output: "This is a sentence"
Explanation: Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers.

Example 2:
Input: s = "Myself2 Me1 I4 and3"
Output: "Me Myself and I"
Explanation: Sort the words in s to their original positions "Me1 Myself2 and3 I4", then remove the numbers.

Constraints:
2 <= s.length <= 200
s consists of lowercase and uppercase English letters, spaces, and digits from 1 to 9.
The number of words in s is between 1 and 9.
The words in s are separated by a single space.
s contains no leading or trailing spaces.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    std::string sortSentence(std::string s) {
        char delimeter = ' ';
        size_t position;
        std::vector<pair<size_t, std::string>> words;
        while((position = s.find(delimeter)) != std::string::npos) {
            std::string tmp = s.substr(0, position);
            words.push_back(std::make_pair(tmp[tmp.size()-1]-'0', tmp.substr(0, tmp.size()-1)));
            s.erase(0, position+1);
        }
        words.push_back(std::make_pair(s[s.size()-1]-'0', s.substr(0, s.size()-1)));

        sort(words.begin(), words.end());
        std::string result = "";
        for(auto word : words) {
            result += word.second + ' ';
        }
        return result.substr(0, result.size()-1);
    }
};
