#include <iostream>
#include <vector>

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int lastIndex[26];
        for(int i=0; i<s.length(); i++){
            lastIndex[s[i]-'a'] = i;
        }
        int start=0;
        int end=0;
        vector<int> partition;
        for(int i=0; i<s.length(); i++){
            end = max(end, lastIndex[s[i]-'a']);
            if(i==end){
                partition.push_back(end-start+1);
                start = end + 1;
            }
            else{
                continue;
            }
        }
        return partition;
    }
};
