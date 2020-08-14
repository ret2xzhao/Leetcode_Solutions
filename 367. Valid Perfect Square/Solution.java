/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.
Follow up: Do not use any built-in library function such as sqrt.

Example 1:
Input: num = 16
Output: true

Example 2:
Input: num = 14
Output: false

Constraints:
1 <= num <= 2^31 - 1
*/

class Solution {
    public boolean isPerfectSquare(int num) {
        int result = mySqrt(num);
        if(result*result == num){
            return true;
        }
        else{
            return false;
        }
    }

    public int mySqrt(int x) {
        if(x<2){
            return x;
        }
        int left=0, right=x, mid;
        while(left+1<right){
            mid = left+(right-left)/2;
            if(x/mid >= mid){
                left = mid;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
}