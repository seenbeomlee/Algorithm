import java.util.*;

/* string을 split하는 방법 -> StringTokenizer 이용 */

class Main {
  public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
 
		String S = scn.nextLine();
		scn.close();
 
		// st 에 공백을 기준으로 나눈 토큰들을 st 에 저장한다
		StringTokenizer st = new StringTokenizer(S," ");
		
		// countTokens() 는 토큰의 개수를 반환한다
		System.out.println(st.countTokens());	
  }
}