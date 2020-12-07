import java.util.*;

class Main {
  private static long[] dp = new long[5001];

  public static void main(String[] args) {
    
    Scanner scn = new Scanner(System.in); 
    int N = scn.nextInt(); 
    long res = 0;

    res = fibo(N);

    System.out.println(res);
  }

  public static long fibo(int N) {
    if(dp[N] != 0) return dp[N];
    if(N == 0) return 0;
    if(N == 1) return 1;

    dp[N-1] = fibo(N-1);
    dp[N-2] = fibo(N-2);
    return dp[N-1] + dp[N-2];
  }
}