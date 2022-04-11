/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where
prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Constraints:
1 <= numCourses <= 10^5
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/

class Solution {
    const int NOT_VISITED = 0;
    const int BEING_VISITED = 1;
    const int DONE = 2;

public:
    bool isCycle(vector<int> adj_list[], vector<int> &vis_list, int id){
        if (vis_list[id]==BEING_VISITED) {
            return true;
        }
        if (vis_list[id]==NOT_VISITED) {
            vis_list[id]=BEING_VISITED;
            for (auto edge : adj_list[id]) {
                if (isCycle(adj_list, vis_list, edge)) {
                    return true;
                }
            }
        }
        vis_list[id] = DONE;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis_list(numCourses, NOT_VISITED);
        vector<int> adj_list[numCourses];
        for (auto edge : prerequisites) {
            adj_list[edge[1]].push_back(edge[0]);
        }
        for (int i=0; i<numCourses; ++i) {
            if (isCycle(adj_list, vis_list, i)) {
                return false;
            }
        }
        return true;
    }
};