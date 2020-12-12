import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    int input = 1;

    input *= scn.nextLong();
    input *= scn.nextLong();
    input *= scn.nextLong();

    int[] res = new int[10];
    while(input > 0) {
      res[input % 10]++;
      input /= 10;
    }

    for(int i = 0; i < 10; i++)
      System.out.println(res[i]);
  }
}