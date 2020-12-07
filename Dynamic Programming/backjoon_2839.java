import java.util.*;

class Main {
  private static int[] dp = new int[5001];

  public static void main(String[] args) {
    
    Scanner scn = new Scanner(System.in); 
    int N = scn.nextInt(); 
    int res = 9999;

    res = Math.min(res, find(N));

    if(res == 9999) res = -1;
    System.out.println(res);
  }

  public static int find(int N) {
    if(dp[N] != 0) return dp[N];
    else if(N == 3 || N == 5) return 1;
    else if(N < 5) return 9999;

    return dp[N] = Math.min(find(N - 3), find(N - 5)) + 1;
  }
}