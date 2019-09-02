Lint_417. Valid Number.java

public class Solution {
    /**
     * @param s: the string that represents a number
     * @return: whether the string is a valid number
     */
    public boolean isNumber(String s) {
        // write your code here
        if (s == null) return false;
        
        int i = 0;
        s = s.trim() + " "; // 数组多开一位，防止越界
        char[] sc = s.toCharArray();
        int len = s.length()-1;
        
        if (sc[i] == '+' || sc[i] == '-')
            i++;
        
        int nDigit = 0, nPoint = 0;
        while(Character.isDigit(sc[i]) || sc[i] =='.') {
            if (Character.isDigit(sc[i])) {
                nDigit++;
            }
            
            if (sc[i] == '.') {
                nPoint++;
            }
            i++;
        }
        if (nPoint > 1 || nDigit <=0) {
            return false;
        }
        
        if (sc[i] == 'e') {
            i++;
            if (sc[i] == '+' || sc[i] =='-') {
                i++;
            }
            
            for(;i< len; i++) {
                if (!Character.isDigit(sc[i])) {
                    return false;
                }
            }
        }
        
        return i == len;
    }
}