/*
Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array
is unique.

Example 1:
Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

Example 2:
Input: arr = [1,2]
Output: false

Example 3:
Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true

Constraints:
1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
*/

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Solution {
    public boolean uniqueOccurrences1(int[] arr) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i=0; i<arr.length; i++) {
            map.put(arr[i], map.getOrDefault(arr[i], 0)+1);
        }
        ArrayList<Integer> occurrencesList = new ArrayList<Integer>(map.values());
        if(occurrencesList.size() == 1) {
            return true;
        }
        Collections.sort(occurrencesList);
        for(int i=0; i+1<occurrencesList.size(); i++) {
            if(occurrencesList.get(i)>=occurrencesList.get(i+1)) {
                return false;
            }
        }
        return true;
    }

    public boolean uniqueOccurrences2(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : arr) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        Set<Integer> set = new HashSet<Integer>(map.values());
        return map.size() == set.size();
    }
}