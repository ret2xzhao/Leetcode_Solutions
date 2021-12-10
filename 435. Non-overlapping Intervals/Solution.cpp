/*
Given an array of intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest
of the intervals non-overlapping.

Example 1:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Example 3:
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

Constraints:
1 <= intervals.length <= 10^5
intervals[i].length == 2
-5 * 10^4 <= starti < endi <= 5 * 10^4
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            else{
                return a[0]<b[0];
            }});    
        int count = 0;
        int pre = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] < pre){
                ++count;
            }
            else{
                pre = intervals[i][1];
            }
        }
        return count;
    }
};

int main() {
    // g++ Solution.cpp -o Solution
    Solution s;
    
    vector<vector<int>> intervals1 = {{1,2},{2,3},{3,4},{1,3}};
    std::cout<<s.eraseOverlapIntervals(intervals1)<<endl;

    vector<vector<int>> intervals2 = {{1,2},{1,2},{1,2}};
    std::cout<<s.eraseOverlapIntervals(intervals2)<<endl;

    vector<vector<int>> intervals3 = {{1,2},{2,3}};
    std::cout<<s.eraseOverlapIntervals(intervals3)<<endl;
}