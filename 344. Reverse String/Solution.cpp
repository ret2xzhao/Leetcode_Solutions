#include <algorithm>
#include <vector>
using std::swap;
using std::vector;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i=0; i<n/2; i++) {
            swap(s.at(i), s.at(n-i-1));
        }
    }
};