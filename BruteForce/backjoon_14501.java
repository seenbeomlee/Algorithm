import java.util.*;

class Resrv implements Comparable<Resrv>{
  int x, y;

  Resrv(int x, int y) {
    this.x = x;
    this.y = y;
  }

  @Override
  public int compareTo(Resrv o) {
    if(this.x > o.x) return -1;
    else if (this.x < o.x) return 1;
    else return o.y - this.y;
  }
}

class Main {
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);

    int N = scn.nextInt();
    Resrv[] list = new Resrv[N];
    for(int i = 0; i < N; i++) {
      Resrv temp = new Resrv(scn.nextInt(), scn.nextInt());
      list[i] = temp;
    }

    int[] dp = new int[N+1];
    for(int i = 0; i < N+1; i++) {
      for(int j = 0; j < i; j++) {
        if(j + (list[j].x - 1) < i)
          dp[i] = Math.max(dp[i], list[j].y + dp[j]);
      }
      //System.out.print("dp" + i + " : " + dp[i]);
    }
    if(list[N-1].x == 1) dp[N-1] += list[N-1].y;
    System.out.print(dp[N]);
  }
}
