/*
请实现一个函数，把字符串s中的每个空格替换成"%20"。

示例 1：
输入：s = "We are happy."
输出："We%20are%20happy."

限制：
0 <= s 的长度 <= 10000
*/

class Solution {
    public String replaceSpace1(String s) {
        return s.replaceAll(" ","%20");
    }

    public String replaceSpace2(String s) {
        String result = "";
        for(int i=0; i<s.length(); i++) {
            if(Character.isWhitespace(s.charAt(i))) {
                result += "%20";
            }
            else {
                result += s.charAt(i);
            }
        }
        return result;
    }

    public String replaceSpace3(String s) {
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<s.length(); i++) {
            if(Character.isWhitespace(s.charAt(i))) {
                sb.append("%20");
            }
            else {
                sb.append(s.charAt(i));
            }
        }
        return sb.toString();
    }
}