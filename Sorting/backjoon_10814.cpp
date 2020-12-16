#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

int N, M;

class user {
  public:
    int age;
    int num;
    char* name;

    user() {;}
    user(int a, int n, char* na) {
      age = a;
      n = num;
      name = na;
    }
};

bool compare(user& A, user& B) {
  if(A.age > B.age) return false;
  else if (B.age > A.age) return true;
  else {
    return A.num > B.num;
  }
}

int main() {
  scanf("%d", &N);

  vector<user> u_list;

  int age;
  for(int i = 0; i < N; i++) {
    char* s_new = new char[101];
    scanf("%d %s", &age, s_new);
    user temp(age, i, s_new);
    u_list.push_back(temp);
  }

  sort(u_list.begin(), u_list.end(), compare);

  for(int i = 0; i < u_list.size(); i++) {
    printf("%d %s\n", u_list[i].age, u_list[i].name);
  }
    
}