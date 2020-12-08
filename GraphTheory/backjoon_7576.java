import java.util.*;

// 6 4
// 1 -1 0 0 0 0
// 0 -1 0 0 0 0
// 0 0 0 0 -1 0
// 0 0 0 0 -1 1

// 6

class Point {
  public int x, y;
  public int is;

  public Point(int x, int y, int is) {
    this.x = x;
    this.y = y;
    this.is = is;
  }
}

class Main {
  public static int prev_total_0num = 0;

  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    int M = scn.nextInt();
    int N = scn.nextInt();
    int days = 0;
    //int total0num = 0;

    Point[][] graph = new Point[N][M];

    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        Point point = new Point(j, i, scn.nextInt());
        graph[i][j] = point;
      }
    }

    //scan -> '0' || BFS 1 -> scan -> BFS 1 -> scan .. '-1'
    while(!scan(graph, N, M)) {
      days++;
      if(BFS(graph, N, M)) {
        System.out.print("-1");
        System.exit(0);
      }
    }
    System.out.print(days);
  }

  static boolean BFS(Point[][] graph, int N, int M) {
    Deque<Point> deque = new ArrayDeque<Point>();
    int total_num = 0;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        if(graph[i][j].is == 1) deque.add(graph[i][j]);
        else if(graph[i][j].is == 0) total_num++;
      }
    }

    if(prev_total_0num == total_num) return true; // if cannot reached

    while(!deque.isEmpty()) {
      Point now = deque.poll();
      if(now.y > 0) { // i-1, j
        if(graph[now.y-1][now.x].is == 0) {
          graph[now.y-1][now.x].is = 1;
        }
      }
      if(now.y < N-1) { // i+1, j
        if(graph[now.y+1][now.x].is == 0) {
          graph[now.y+1][now.x].is = 1;
        }
      }
      if(now.x > 0) { // i, j-1
        if(graph[now.y][now.x-1].is == 0) {
          graph[now.y][now.x-1].is = 1;
        }
      }
      if(now.x < N-1) { // i, j+1
        if(graph[now.y][now.x+1].is == 0) {
          graph[now.y][now.x+1].is = 1;
        }
      }
    }

    prev_total_0num = total_num;
    return false;
  }

  static boolean scan(Point[][] graph, int N, int M) {
    // for Debug
    // for(int i = 0; i < N; i++) {
    //   for(int j = 0; j < M; j++) {
    //     System.out.print(graph[i][j].is + " ");
    //   }
    //   System.out.println();
    // }
    // System.out.println();

    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        if(graph[i][j].is == 0) return false; // not finished
      }
    }
    return true; // if finished
  }
}