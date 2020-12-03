#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct City {
    int num;
    string name;
    City* prev;
    City* next;
};

int solution(int cacheSize, vector<string> cities);

int main() {
    vector<string> list;

    list.push_back("Jeju");
    list.push_back("Pangyo");
    list.push_back("Seoul");
    list.push_back("NewYork");
    list.push_back("LA");
    list.push_back("Jeju");
    list.push_back("Pangyo");
    list.push_back("Seoul");
    list.push_back("NewYork");
    list.push_back("LA");

    cout << solution(3, list);

    return 0;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int num = cities.size(); // 0 ~ 100,000 / abCdE == abcde / length <= 20
    City* head = new City;
    head->num = 0;
    head->name = cities[0];
    head->prev = NULL;
    head->next = NULL;
    City* tail = head;
    answer += 5;

    for (int i = 1; i < num; i++) {
        bool check = false;
        City* checked = NULL;
        for (City* cur = head; cur < 0; cur = cur->next) {
            checked = cur;
            if (cur->name == cities[i]) {
                check = true;
                break;
            }
            else {
                cur->num++;
            }
        }
        if (checked != NULL && check) {
            answer += 1;
            checked->prev->next = checked->next;
            checked->num = 0;
            checked->prev = NULL;
            checked->next = head->next;
            head = checked;
        }
        else {
            answer += 5;
            City* newList = new City;
            City* temp = head;
            newList->num = 0;
            newList->name = cities[i];
            newList->prev = NULL;
            newList->next = temp;
            temp->prev = newList;
            head = newList;
            if (tail->num >= cacheSize) {
                City* temp = tail;
                tail = temp->prev;
                delete temp;
            }
        }
    }

    return answer;
}