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

            if (input <= max_pq.top()) max_pq.push(input);
            else if (input >= min_pq.top()) min_pq.push(input); 
            else {
                if (max_pq.size() == min_pq.size()) max_pq.push(input);
                else max_pq.size() > min_pq.size() ?
                    min_pq.push(input) : max_pq.push(input);
            }

            //cout << "min_pq.size(): " << min_pq.size() << endl;
            //cout << "max_pq.size(): " << max_pq.size() << endl;
            //cout << "min_pq.size() - max_pq.size(): " << (min_pq.size()) - (max_pq.size()) << endl;
            //cout << "min_pq.size() - max_pq.size(): " << (int)min_pq.size() - (int)max_pq.size() << endl;


            if ((int)min_pq.size() - (int)max_pq.size() > 0) {
                max_pq.push(min_pq.top());
                min_pq.pop();
            }
            else if ((int)max_pq.size() - (int)min_pq.size() > 1) {
                min_pq.push(min_pq.top());
                max_pq.pop();
            }
            printf("%d\n", max_pq.top());
        }
    }
}