import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);

    int N = scn.nextInt();
    int M = scn.nextInt();

    int[] cards = new int[N];
    for(int i = 0; i < N; i++) {
      cards[i] = scn.nextInt();
    }

    Arrays.sort(cards);
    int length = cards.length;
    for(int i = 0; i < length; i++) {
      if(cards[i] > M) {
        length = i;
        break;
      }
    }

    int res = 0;
    int now = 0;
    for(int i = 0; i < length - 2; i++) {
      for(int j = i + 1; j < length - 1; j++) {
        for(int k = j + 1; k < length; k++) {
          now = cards[i] + cards[j] + cards[k];

          if(now <= M && now > res) res = now;
        }
      }
    }
    System.out.print(res);
  }
}