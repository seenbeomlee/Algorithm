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
  public static int find(int[][] now, int N, int M) {
    int num = 0;
    Deque<point> deque = new ArrayDeque<point>();

    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        if(now[i][j] == 2) {
          point temp = new point(j, i);
          deque.add(temp);
        }
      }
    }

    while(!deque.isEmpty()) {
      point temp = deque.pop();
      
      //System.out.println("x: " + temp.x + " y: " + temp.y + " " + now[temp.y][temp.x]);
      now[temp.y][temp.x] = 2;
      if(temp.y > 0 && now[temp.y-1][temp.x] == 0) {
        point q = new point(temp.x, temp.y-1);
        deque.add(q);
      }
      if(temp.y < N-1 && now[temp.y+1][temp.x] == 0) {
        point w = new point(temp.x, temp.y+1);
        deque.add(w);
      }
      if(temp.x > 0 && now[temp.y][temp.x-1] == 0) {
        point e = new point(temp.x-1, temp.y);
        deque.add(e);
      }
      if(temp.x < M-1 && now[temp.y][temp.x+1] == 0) {
        point r = new point(temp.x+1, temp.y);
        deque.add(r);
      }
    }

    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        if(now[i][j] == 0) {
          num++;
        }
      }
    }

    return num;
  }

  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    Deque<Integer> deque = new ArrayDeque<Integer>();

    int N = scn.nextInt();
    int M = scn.nextInt();

    int[][] arr = new int[N][M];
    ArrayList<point> pointList = new ArrayList<point>();

    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        arr[i][j] = scn.nextInt();
        if(arr[i][j] == 0) {
          point temp = new point(j, i);
          pointList.add(temp);
        }
      }
    }

    int res = 0;
    for(int i = 0; i < pointList.size() - 2; i++) {
      for(int j = i + 1; j < pointList.size() - 1; j++) {
        for(int k = j + 1; k < pointList.size(); k++) {
          point inode = pointList.get(i);
          point jnode = pointList.get(j);
          point knode = pointList.get(k);

          int[][] now = new int[N][M];
          for(int q = 0; q < N; q++) {
            now[q] = arr[q].clone();
          }
          now[inode.y][inode.x] = 1;
          now[jnode.y][jnode.x] = 1;
          now[knode.y][knode.x] = 1;

          res = Math.max(res, find(now, N, M));
        }
      }
    }

    System.out.print(res);
  }
}
