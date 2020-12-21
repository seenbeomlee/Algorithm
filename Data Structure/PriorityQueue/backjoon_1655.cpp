#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>

#include <algorithm> // sort
#include <cmath>     // floor
using namespace std;

int N;

int main()
{
    scanf("%d", &N);

    priority_queue<int, vector<int>, greater<int>> min_pq;
    priority_queue<int> max_pq;
    int input;

    if (N == 1) {
        scanf("%d", &input);
        printf("%d\n", input);
    }
    else {
        int first;
        int second;
        scanf("%d", &first);
        printf("%d\n", first);
        scanf("%d", &second);

        if (first > second) swap(first, second);
        printf("%d\n", min(first, second));

        max_pq.push(first);
        min_pq.push(second);
        for (int i = 2; i < N; i++)
        {
            scanf("%d", &input);

            if (max_pq.size() > min_pq.size()) min_pq.push(input);
            else max_pq.push(input);

            if (max_pq.top() > min_pq.top()) {
                int from_max = max_pq.top();
                int from_min = min_pq.top();

                max_pq.pop();
                max_pq.push(from_min);

                min_pq.pop();
                min_pq.push(from_max);
            }

            printf("%d\n", max_pq.top());
        }
    }
}