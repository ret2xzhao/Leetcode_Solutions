/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left
and top edges, and the Atlantic Ocean touches the island's right and bottom edges.
The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the
height above sea level of the cell at coordinate (r, c).
The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the
neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.
Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both
the Pacific and Atlantic oceans.

Example 1:
Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

Example 2:
Input: heights = [[2,1],[1,2]]
Output: [[0,0],[0,1],[1,0],[1,1]]

Constraints:
m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 10^5
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size(),  column = heights[0].size();
        vector<vector<bool>> pacific, atlantic;
        vector<vector<int>> result;
        pacific = atlantic = vector<vector<bool>>(row, vector<bool>(column, false));
        for(int i=0; i<column; ++i){
            dfs(heights, pacific,  0, 0,     i);
            dfs(heights, atlantic, 0, row-1, i);
        }
        for(int j=0; j<row; ++j){
            dfs(heights, pacific,  0, j, 0);
            dfs(heights, atlantic, 0, j, column-1);
        }
        for(int i=0; i<row; ++i){
            for(int j=0; j<column; ++j){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int height, int x, int y) {     
        int row = heights.size(),  column = heights[0].size();
        if(x<0 || x>=row || y<0 || y>=column || visited[x][y]==true || heights[x][y]<height){
            return;
        }
        visited[x][y] = true;
        dfs(heights, visited, heights[x][y], x-1, y);
        dfs(heights, visited, heights[x][y], x, y-1);
        dfs(heights, visited, heights[x][y], x+1, y);
        dfs(heights, visited, heights[x][y], x, y+1);
    }
};