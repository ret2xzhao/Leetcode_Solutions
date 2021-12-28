/*
The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer n, return its complement.

Example 1:
Input: n = 5
Output: 2
Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.

Example 2:
Input: n = 7
Output: 0
Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.

Example 3:
Input: n = 10
Output: 5
Explanation: 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.

Constraints:
0 <= n < 10^9
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){return 1;}       
        // Decimal to Binary(reverse order):
        vector<int> binary;
        while(n){
            if(n%2 == 1) {
                binary.push_back(1);
            }
            else {
                binary.push_back(0);
            }
            n = n / 2;
        }
        
        // Complement:
        for(int i=0; i<binary.size(); i++){
            if(binary[i] == 0){
                binary[i] = 1;
            }
            else{
                binary[i] = 0;
            }
        }

        // Binary to Decimal:
        int result = 0, size=binary.size()-1;
        for(int i=0; i<binary.size(); i++){
            result += binary[i] * pow(2, i);
        }
        return result;
    }
};
