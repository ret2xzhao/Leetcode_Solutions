/*
Given two strings representing two complex numbers.
You need to return a string representing their multiplication. Note i^2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i^2 + 2 * i = 2i, and you need convert it to the form of 0+2i.

Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i^2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.

Note:
The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in
this form.
*/

class Solution {
    public String complexNumberMultiply(String a, String b) {
        int aReal      = Integer.parseInt(a.substring(0, a.indexOf('+')));
        int aImaginary = Integer.parseInt(a.substring(a.indexOf('+')+1, a.indexOf('i')));
        int bReal      = Integer.parseInt(b.substring(0, b.indexOf('+')));
        int bImaginary = Integer.parseInt(b.substring(b.indexOf('+')+1, b.indexOf('i')));
        return "" + (aReal * bReal - aImaginary * bImaginary) + "+" + (aReal * bImaginary + aImaginary * bReal) + "i";
    }
}