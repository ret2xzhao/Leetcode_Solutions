/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr]
of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

Constraints:
1 <= target <= 10^9
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int sum = 0;
        for (int i=0, j=0; i<nums.size(); i++) {
            sum += nums[i];
            while (sum - nums[j] >= target) {
                sum -= nums[j];
                j++;
            }
            if (sum >= target) {
                res = min(res, i-j+1);
            }
        }
        return res != INT_MAX? res : 0;
    }
};

int main(){

    Solution s;

    int target1 = 7;
    std::vector<int> nums1= {2,3,1,2,4,3};
    std::cout << s.minSubArrayLen(target1, nums1) << std::endl;

    int target2 = 4;
    std::vector<int> nums2= {1,4,4};
    std::cout << s.minSubArrayLen(target2, nums2) << std::endl;

    int target3 = 11;
    std::vector<int> nums3= {1,1,1,1,1,1,1,1};
    std::cout << s.minSubArrayLen(target3, nums3) << std::endl;
}