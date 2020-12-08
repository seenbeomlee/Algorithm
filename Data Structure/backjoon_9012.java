import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    int N = scn.nextInt(); 

    String input;
    String trash;
    trash = scn.nextLine();
    for(int i = 0; i < N; i++) {
      Stack<String> stack = new Stack<>();
      input = scn.nextLine();
      int j;
      for(j = 0; j < input.length(); j++) {
        if(input.charAt(j) == '(') {
          stack.push("(");
        }
        else {
          if(stack.empty()) {
            System.out.println("NO");
            break;
          }
          stack.pop();
        }
      }
      if(j == input.length() && stack.empty()) System.out.println("YES");
      else if(j == input.length())System.out.println("NO");
    }

  }
}
