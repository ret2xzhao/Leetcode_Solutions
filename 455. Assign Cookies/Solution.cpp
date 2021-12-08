/*
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each
cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content.
Your goal is to maximize the number of your content children and output the maximum number.

Example 1:
Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.

Example 2:
Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.
 
Constraints:
1 <= g.length <= 3 * 10^4
0 <= s.length <= 3 * 10^4
1 <= g[i], s[j] <= 2^31 - 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int child=0, cookie=0;
        while(child<g.size() && cookie<s.size()){
            if(g[child]<=s[cookie]){
                ++child;
            }
            ++cookie;
        }
        return child;
    }
};

int main() {
    vector<int> input1 = {1, 2, 3};
    vector<int> input2 = {1, 1};
    Solution s1;
    std::cout<<s1.findContentChildren(input1, input2)<<endl;

    vector<int> input3 = {1, 2};
    vector<int> input4 = {1, 2, 3};
    Solution s2;
    std::cout<<s2.findContentChildren(input3, input4)<<endl;

    vector<int> input5 = {2, 4, 8};
    vector<int> input6 = {1, 2, 3, 5, 6, 7};
    Solution s3;
    std::cout<<s3.findContentChildren(input5, input6)<<endl;
    // g++ Solution.cpp -o Solution
}