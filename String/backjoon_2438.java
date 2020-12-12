import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    int N = scn.nextInt();

    for(int i = 0; i < N; i ++) {
      for(int j = 0; j <= i; j++) {
        System.out.print("*");
      }
      System.out.println();
    }

  }
}