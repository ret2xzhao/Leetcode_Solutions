/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:
Input: [2,2,1]
Output: 1

Example 2:
Input: [4,1,2,1,2]
Output: 4
*/

import java.util.HashMap;

class Solution {
    public int singleNumber1(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        int length = nums.length;
        for(int i=0; i<length; i++) {
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
        }
        for(int i=0; i<length; i++) {
            if(map.get(nums[i]) == 1) {
                return nums[i];
            }
        }
        return -1;
    }

    public int singleNumber2(int[] nums) {
        int result = 0;
        for(int i : nums) {
            result ^= i;
        }
        return result;
    }
}