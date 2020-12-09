import java.util.*;

// 3
// 1 0
// 5
// 4 2
// 1 2 3 4
// 6 0
// 1 1 9 1 1 1

// 1
// 2
// 5
class point {
  int num;
  int index;

  point(int num, int index) {
    this.num = num;
    this.index = index;
  }
}

class Main {
    public static void main(String[] args) {
      Scanner scn = new Scanner(System.in);
      int t = scn.nextInt(); 
      int N;
      int M;

      for(int i = 0; i < t; i++) {
        N = scn.nextInt();
        M = scn.nextInt();
        Queue<point> queue = new LinkedList<>();

        int index = 0;
        int order = 0;
        Integer[] temp_list = new Integer[N];
        ArrayList<Integer> index_list = new ArrayList<>();
        
        for(int j = 0; j < N; j++) {
          temp_list[j] = scn.nextInt();

          point temp = new point(j, temp_list[j]);

          queue.add(temp);
        }

        for(int data : temp_list) { // 중복 제거, duplicated array
          if(!index_list.contains(data)) index_list.add(data);
        }

        Collections.sort(index_list); // ArrayList sort asc
        Collections.reverse(index_list); // ArrayList sort asc -> ArrayList sort desc
        // for(Integer temp: index_list) {
        //   System.out.print(temp + " ");
        // }

        point now;
        ww: 
        while(true) {
          now = queue.poll();

          if(now.index < index_list.get(index)) {
            queue.add(now);
          } else {
            order++;
            if(now.num == M) {
              System.out.println(order);
              break ww;
            }
          }

          //index++;
          // queue to ArrayList / convert queue to ArrayList
          // queue cannot get object from index
          boolean contain = false;
          ArrayList<point> queue_list = new ArrayList(queue);
          for(int j = 0; j < queue.size(); j++) {
            if(queue_list.get(j).index == index_list.get(index)) contain = true;
          }
          if(!contain) index++;
        } // while
      }
    }
}