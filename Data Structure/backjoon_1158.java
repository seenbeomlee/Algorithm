import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int N = scn.nextInt(); 
        int K = scn.nextInt();
        int index = K;

        LinkedList<Integer> list = new LinkedList<Integer>();

        for(int i = 1; i <= N; i++) {
          list.add(i);
        }

        System.out.print("<");
        while(list.size() > 1) {
          if(index > list.size()) {
            index -= list.size();
            continue;
          }
          System.out.print(list.get(index - 1) + ", ");
          list.remove(index - 1);
          index += K - 1;
        }
        System.out.print(list.get(0) + ">");

    }
}