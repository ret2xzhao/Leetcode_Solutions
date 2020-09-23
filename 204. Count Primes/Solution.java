/*
Count the number of prime numbers less than a non-negative number, n.

Example:
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/

import java.util.Arrays;

public class Solution{
    /* Time Limit Exceeded
    int countPrimes(int n) {
        int count = 0;
        for(int i=2; i<n; i++){
            if(isPrime(i)){
                count++;
            }
        }
        return count;
    }

    boolean isPrime(int num){
        for(int i=2; i*i<=num; i++){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }
    */

    int countPrimes(int n) {
        boolean[] isPrime = new boolean[n];
        Arrays.fill(isPrime, true);
        for(int i=2; i*i<n; i++) {
            if(isPrime[i]) {
                for(int j=2*i; j<n; j+=i) {
                    isPrime[j] = false;
                }
            }
        }
        int count=0;
        for(int i=2; i<n; i++){
            if(isPrime[i]) count++;
        }
        return count;
    }
}