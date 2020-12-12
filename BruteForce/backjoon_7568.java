import java.util.*;

class People implements Comparable<People>{
  int x, y;

  People(int x, int y) {
    this.x = x;
    this.y = y;
  }

  @Override
  public int compareTo(People o) {
    if(this.x > o.x) return -1;
    else if (this.x < o.x) return 1;
    else return o.y - this.y;
  }
}

class Main {
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);

    int N = scn.nextInt();
    People[] list = new People[N];
    for(int i = 0; i < N; i++) {
      People temp = new People(scn.nextInt(), scn.nextInt());
      list[i] = temp;
    }

    //Arrays.sort(list);

    for(int i = 0; i < N; i++) {
      //System.out.println(i + "th people: " + list[i].x + " " + list[i].y);
      int res = 0;
      for(int j = 0; j < N; j++) {
        if(list[j].y > list[i].y && list[j].x > list[i].x) res++;
      }
      System.out.println(res + 1);
    }
  }
}
