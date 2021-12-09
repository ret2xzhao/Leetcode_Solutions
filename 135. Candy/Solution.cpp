/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

Example 1:
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:
Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.

Constraints:
n == ratings.length
1 <= n <= 2 * 10^4
0 <= ratings[i] <= 2 * 10^4
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> num (ratings.size(), 1);
        for(int i=1; i<ratings.size(); i++){
            if(ratings[i]>ratings[i-1]){
                num[i] = num[i-1] + 1;
            }
        }
        for(int i=ratings.size()-1; i>=1; i--){
            if(ratings[i]<ratings[i-1]){
                num[i-1] = max(num[i-1], num[i] + 1);
            }
        }
        return std::accumulate(num.begin(), num.end(), 0);
    }
};

int main() {
    // g++ Solution.cpp -o Solution
    Solution s;

    vector<int> ratings1 = {1, 0, 2};
    std::cout<<s.candy(ratings1)<<endl;

    vector<int> ratings2 = {1, 2, 2};
    std::cout<<s.candy(ratings2)<<endl;

    vector<int> ratings3 = {1};
    std::cout<<s.candy(ratings3)<<endl;
}
