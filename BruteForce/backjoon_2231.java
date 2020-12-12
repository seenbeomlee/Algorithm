import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);

    int N = scn.nextInt();
    int mid;
    int now;

    for(int i = 0; i < N; i++) {
      mid = now = i;

      while(now > 0) {
        mid += now % 10;
        now /= 10;
      }

      if(mid == N) {
        System.out.print(i);
        break;
      }
      if(i == N - 1) System.out.print(0);
    }
  }
}
