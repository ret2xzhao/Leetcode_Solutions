/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]

Constraints:
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non-decreasing array.
-10^9 <= target <= 10^9
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            return {-1, -1};
        }
        int lowerBound = searchLowerBound(nums, target);
        int upperBound = searchUpperBound(nums, target);
        if((nums[upperBound]!=target) || (nums[lowerBound]!=target)){
            return {-1, -1};
        }
        else{
            return {lowerBound, upperBound};
        }
    }

    int searchLowerBound(vector<int>& nums, int target){
        int left=0, right=nums.size()-1, mid;
        while(left<right){
            mid = left+(right-left)/2;
            if(nums[mid] >= target){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return right;
    }

    int searchUpperBound(vector<int>& nums, int target){
        int left=0, right=nums.size()-1, mid;
        while(left<right){
            mid = left+(right-left+1)/2;
            if(nums[mid] <= target){
                left=mid;
            }
            else{
                right=mid-1;
            }
        }
        return right;
    }
};
