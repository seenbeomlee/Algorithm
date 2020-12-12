import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    int N = scn.nextInt();
    String trash = scn.nextLine();

    for(int i = 0; i < N; i++) {
      String input = scn.nextLine();
      int res = 0;
      int point = 0;
      for(int j = 0; j < input.length(); j++) {
        if(input.charAt(j) == 'O') {
          point++;
          res += point;
        } else {
          point = 0;
        }
      }
      System.out.println(res);
    }
  }
}