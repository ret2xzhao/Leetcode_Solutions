/*
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and
"Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal".
For the left two athletes, you just need to output their relative ranks according to their scores.

Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.
*/

import java.util.Arrays;
import java.util.HashMap;

class Solution {
    public String[] findRelativeRanks(int[] nums) {
        int[] temp = new int[nums.length];
        String[] result = new String[nums.length];
        for(int i=0; i<nums.length; i++) {
            temp[i] = nums[i];
        }
        Arrays.sort(temp);
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i=0; i<temp.length; i++) {
            map.put(temp[i], temp.length-i);
        }
        for(int i=0; i<nums.length; i++) {
            if(map.get(nums[i]) == 1) {
                result[i] = "Gold Medal";
            }
            else if(map.get(nums[i]) == 2) {
                result[i] = "Silver Medal";
            }
            else if(map.get(nums[i]) == 3) {
                result[i] = "Bronze Medal";
            }
            else {
                result[i] = "" + map.get(nums[i]);
            }
        }
        return result;
    }
}