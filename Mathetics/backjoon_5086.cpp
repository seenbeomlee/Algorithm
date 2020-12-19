#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

int N, M;

int main() {
  int a, b;

  while(1) {
    cin >> a >> b;

    if(a == 0 && b == 0) break;
    if(b % a == 0) cout << "factor" << endl;
    else if(a % b == 0) cout << "multiple" << endl;
    else cout << "neither" << endl;
  }
} 