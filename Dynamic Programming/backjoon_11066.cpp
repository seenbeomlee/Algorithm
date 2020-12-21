#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <list>

#include <algorithm> // sort
#include <cmath>     // floor
using namespace std;

int N, K;
int res = 999999999;

void find(list<int> fileList, int value) {
    if (fileList.size() == 1) {
        res = min(res, value);
        return;
    }

    for (int j = 0; j < fileList.size() - 1; j++) {
        list<int>::iterator nowIt = fileList.begin();
        list<int>::iterator nextIt = fileList.begin();
        for (int k = 0; k < j; k++) {
            nowIt++;
            nextIt++;
        }
        nextIt++;
        int nowValue = *nowIt;
        int nextValue = *nextIt;
        *nowIt = *nowIt + *(nextIt);
        fileList.erase(nextIt);

        find(fileList, value + *nowIt);

        *nowIt = nowValue; // revert
        fileList.insert(++nowIt, nextValue); // revert
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &K);

        list<int> fileList;
        int input;
        res = 999999999;
        for (int j = 0; j < K; j++) {
            scanf("%d", &input);
            fileList.push_back(input);
        }

        for (int j = 0; j < fileList.size() - 1; j++) {
            int value = 0;
            list<int>::iterator nowIt = fileList.begin();
            list<int>::iterator nextIt = fileList.begin();
            for (int k = 0; k < j; k++) {
                nowIt++;
                nextIt++;
            }
            nextIt++;
            int nowValue = *nowIt;
            int nextValue = *nextIt;
            *nowIt = *nowIt + *(nextIt);
            fileList.erase(nextIt);

            find(fileList, value + *nowIt);

            *nowIt = nowValue; // revert
            fileList.insert(++nowIt, nextValue); // revert
        }

        printf("%d\n", res);
    }
}