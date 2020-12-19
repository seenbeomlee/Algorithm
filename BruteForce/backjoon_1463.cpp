#include <cstdio>

#include <iostream>
#include <string>

using namespace std;

int M, N;

int main() {
  cin >> M;
  long i = 666;
  int res = 0;

  while(1) {
    if(!(to_string(i).find("666") == std::string::npos)) res++;
    if(res == M) break;
    i++;
  }

  cout << i;
}