import java.util.*;

// i think only DFS is correct.
// class Main {
//   public static void main(String[] args) {
//     Scanner scn = new Scanner(System.in);

//     int N = scn.nextInt(); 
//     int M = scn.nextInt();
//     String inputLine;
//     String trash;

//     int[][] graph = new int[N][M];
//     int[][] dp = new int[N][M];

//     trash = scn.nextLine();

//     for(int i = 0; i < N; i++) {
//       inputLine = scn.nextLine();
//       for(int j = 0; j < M; j++) {
//         // convert string 11011 to int 1 1 0 1 1
//         int temp = (int)inputLine.charAt(j);
//         if(temp == 48) temp = 0;
//         else temp = 1;
//         graph[i][j] = temp; 
//         if(graph[i][j] == 0) dp[i][j] = 9999;
//       }
//     }

//     // for(int i = 0; i < N; i++) {
//     //   for(int j = 0; j < M; j++) {
//     //     System.out.print(graph[i][j]);
//     //   }
//     //   System.out.println();
//     // }

//     // for(int i = N - 1; i >= 0; i--) {
//     //   for(int j = M - 1; j >= 0; j--) {
//     //     int min = 9999;
//     //     if(i == 0 && j == 0) dp[i][j] = 1;
//     //     if(i > 0) min = Math.min(min, dp[i-1][j]);
//     //     if(i < N-1) min = Math.min(min, dp[i+1][j]);
//     //     if(j > 0) min = Math.min(min, dp[i][j-1]);
//     //     dp[i][j] = min;
//     //   }
//     // }

//     System.out.print(find(graph, dp, N-1, M-1, N, 0) + 1);
//   }

//   public static int find(int[][] graph, int[][] dp, int i, int j, int N, int from) {
//     //  1
//     //     2
//     //  3
//     if(i == 0 && j == 0) return dp[0][0] = 0;
//     if(graph[i][j] == 0) return dp[i][j];
//     //if(dp[i][j] != 0) return dp[i][j];
//     int min = 9999;
//     if(i > 0 && from != 1) min = Math.min(min, find(graph, dp, i-1, j, N, 3));
//     if(i < N-1 && from != 3) min = Math.min(min, find(graph, dp, i+1, j, N, 1));
//     if(j > 0) min = Math.min(min, find(graph, dp, i, j-1, N, 2));
//     return dp[i][j] = min + 1;
//   }
// }

import java.util.*;

class node {
  public int x, y;
  public int is;
  public int num;
  public boolean visited;

  node(int j, int i, int num, int num2, boolean bool) {
    this.x = j;
    this.y = i;
    this.is = num;
    this.num = num2;
    this.visited = bool;
  }
}

class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int N = scn.nextInt(); 
        int M = scn.nextInt();
        String inputLine;
        String trash;

        node[][] graph = new node[N][M];
        node[][] sec_graph = new node[N][M];

        trash = scn.nextLine();

        for(int i = 0; i < N; i++) {
            inputLine = scn.nextLine();
            for(int j = 0; j < M; j++) {
                // convert string 11011 to int 1 1 0 1 1
                int num = (int)inputLine.charAt(j);
                if(num == 48) num = 0;
                else num = 1;
                node temp = new node(j, i, num, 9999, false);
                graph[i][j] = temp; 
            }
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
              sec_graph[i][j] = graph[i][j];
            }
        }

        int res = 9999;
        if(graph[1][0].is == 1) res = Math.min(res, DFS(graph, graph[1][0], N, M));
        if(graph[0][1].is == 1) res = Math.min(res, DFS(sec_graph, sec_graph[0][1], N, M));

        System.out.print(res + 2);
    }

    public static int DFS(node[][] graph, node first, int N, int M) {
      Deque<node> deque = new ArrayDeque<node>();
      node now;
      first.num = 0;
      first.visited = true;
      deque.add(first);
      while(!deque.isEmpty()) {
        now = deque.poll();
        //now.visited = true;
        //System.out.println("now : " + now.x + now.y + now.num);

        if(now.y > 0 && !graph[now.y-1][now.x].visited && graph[now.y-1][now.x].is == 1) {
          //System.out.println("A : " + now.x + now.y + now.num);
          graph[now.y-1][now.x].num = Math.min(graph[now.y-1][now.x].num, now.num + 1);
          graph[now.y-1][now.x].visited = true;
          deque.add(graph[now.y-1][now.x]);
        }
        if(now.x < M-1 && !graph[now.y][now.x+1].visited && graph[now.y][now.x+1].is == 1) {
          //System.out.println("B : " + now.x + now.y + now.num);
          graph[now.y][now.x+1].num = Math.min(graph[now.y][now.x+1].num, now.num + 1);
          graph[now.y][now.x+1].visited = true;
          deque.add(graph[now.y][now.x+1]);
        }
        if(now.y < N-1 && !graph[now.y+1][now.x].visited && graph[now.y+1][now.x].is == 1) {
          //System.out.println("C : " + now.x + now.y + now.num);
          graph[now.y+1][now.x].num = Math.min(graph[now.y+1][now.x].num, now.num + 1);
          graph[now.y+1][now.x].visited = true;
          deque.add(graph[now.y+1][now.x]);
        }
      }

      return graph[N-1][M-1].num;
    }
}