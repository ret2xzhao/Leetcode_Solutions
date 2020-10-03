/*
A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part,
and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

Note:
S will have length in range [1, 500].
S will consist of lowercase English letters ('a' to 'z') only.
*/

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> partitionLabels(String S) {
        List<Integer> list = new ArrayList<Integer>();
        int[] count = new int[26];
        for(int i=0; i<S.length(); i++) {
            count[S.charAt(i) - 'a'] = i;
        }
        int start=0, end=0;
        for(int i=0; i<S.length(); i++) {
            end = Math.max(count[S.charAt(i) - 'a'], end);
            if(i == end) {
                list.add(end-start+1);
                start = end + 1;
                end = 0;
            }
        }
        return list;
    }
}