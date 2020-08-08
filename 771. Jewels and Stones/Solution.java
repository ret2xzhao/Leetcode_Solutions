/*
You're given strings J representing the types of stones that are jewels, and S representing the stones you have. Each character
in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.
The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is
considered a different type of stone from "A".

Example 1:
Input: J = "aA", S = "aAAbbbb"
Output: 3

Example 2:
Input: J = "z", S = "ZZ"
Output: 0

Note:
S and J will consist of letters and have length at most 50.
The characters in J are distinct.
*/

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

class Solution {
    public int numJewelsInStones1(String J, String S) {
        int result=0;
        HashMap<Character, Integer> stone = new HashMap<Character, Integer>();
        for(int i=0; i<S.length(); i++) {
            stone.put(S.charAt(i), stone.getOrDefault(S.charAt(i), 0)+1);
        }
        HashMap<Character, Integer> jewel = new HashMap<Character, Integer>();
        for(int i=0; i<J.length(); i++) {
            jewel.put(J.charAt(i), jewel.getOrDefault(J.charAt(i), 0)+1);
        }
        Set<Map.Entry<Character, Integer>> set = jewel.entrySet();
        for(Map.Entry<Character, Integer> s1 : set) {
            if(stone.containsKey(s1.getKey())) {
                result = result + stone.get(s1.getKey());
            }
        }
        return result;
    }

    public int numJewelsInStones2(String J, String S) {
        int count = 0;
        for(char s: S.toCharArray()){
            if(J.indexOf(s) >= 0) {
                count++;
            }
        }
        return count;
    }
}