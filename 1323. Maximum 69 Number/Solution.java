/*
Given a positive integer num consisting only of digits 6 and 9.
Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

Example 1:
Input: num = 9669
Output: 9969
Explanation:
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.

Example 2:
Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.

Example 3:
Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.

Constraints:
1 <= num <= 10^4
num's digits are 6 or 9.
*/

import java.util.ArrayList;

public class Solution {
    public int maximum69Number (int num) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        while(num != 0) {
            list.add(num % 10);
            num = num / 10;
        }
        int result = 0;
        boolean flag = false;
        for(int i=list.size()-1; i>=0; i--) {
            if(list.get(i) == 9 || flag == true) {
                result = (int) (result + list.get(i) * Math.pow(10, i));
            }
            else if(list.get(i) == 6 && flag == false){
                result = (int) (result + 9 * Math.pow(10, i));
                flag = true;
            }
        }
        return result;
    }
}