#include <cstdio>
#include <iostream> // -> cin/cout의 속도가 scanf/printf의 속도보다 약 7배 느리다. 따라서, 이 경우 시간초과

using namespace std;

void hanoi(int N, int S, int O, int E);

int main() {
  int N;
  scanf("%d", &N);

  // S O E

  // S E O
  // O S E
  // 1 2 3

  printf("%d\n", ((1<<N) - 1));
  hanoi(N, 1, 2, 3);

}

void hanoi(int N, int S, int O, int E) {
  if(N == 1) {
    printf("%d %d\n", S, E);
  } else {
    hanoi(N-1, S, E, O);
    printf("%d %d\n", S, E);
    hanoi(N-1, O, S, E);
  }
}