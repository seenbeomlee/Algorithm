// 오름차순 정렬

import java.util.*;

class Main {
    static int res = 0;
    static int N;

  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);

    N = scn.nextInt();
    int[] arr = new int[N];

    for(int i = 0; i < N; i++) {
      arr[i] = scn.nextInt();
    }

    Arrays.sort(arr);

    for(int i = 0; i < N; i++) {
      System.out.println(arr[i]);
    }
  }
}
