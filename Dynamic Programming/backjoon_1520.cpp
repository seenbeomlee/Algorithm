#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <list>

#include <algorithm> // sort
#include <cmath>     // floor
using namespace std;

int N, M;

// 4 5
// 50 45 37 32 30
// 35 50 40 20 25
// 30 30 25 17 28
// 27 24 22 15 10

// 3

class point {
public:
    int x, y;

    point() { ; };
    point(int a, int b) {
        y = a;
        x = b;
    }
};

int main()
{
    scanf("%d %d", &N, &M);

    int** board = new int* [N];
    int** res = new int* [N];

    for (int i = 0; i < N; i++) {
        board[i] = new int[M];
        res[i] = new int[M];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &board[i][j]);
            res[i][j] = 0;
        }
    }

    queue<point> pList;
    point start(0, 0);
    pList.push(start);

    point now;
    while (!pList.empty()) {
        now = pList.front();
        pList.pop();

        // i == now.y, j == now.x
        // top
        if (now.y > 0 && board[now.y][now.x] > board[now.y - 1][now.x]) {
            res[now.y - 1][now.x] = res[now.y - 1][now.x] + 1;
            point next(now.y - 1, now.x);
            pList.push(next);
        }

        // bottom
        if (now.y < N - 1 && board[now.y][now.x] > board[now.y + 1][now.x]) {
            res[now.y + 1][now.x] = res[now.y + 1][now.x] + 1;
            point next(now.y + 1, now.x);
            pList.push(next);
        }

        // left
        if (now.x > 0 && board[now.y][now.x] > board[now.y][now.x - 1]) {
            res[now.y][now.x - 1] = res[now.y][now.x - 1] + 1;
            point next(now.y, now.x - 1);
            pList.push(next);
        }

        // right
        if (now.x < M - 1 && board[now.y][now.x] > board[now.y][now.x + 1]) {
            res[now.y][now.x + 1] = res[now.y][now.x + 1] + 1;
            point next(now.y, now.x + 1);
            pList.push(next);
        }

    }

    printf("%d", res[N - 1][M - 1]);
}


#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <list>

#include <algorithm> // sort
#include <cmath>     // floor
using namespace std;

int N, M;

// 4 5
// 50 45 37 32 30
// 35 50 40 20 25
// 30 30 25 17 28
// 27 24 22 15 10

// 3

class point {
public:
    int x, y;

    point() { ; };
    point(int a, int b) {
        y = a;
        x = b;
    }
};

int main()
{
    scanf("%d %d", &N, &M);

    int** board = new int* [N];
    int** res = new int* [N];

    for (int i = 0; i < N; i++) {
        board[i] = new int[M];
        res[i] = new int[M];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &board[i][j]);
            res[i][j] = -1;
        }
    }

    queue<point> pList;
    point start(0, 0);
    pList.push(start);

    point now;
    while (!pList.empty()) {
        now = pList.front();
        pList.pop();

        // i == now.y, j == now.x
        // top
        if (now.y > 0 && board[now.y][now.x] > board[now.y - 1][now.x]) {
            if (res[now.y - 1][now.x] == -1) {
                res[now.y - 1][now.x] = 0;
                point next(now.y - 1, now.x);
                pList.push(next);
            }


            res[now.y - 1][now.x] = res[now.y - 1][now.x] + 1;

        }

        // bottom
        if (now.y < N - 1 && board[now.y][now.x] > board[now.y + 1][now.x]) {
            if (res[now.y + 1][now.x] == -1) {
                res[now.y + 1][now.x] = 0;
                point next(now.y + 1, now.x);
                pList.push(next);
            }

            res[now.y + 1][now.x] = res[now.y + 1][now.x] + 1;
        }

        // left
        if (now.x > 0 && board[now.y][now.x] > board[now.y][now.x - 1]) {
            if (res[now.y][now.x - 1] == -1) {
                res[now.y][now.x - 1] = 0;
                point next(now.y, now.x - 1);
                pList.push(next);
            }


            res[now.y][now.x - 1] = res[now.y][now.x - 1] + 1;
        }

        // right
        if (now.x < M - 1 && board[now.y][now.x] > board[now.y][now.x + 1]) {
            if (res[now.y][now.x + 1] == -1) {
                res[now.y][now.x + 1] = 0;
                point next(now.y, now.x + 1);
                pList.push(next);
            }


            res[now.y][now.x + 1] = res[now.y][now.x + 1] + 1;
        }

    }

    printf("%d", res[N - 1][M - 1]);
}