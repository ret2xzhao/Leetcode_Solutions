/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:
Input: [3,0,1]
Output: 2

Example 2:
Input: [9,6,4,2,3,5,7,0,1]
Output: 8
*/

import java.util.HashSet;
import java.util.Set;

class Solution {
    public int missingNumber1(int[] nums) {
        int total = (1+nums.length)*nums.length/2;
        int sum = 0;
        for(int i=0; i<nums.length; i++) {
            sum = sum + nums[i];
        }
        return total - sum;
    }

    public int missingNumber2(int[] nums) {
        Set<Integer> numSet = new HashSet<Integer>();
        for(int num : nums) {
            numSet.add(num);
        }
        int result = nums.length + 1;
        for(int i=0; i<result; i++) {
            if(!numSet.contains(i)) {
                return i;
            }
        }
        return -1;
    }
}