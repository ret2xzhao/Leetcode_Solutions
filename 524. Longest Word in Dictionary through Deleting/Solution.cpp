/*
Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters.
If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"

Example 2:
Input: s = "abpcplea", dictionary = ["a","b","c"]
Output: "a"

Constraints:
1 <= s.length <= 1000
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 1000
s and dictionary[i] consist of lowercase English letters.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int length = 0;
        string result = "";
        sort(dictionary.begin(), dictionary.end());
        for(string word: dictionary){
            if(isSubsequence(word, s)){
                if(word.size()>length){
                    length = word.size();
                    result = word;
                }
            }
        }
        return result;
    }

    bool isSubsequence(string s, string t) {
        if(s.empty()){return true;}
        if(s.size()>t.size()){return false;}
        int s_ptr=0;
        int t_ptr=0;
        while(t_ptr <= t.size()-1){
            if(s[s_ptr]==t[t_ptr]){
                ++s_ptr;
                ++t_ptr;
                if(s_ptr==s.size()){return true;}
            }
            else{
                ++t_ptr;
            }
        }
        return false;
    }
};
