import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);

    int[] height =  new int[9];

    for(int i = 0; i < 9; i++) height[i] = scn.nextInt();

    Arrays.sort(height);

    here: for(int i = 0; i < 3; i++) {
      for(int j = i + 1; j < 4; j++) {
        for(int k = j + 1; k < 5; k++) {
          for(int a = k + 1; a < 6; a++) {
            for(int b = a + 1; b < 7; b++) {
              for(int c = b + 1; c < 8; c++) {
                for(int d = c + 1; d < 9; d++) {
                  if(height[i] +
                  height[j] +
                  height[k] +
                  height[a] +
                  height[b] +
                  height[c] +
                  height[d] == 100) {
                    System.out.println(height[i]);
                    System.out.println(height[j]);
                    System.out.println(height[k]);
                    System.out.println(height[a]);
                    System.out.println(height[b]);
                    System.out.println(height[c]);
                    System.out.println(height[d]);
                    break here;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}