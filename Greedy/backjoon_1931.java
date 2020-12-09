import java.util.*;

// 11
// 1 4
// 3 5
// 0 6
// 5 7
// 3 8
// 5 9
// 6 10
// 8 11
// 8 12
// 2 13
// 12 14

// 4

class meeting {
  long start;
  long end;
  meeting(long start, long end) {
    this.start = start;
    this.end = end;
  }
}

class Main {
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    int N = scn.nextInt(); // 1 <= N <= 100,000
    int res = 0;
    long start;
    long end;
    long current = 0;
    long last_start = 0;

    meeting[] list = new meeting[N];
    for(int i = 0; i < N; i++) {
      start = scn.nextLong();
      end = scn.nextLong();
      meeting temp = new meeting(start, end);
      list[i] = temp;

      last_start = Math.max(last_start, start);
    }

    // end asc -> start asc
    // current < object.start 면서, end가 가장 low한 회의 선택
    while(current <= last_start) {
      meeting selected = null;
      for(int i = 0; i < N; i++) {
        if(list[i].start >= current && (selected == null || (list[i].end < selected.end))) {
          selected = list[i];
        }
      }

      current = selected.end;
      res++;
    }

    System.out.print(res);
  }
}