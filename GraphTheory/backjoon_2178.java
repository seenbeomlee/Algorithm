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

class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int N = scn.nextInt(); 
        int M = scn.nextInt();
        String inputLine;
        String trash;

        int[][] graph = new int[N][M];
        int[][] dp = new int[N][M];

        trash = scn.nextLine();

        for(int i = 0; i < N; i++) {
            inputLine = scn.nextLine();
            for(int j = 0; j < M; j++) {
                // convert string 11011 to int 1 1 0 1 1
                int temp = (int)inputLine.charAt(j);
                if(temp == 48) temp = 0;
                else temp = 1;
                graph[i][j] = temp; 
                if(graph[i][j] == 0) dp[i][j] = 9999;
            }
        }
    }
}