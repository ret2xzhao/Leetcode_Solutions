/*
You are given a 0-indexed integer array nums and a target element target.
A target index is an index i such that nums[i] == target.
Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list.
The returned list must be sorted in increasing order.

Example 1:
Input: nums = [1,2,5,2,3], target = 2
Output: [1,2]
Explanation: After sorting, nums is [1,2,2,3,5].
The indices where nums[i] == 2 are 1 and 2.

Example 2:
Input: nums = [1,2,5,2,3], target = 3
Output: [3]
Explanation: After sorting, nums is [1,2,2,3,5].
The index where nums[i] == 3 is 3.

Example 3:
Input: nums = [1,2,5,2,3], target = 5
Output: [4]
Explanation: After sorting, nums is [1,2,2,3,5].
The index where nums[i] == 5 is 4.

Constraints:
1 <= nums.length <= 100
1 <= nums[i], target <= 100
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        int lowerBound = searchLowerBound(nums, target);
        int upperBound = searchUpperBound(nums, target);
        if(nums[lowerBound]!=target){
            return result;
        }
        for(int i=lowerBound; i<=upperBound; ++i){
            result.push_back(i);
        }
        return result;
    }
    
    int searchLowerBound(vector<int>& nums, int target){
        int left=0, right=nums.size()-1, mid;
        while(left<right){
            mid = left+(right-left)/2;
            if(nums[mid] >= target){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return right;
    }
    
    int searchUpperBound(vector<int>& nums, int target){
        int left=0, right=nums.size()-1, mid;
        while(left<right){
            mid = left+(right-left+1)/2;
            if(nums[mid] <= target){
                left = mid;
            }
            else{
                right = mid-1;
            }
        }
        return right;
    }
};