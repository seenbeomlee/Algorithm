import java.util.*;

class Main {
    static int res = 0;
    static int N;

  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);

    N = scn.nextInt();
    int length = (Integer.toString((Integer)N).length());
    int[] arr = new int[length];

    for(int i = 0; i < arr.length; i++) {
      arr[i] = N % 10;
      N /= 10;
    }

    Arrays.sort(arr);
    for(int i = arr.length-1; i >= 0; i--) {
      System.out.print(arr[i]);
    }
  }
}
