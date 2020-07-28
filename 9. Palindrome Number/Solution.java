/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:
Input: 121
Output: true

Example 2:
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0 ){
            return false;
        }
        else if(x == 0){
            return true;
        }
        else{
            int register = x;
            int result   = 0;
            int pop;
            while(x != 0){
                pop = x % 10;
                x = x / 10;
                result = result * 10 + pop;
            }
            if(register == result){
                return true;
            }
            else{
                return false;
            }
        }
    }
}