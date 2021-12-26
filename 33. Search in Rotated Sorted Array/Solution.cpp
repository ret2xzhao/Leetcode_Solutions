/*
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and
become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1

Constraints:
1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-10^4 <= target <= 10^4
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1, mid;
        while(left<right){
            mid = (left+right+1) / 2;
            if(nums[mid]>=nums[0]){
                left = mid;
            }
            else {
                right = mid - 1;
            }
        }
        if(target>=nums[0]){
            left=0;
        }
        else{
            left=right+1, right=nums.size()-1;
        }
        while(left<right){
            mid = (left+right) / 2;
            if(nums[mid]>=target){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        if(nums[right] == target){return right;}
        return -1;
    }
};

int main() {
    // g++ Solution.cpp -o Solution
    Solution s;

    vector<int> nums1 = {4,5,6,7,0,1,2};
    int target1 = 0;
    std::cout<<s.search(nums1, target1)<<endl;

    vector<int> nums2 = {4,5,6,7,0,1,2};
    int target2 = 3;
    std::cout<<s.search(nums2, target2)<<endl;
    
    vector<int> nums3 = {1};
    int target3 = 0;
    std::cout<<s.search(nums3, target3)<<endl;
}
