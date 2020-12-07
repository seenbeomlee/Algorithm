import java.util.*;

class Main {
  private static int[] dp = new int[5001];

  public static void main(String[] args) {
    
    Scanner scn = new Scanner(System.in); 
    int N = scn.nextInt(); 
    int res = 0;

    int[][] para = new int[N][];
    int[][] resPara = new int[N][];
    for(int i = 0; i < N; i++) {
      para[i] = new int[i + 1];
      resPara[i] = new int[i + 1];
    }

    for(int i = 0; i < N; i++) {
      for(int j = 0; j <= i; j++) {
        para[i][j] = scn.nextInt();
        resPara[i][j] = para[i][j];
      }
    }

    int left;
    int right;
    int top;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j <= i; j++) {
        if(i > 0 && j > 0) {
          left = resPara[i-1][j-1];
        } else left = -1;
        if(i > 0 && j < i) {
          right = resPara[i-1][j];
        } else right = -1;
        top = Math.max(left, right);
        if(top == -1) top = 0;
        resPara[i][j] = top + para[i][j];
      }
    }
    
    for(int i = 0; i < N; i++) res = Math.max(res, resPara[N-1][i]);
    System.out.println(res);
  }
}