import java.util.*;

/* java 에서, array의 모든 element를 N으로 초기화하고 싶다면 */
/* Arrays.fill(arr, N)을 사용한다 */

class Main {
  public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
 
		String S = scn.nextLine();

    int[] arr = new int[26];
    Arrays.fill(arr, -1);
    for(int i = 0; i < S.length(); i++) {
      if(arr[S.charAt(i) - 'a'] == -1) {
        arr[S.charAt(i) - 'a'] = i;
      }
    }

    for(int i = 0; i < 26; i++) {
      System.out.print(arr[i] + " ");
    }

		scn.close();	
  }
}