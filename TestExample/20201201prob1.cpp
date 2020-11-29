/* 두 문자열 (string)을 입력 받고, 두 문자열이 철자를 바꾼 것인지 체크하는 함수를 작성하시오.
"abc", "cba"의 res = true */

#include<iostream>
#include<string>
using namespace std;

void check_same(int* list_a, int* list_b);

int main() {
    string a, b;
    // ASCII code 0 ~ 127
    int* list_a = new int[128]();
    int* list_b = new int[128]();

    cin >> a >> b;

    for (string::iterator iter = a.begin(); iter != a.end(); iter++) list_a[*iter]++;
    for (string::iterator iter = b.begin(); iter != b.end(); iter++) list_b[*iter]++;

    check_same(list_a, list_b);

    delete[] list_a;
    delete[] list_b;

    return 0;
}

void check_same(int* list_a, int* list_b) {
    for (int i = 0; i < 128; i++) {
        if (list_a[i] != list_b[i]) {
            cout << "false" << endl;
            return;
        }
    }
    cout << "true" << endl;
}