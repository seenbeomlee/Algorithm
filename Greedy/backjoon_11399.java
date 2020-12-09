import java.util.*;

// 5
// 3 1 4 3 2

// 32

class Main {
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    int t = scn.nextInt(); 
    int res = 0;
    int[] Pi = new int[t];
    int[] totali = new int[t];

    for(int i = 0; i < t; i++) {
      Pi[i] = scn.nextInt();
    }

    Arrays.sort(Pi);
    for(int i = 0; i < Pi.length; i++) {
      for(int j = i; j < Pi.length; j++) {
        totali[j] += Pi[i];
      }
    }

    for(int i = 0; i < Pi.length; i++) {
      res += totali[i];
    }

    System.out.print(res);
  }
}