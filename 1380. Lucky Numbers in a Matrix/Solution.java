/*
Given a m * n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

Example 1:
Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.

Example 2:
Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.

Example 3:
Input: matrix = [[7,8],[1,2]]
Output: [7]

Constraints:
m == matrix.length
n == matrix[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 10^5.
All elements in the matrix are distinct.
*/

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        List<Integer> result = new ArrayList<Integer>();
        int[] minInRow = new int[matrix.length];
        int[] maxInColumn = findMaxInColumn(matrix);
        for(int i=0; i<matrix.length; i++) {
            Arrays.sort(matrix[i]);
            minInRow[i] = matrix[i][0];
        }
        for(int i=0; i<minInRow.length; i++) {
            for(int j=0; j<maxInColumn.length; j++) {
                if(minInRow[i] == maxInColumn[j]) {
                    result.add(minInRow[i]);
                }
            }
        }
        return result;
    }

    public int[] findMaxInColumn(int[][] matrix) {
        int index=0;
        int[] maxInColumn = new int[matrix[0].length];
        for(int i=0; i<matrix[0].length; i++) {
            int maxNumber = Integer.MIN_VALUE;
            for(int j=0; j<matrix.length; j++) {
                maxNumber = Math.max(maxNumber, matrix[j][i]);
            }
            maxInColumn[index++] = maxNumber;
            maxNumber = 0;
        }
        return maxInColumn;
    }
}