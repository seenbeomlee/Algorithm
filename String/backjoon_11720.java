import java.util.*;

/* convert 'char' to 'int' in java */
/* java 에서 char형을 int형으로 바꾸는 방법 */

class Main {
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    String trash = scn.nextLine();
    String N = scn.nextLine();
    int res = 0;

    for(int i = 0; i < N.length(); i ++) {
      res += (N.charAt(i) - '0');
    }

    System.out.print(res);
  }
}