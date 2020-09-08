/*
Given two binary strings, return their sum (also a binary string).
The input strings are both non-empty and contains only characters 1 or 0.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

Constraints:
Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*/

class Solution {
    public String addBinary(String a, String b) {
        StringBuilder str = new StringBuilder();
        int len_a = a.length()-1;
        int len_b = b.length()-1;
        int carry = 0;
        while(len_a>=0 || len_b>=0) {
            int sum = carry;
            if(len_a>=0) {
                sum += a.charAt(len_a--)-'0';
            }
            if(len_b>=0) {
                sum += b.charAt(len_b--)-'0';
            }
            carry = sum/2;
            str.append(sum%2);
        }
        if(carry == 1) {
            str.append(carry);
        }
        return str.reverse().toString();
    }
}