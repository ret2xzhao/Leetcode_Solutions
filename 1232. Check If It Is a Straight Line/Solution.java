/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a
straight line in the XY plane.

Example 1:
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Example 2:
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false

Constraints:
2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.
*/

public class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        if(coordinates.length == 2) {
            return true;
        }
        else {
            int y2 = coordinates[1][1];
            int y1 = coordinates[0][1];
            int x2 = coordinates[1][0];
            int x1 = coordinates[0][0];
            double slope1, slope2;
            if(y2-y1 == 0){
                slope1 = 0;
            }
            else if(x2-x1 == 0) {
                slope1 = -1;
            }
            else {
                slope1 = (double)(y2 - y1)/(x2 - x1);
            }
            for(int i=2; i<coordinates.length; i++) {
                if(coordinates[i][1]-y1 == 0) {
                    slope2 = 0;
                }
                else if(coordinates[i][0]-x1 == 0) {
                    slope2 = -1;
                }
                else {
                    slope2 = (double)(coordinates[i][1]-y1)/(coordinates[i][0]-x1);
                }
                if(slope1 != slope2) {
                    return false;
                }
            }
            return true;
        }
    }
}