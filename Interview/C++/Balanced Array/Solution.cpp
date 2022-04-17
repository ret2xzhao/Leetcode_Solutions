/*
Given an array of numbers, find the index of the smallest array element(the pivot), for which the sums of all elements to the left and to the right are equal.
The array may not be reordered.

Example 1:
array = [1,2,3,4,6] 
index = 3
    - The sum of the first three elements, 1+2+3=6. The value of the last element is 6.
    - Using zero-based indexing, array[3]=4 is the pivot between the two subarrays.
    - The index of the pivot is 3.

Example 2:
array = [1,2,3,3] 
index = 2

Example 3:
array = [1,2,1] 
index = 1

Function Description:
balancedSum has the following parameter(s):
    int array[n]: an array of n integers

Returns:
    An integer representing the index of the pivot

Constrainst:
    - 3 <= n <= 10^5
    - 1 <= array[i] <= 2*10^4, where 0 <= i < n
    - It is guaranteed that a solution always exists.
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int balancedSum(vector<int> array) {
    int leftSum = 0, totalSum = 0;
    totalSum = accumulate(array.begin(), array.end(), 0);
    for (int i=0; i<array.size(); ++i) {
        if (leftSum == totalSum-array[i]-leftSum) {
            return i;
        }
        leftSum += array[i];
    }
    return -1;
}

int main() {
    // g++ Solution.cpp -o Solution

    std::vector<int> array1 = {1,2,3,4,6};
    std::cout << balancedSum(array1) << std::endl;

    std::vector<int> array2 = {1,2,3,3};
    std::cout << balancedSum(array2) << std::endl;
    
    std::vector<int> array3 = {1,2,1};
    std::cout << balancedSum(array3) << std::endl;
}