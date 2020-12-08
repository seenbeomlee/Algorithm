import java.util.*;

// 7
// 0110100
// 0110101
// 1110101
// 0000111
// 0100000
// 0111110
// 0111000

// 3
// 7
// 8
// 9
class Point {
  public int x, y;
  public int is;
  public int cluster;

  public Point(int x, int y, int is) {
    this.x = x;
    this.y = y;
    this.is = is;
    this.cluster = 0;
  }
}

class Main {
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    int N = scn.nextInt();
    String inputLine;
    String trash;

    Point graph[][] = new Point[N][N];
    int index = 0;
    int[] townNum = new int[N * N];

    trash = scn.nextLine();

    for(int i = 0; i < N; i++) {
      inputLine = scn.nextLine();
      for(int j = 0; j < N; j++) {
        int temp = (int)inputLine.charAt(j);
        if(temp == 48) temp = 0;
        else temp = 1;
        Point inputPoint = new Point(j, i, temp);
        graph[i][j] = inputPoint;
      }
    }

    // System.out.println();

    // for(int i = 0; i < N; i++) {
    //   for(int j = 0; j < N; j++) {
    //     System.out.print(graph[i][j].is);
    //   }
    //   System.out.println();
    // }

    Deque<Point> deque = new ArrayDeque<Point>();
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        if(graph[i][j].is == 1 && graph[i][j].cluster == 0) {
          index++;
          graph[i][j].cluster = index;
          // System.out.println("x: " + graph[i][j].x + " y: " + graph[i][j].y + " cluster: " + graph[i][j].cluster);
          deque.add(graph[i][j]);
        }
        while(!deque.isEmpty()) {
          Point now = deque.poll();
          townNum[index]++;
          // System.out.println("now x: " + now.x + " y: " + now.y + " cluster: " + now.cluster);
          if(now.y > 0) { // i-1, j
            if(graph[now.y-1][now.x].is == 1 && graph[now.y-1][now.x].cluster == 0) {
              deque.add(graph[now.y-1][now.x]);
              graph[now.y-1][now.x].cluster = index;
            }
          }
          if(now.y < N-1) { // i+1, j
            if(graph[now.y+1][now.x].is == 1 && graph[now.y+1][now.x].cluster == 0) {
              deque.add(graph[now.y+1][now.x]);
              graph[now.y+1][now.x].cluster = index;
            }
          }
          if(now.x > 0) { // i, j-1
            if(graph[now.y][now.x-1].is == 1 && graph[now.y][now.x-1].cluster == 0) {
              deque.add(graph[now.y][now.x-1]);
              graph[now.y][now.x-1].cluster = index;
            }
          }
          if(now.x < N-1) { // i, j+1
            if(graph[now.y][now.x+1].is == 1 && graph[now.y][now.x+1].cluster == 0) {
              deque.add(graph[now.y][now.x+1]);
              graph[now.y][now.x+1].cluster = index;
            }
          }
        }
      }
    }
    System.out.println(index);
    Arrays.sort(townNum);
    for(int i = 0; i < N * N; i++) 
      if(townNum[i] != 0) System.out.println(townNum[i]);
  }
}