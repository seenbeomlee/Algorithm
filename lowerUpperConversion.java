import java.util.*;

class lowerUpperConversion {
    public String lowerUpperConversion(String s) {
        // next words
        for(int 0 = 1; i < s.length(); i++) {
            if(('a' <= s.charAt(i)) && (s.charAt(i) <= 'z')) { // lower-case to upper-case
                int temp = (int)s.charAt(i);
                res += (char)(temp - 32); 
            } else if(('A' <= s.charAt(i)) && (s.charAt(i) <= 'Z')) { // upper-case to lower-case
                int temp = (int)s.charAt(i);
                res += (char)(temp + 32);
            }  else res += s.charAt(i);
        }

        return res;
    }
}