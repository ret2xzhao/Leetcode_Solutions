/*
Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.

Example 1:
Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.

Example 2:
Input: date = "2019-02-10"
Output: 41

Example 3:
Input: date = "2003-03-01"
Output: 60

Example 4:
Input: date = "2004-03-01"
Output: 61

Constraints:
date.length == 10
date[4] == date[7] == '-', and all other date[i]'s are digits
date represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.
*/

class Solution {
    public int dayOfYear(String date) {
        int[] regularYear = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int[] leapYear    = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        String y   = date.substring(0, 4);
        String m   = date.substring(5, 7);
        String d   = date.substring(8);
        int year   = Integer.parseInt(y);
        int month  = Integer.parseInt(m);
        int day    = Integer.parseInt(d);
        int result = 0;

        if(month == 1) {
            return day;
        }
        else {
            boolean ifLeapYear = isLeapYear(year);
            if(ifLeapYear) {
                for(int i=0; i<month-1; i++) {
                    result = result + leapYear[i];
                }
            }
            else {
                for(int i=0; i<month-1; i++) {
                    result = result + regularYear[i];
                }
            }
        }
        return (result+day);
    }

    public boolean isLeapYear(int year) {
        if (year % 4 != 0) {
            return false;
        } 
        else if (year % 400 == 0) {
            return true;
        }
        else if (year % 100 == 0) {
            return false;
        }
        else {
            return true;
        }
    }
}