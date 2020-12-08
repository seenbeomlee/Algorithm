import java.util.*;

class Main {
  static int index = 0;
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);

    int N = scn.nextInt(); 

    int[] stack = new int[10000];
    String input;
    String trash;
    trash = scn.nextLine();
    for(int i = 0; i < N; i++) {
      input = scn.nextLine();
      String[] in = input.split(" ");
      switch(in[0]) {
        case "push":
          push(stack, in[1]);
          break;
        case "pop":
          System.out.println(pop(stack));
          break;
        case "size":
          System.out.println(size(stack));
          break;
        case "empty":
          System.out.println(empty(stack));
          break;
        case "top":
          System.out.println(top(stack));
          break;
      }
    }
  }

  public static void push(int[] stack, String in) {
    stack[index] = Integer.parseInt(in);
    index++;
  }

  public static int pop(int[] stack) {
    if(empty(stack) == 1) return -1;
    else return stack[--index];
  }

  public static int size(int[] stack) {
    return index;
  }

  public static int empty(int[] stack) {
    if(index == 0) return 1;
    else return 0;
  }

  public static int top(int[] stack) {
    if(empty(stack) == 1) return -1;
    else return stack[index-1];
  }

}
