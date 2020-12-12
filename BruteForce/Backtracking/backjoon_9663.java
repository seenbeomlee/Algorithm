// N-Queen with back-tracking algorithm
// see, how i loop 'N' Queens to calculate cases on the board

import java.util.*;

class point implements Comparable<point>{
  int x, y;

  point(int x, int y) {
    this.x = x;
    this.y = y;
  }

  @Override
  public int compareTo(point o) {
    if(this.x > o.x) return -1;
    else if (this.x < o.x) return 1;
    else return o.y - this.y;
  }
}

class Main {
    static int res = 0;
    static int N;

  public static void loop(int row, int[] col) {
    if(row == N) {
      res++;
      return;
    }

    for(int i = 0; i < N; i++) {
      if(check(i, row, col)) {
        col[row] = i;
        loop(row + 1, col);
      }
    }
  }

  public static boolean check(int now, int row, int[] col) {
    boolean res = true;
    for(int i = 0; i < row; i++) {
      if(((row - i) == Math.abs(now - col[i]))|| col[i] == now) res = false;
    }

    return res;
  }

  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    Deque<Integer> deque = new ArrayDeque<Integer>();
    ArrayList<point> list = new ArrayList<point>();

    N = scn.nextInt();
    
    int row = 0;
    int[] col = new int[N];
    loop(row, col);

    System.out.print(res);
  }
}
