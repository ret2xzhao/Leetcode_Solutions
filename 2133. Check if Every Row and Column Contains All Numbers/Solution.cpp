/*
An n x n matrix is valid if every row and every column contains all the integers from 1 to n (inclusive).
Given an n x n integer matrix matrix, return true if the matrix is valid. Otherwise, return false.

Example 1:
Input: matrix = [[1,2,3],[3,1,2],[2,3,1]]
Output: true
Explanation: In this case, n = 3, and every row and column contains the numbers 1, 2, and 3.
Hence, we return true.

Example 2:
Input: matrix = [[1,1,1],[1,2,3],[1,2,3]]
Output: false
Explanation: In this case, n = 3, but the first row and the first column do not contain the numbers 2 or 3.
Hence, we return false.

Constraints:
n == matrix.length == matrix[i].length
1 <= n <= 100
1 <= matrix[i][j] <= n
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        std::unordered_map<int, int> map;

        // Check Row:
        for(int start=1, i=0; i<matrix.size(); ++start, ++i) {
            for(int j=0; j<matrix[0].size(); ++j) {
                ++map[matrix[i][j]];
            }
            for(int k=1; k<=n; ++k) {
                if(map[k] != start) {
                    return false;
                }
            }
        }

        // Check Column:
        map.clear();
        for(int start=1, i=0; i<matrix[0].size(); ++start, ++i) {
            for(int j=0; j<matrix.size(); ++j) {
                ++map[matrix[j][i]];
            }
            for(int k=1; k<=n; ++k) {
                if(map[k] != start) {
                    return false;
                }
            }
        }
        return true;
    }
};
