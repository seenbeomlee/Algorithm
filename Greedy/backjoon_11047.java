import java.util.*;

// 10 4200
// 1
// 5
// 10
// 50
// 100
// 500
// 1000
// 5000
// 10000
// 50000

// 6

// 10 4790
// 1
// 5
// 10
// 50
// 100
// 500
// 1000
// 5000
// 10000
// 50000

// 12

class Main {
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    int num_coins = scn.nextInt();
    int total = scn.nextInt();
    int res = 0;

    int[] coins = new int[num_coins];
    for(int j = 0; j < num_coins; j++) coins[j] = scn.nextInt();

    for(int j = num_coins - 1; j > 0; j--) {
      while(total >= coins[j]) {
        res += 1;
        total -= coins[j];
      }
    }

    res += total;
    System.out.println(res);
  }
}