#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

int N, M;

int main() {
  string input;
  cin >> input;

  string temp = "";
  bool minus = false;
  int res = 0;
  for(int i = 0; i <= input.length(); i++) {
    //cout << "now: " << res << endl;
    if(input[i] == '-' || input[i] == '+' || input[i] == '\0') {
      if(temp != "") {
        if(minus) res -= stoi(temp);
        else res += stoi(temp);
      }
      
      temp = "";
      if(input[i] == '-') minus = true;
    } else {
      temp += input[i];
    }
  }

  cout << res;
} 