import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);

    int N = scn.nextInt(); 
    int M = scn.nextInt(); 
    int V = scn.nextInt();

    int[] checkList = new int[N];

    int[][] graph = new int[N][N];
    int[][] graphDFS = new int[N][N];
    int[][] graphBFS = new int[N][N];

    for(int i = 0; i < M; i++) {
      int from = scn.nextInt(); 
      int to = scn.nextInt();
      graph[from - 1][to - 1] = 1;
      graph[to - 1][from - 1] = 1;

      graphDFS[from - 1][to - 1] = 1;
      graphDFS[to - 1][from - 1] = 1;

      graphBFS[from - 1][to - 1] = 1;
      graphBFS[to - 1][from - 1] = 1;
    }

    DFS(graphDFS, checkList, N, V);
    System.out.println();
    Arrays.fill(checkList, 0); // init to 0
    BFS(graphBFS, checkList, N, V);

  }

  public static void DFS(int[][] graph, int[] checkList, int N, int V) {
    //stack
    //https://coding-factory.tistory.com/601?category=758267
    Stack<Integer> stack = new Stack<>();
    int now = V - 1;
    stack.push(V - 1);

    while(!stack.isEmpty()) {
      now = stack.pop();
      if(checkList[now] == 0) {
        System.out.print(now + 1 + " ");
        checkList[now] = 1;
      }
      for(int i = N - 1; i >= 0; i--) {
        if(graph[now][i] == 1) {
          stack.push(i);
          graph[now][i] = 0;
        }
      }
    }
    //deque
  }

  public static void BFS(int[][] graph, int[] checkList, int N, int V) {
    //queue
    //https://coding-factory.tistory.com/602
    Queue<Integer> queue = new LinkedList<>();
    int now = V - 1;
    queue.add(V - 1);

    while(!queue.isEmpty()) {
      now = queue.remove();
      if(checkList[now] == 0) {
        System.out.print(now + 1 + " ");
        checkList[now] = 1;
      }
      for(int i = 0; i < N; i++) {
        if(graph[now][i] == 1) {
          queue.add(i);
          graph[now][i] = 0;
        }
      }
    }
    //deque
  }
}