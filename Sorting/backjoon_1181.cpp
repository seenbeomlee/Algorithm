#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

int N, M;

bool compare(string& A, string& B) {
  if(A.length() < B.length()) return true;
  else if(A.length() > B.length()) return false;
  else {
    return A < B;
  }
}

int main() {
  scanf("%d", &N);

  vector<string> s_list;

  char* temp = new char[51];
  for(int i = 0; i < N; i++) {
    scanf("%s", temp);
      
    string s_new(temp);

    bool is = false;
    for(int j = 0; j < s_list.size(); j++) {
      if(s_list[j] == s_new) is = true;
    }
    
    if(!is) s_list.push_back(s_new);
  }

  sort(s_list.begin(), s_list.end(), compare);

  for(int i = 0; i < s_list.size(); i++) {
    printf("%s\n", s_list[i].c_str());
  }
}