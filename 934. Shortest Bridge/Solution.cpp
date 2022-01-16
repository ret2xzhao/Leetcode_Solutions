/*
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
You may change 0's to 1's to connect the two islands to form one island.
Return the smallest number of 0's you must flip to connect the two islands.

Example 1:
Input: grid = [[0,1],[1,0]]
Output: 1

Example 2:
Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2

Example 3:
Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1

Constraints:
n == grid.length == grid[i].length
2 <= n <= 100
grid[i][j] is either 0 or 1.
There are exactly two islands in grid.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    vector<int> direction = {-1, 0, 1, 0, -1};
    queue<pair<int, int>> water;
    void dfs(vector<vector<int>>& grid, int i, int j) {
        grid[i][j] = 2;
        for(int k=0; k<4; ++k) {
            int x = i + direction[k];
            int y = j + direction[k+1];
            if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]==2) {
                continue;
            }
            else if(grid[x][y] == 1) {
                dfs(grid, x, y);
            }
            else if(grid[x][y] == 0) {
                water.push({x, y});
            }
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int row=grid.size(), column=grid[0].size(), res=0;
        // Find the first island:
        bool isFind = false;
        for(int i=0; i<row; ++i) {
            if(isFind){
                break;
            }
            for(int j=0; j<column; ++j) {
                if(grid[i][j] == 1){
                    isFind = true;
                    dfs(grid, i, j);
                    break;
                }
            }
        }

        // Find the second island:
        while(!water.empty()) {
            int size = water.size();
            ++res;
            while(size){
                auto [x, y] = water.front();
                water.pop();
                for(int k=0; k<4; ++k) {
                    int p = x + direction[k];
                    int q = y + direction[k+1];
                    if(p<0 || p>=grid.size() || q<0 || q>=grid[0].size() || grid[p][q]==2) {
                        continue;
                    }
                    if(grid[p][q] == 1) {
                        return res;
                    }
                    grid[p][q] = 2;
                    water.push({p, q});
                }
                --size;
            }
        }
        return res;
    }
};
