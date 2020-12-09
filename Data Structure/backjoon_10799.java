import java.util.*;

// ()(((()())(())()))(()) 17

// (((()(()()))(())()))(()()) 24

class Main {
    public static void main(String[] args) {
      Scanner scn = new Scanner(System.in);
      String N = scn.nextLine(); 
      int res = 0;
      
      Stack<Character> stack = new Stack<>();
      char prev = '(';
      for(int i = 0; i < N.length(); i++) {
        char in = N.charAt(i);
        if(in == '(') {
          res += 1; // add stick
          stack.push(in);
        } else {
          stack.pop();
          if(prev == '(') res += stack.size() - 1;
        }
        prev = in;
      }

      System.out.print(res);
    }
}