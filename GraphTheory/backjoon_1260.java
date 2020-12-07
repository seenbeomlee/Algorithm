import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);

    int N = scn.nextInt(); 
    int M = scn.nextInt(); 
    int V = scn.nextInt();

    int[][] graph = new int[N][N];
    for(int i = 0; i < M; i++) {
      int from = scn.nextInt(); 
      int to = scn.nextInt();
      graph[from - 1][to - 1] = 1;
      graph[to - 1][from - 1] = 1;
    }

    int[][] graphDFS = new int[N][N];
    int[][] graphBFS = new int[N][N];

    graphDFS = graph.clone();
    graphBFS = graph.clone();

    DFS(graphDFS, N, V);
    System.out.println();
    BFS(graphBFS, N, V);

  }

  public static void DFS(int[][] graph, int N, int V) {
    //stack
    //https://coding-factory.tistory.com/601?category=758267
    Stack<Integer> stack = new Stack<>();
    int now = V - 1;
    stack.push(V - 1);

    while(!stack.isEmpty()) {
      now = stack.pop();
      System.out.print(now + 1 + " ");
      for(int i = N - 1; i >= 0; i--) {
        if(graph[now][i] == 1) {
          stack.push(i);
          graph[now][i] = 0;
          for(int j = 0; j < N; j++)
            graph[i][j] = 0;
        }
      }
    }
    //deque
  }

  public static void BFS(int[][] graph, int N, int V) {
    //queue
    //https://coding-factory.tistory.com/602
    Queue<Integer> queue = new LinkedList<>();
    int now = V - 1;
    queue.add(V - 1);

    while(!queue.isEmpty()) {
      now = queue.remove();
      System.out.print(now + 1 + " ");
      for(int i = 0; i < N; i++) {
        if(graph[now][i] == 1) {
          queue.add(i);
          graph[now][i] = 0;
          for(int j = 0; j < N; j++)
            graph[i][j] = 0;
        }
      }
    }
    //deque
  }
}