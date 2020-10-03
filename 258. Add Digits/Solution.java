/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:
Input: 38
Output: 2
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2.
             Since 2 has only one digit, return it.
*/

class Solution {
    public int addDigits(int num) {
        int digit;
        while(num != 0){
            if(num<10){return num;}
            digit = num%10;
            num = num/10 + digit;
        }
        return 0;
    }
}