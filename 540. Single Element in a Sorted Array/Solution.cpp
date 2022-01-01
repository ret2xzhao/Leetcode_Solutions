/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: nums = [3,3,7,7,10,11,11]
Output: 10

Constraints:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/

#include <iostream>
#include <vector>

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0, right=nums.size()-1, mid;
        while (left<right) {
            mid = left+(right-left)/2;
            bool rHalfIsEven = (right-mid)%2==0;
            if(nums[mid]==nums[mid-1]){
                if(rHalfIsEven){
                    right = mid-2;
                }
                else{
                    left = mid+1;
                }
            }
            else if(nums[mid]==nums[mid+1]){
                if(rHalfIsEven){
                    left = mid+2;
                }
                else{
                    right = mid-1;
                }
            }
            else{
                return nums[mid];
            }
        }
        return nums[right];
    }
};