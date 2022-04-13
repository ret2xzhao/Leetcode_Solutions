/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

Constraints:
0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(), n=word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // Base conditions:
        for (int i=0; i<m+1; i++) {
            dp[i][0] = i;
        }
        for (int j=0; j<n+1; j++) {
            dp[0][j] = j;
        }
        // Solving the sub-problems:
        for (int i=1; i<m+1; i++) {
            for (int j=1; j<n+1; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    int insertChar = dp[i][j-1];
                    int deleteChar = dp[i-1][j];
                    int replaceChar = dp[i-1][j-1];
                    dp[i][j] = 1 + min({insertChar, deleteChar, replaceChar});
                }
            }
        }
        return dp[m][n];
    }
};