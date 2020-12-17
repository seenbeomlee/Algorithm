#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

int res = 0;

class point {
public:
    int x, y;

    point() { ; }
    point(int a, int b) {
        x = a;
        y = b;
    }
};

void find(vector<vector<int>> board, vector<point> pList, int pIndex);

vector<int> cal(vector<vector<int>> board, vector<point> pList, int pIndex);

int main() {
    vector<vector<int>> board;
    vector<point> pList;
    int pIndex = 0;

    int temp;
    for (int i = 0; i < 9; i++) {
        vector<int> row;
        for (int j = 0; j < 9; j++) {
            scanf("%d", &temp);
            row.push_back(temp);

            if (temp == 0) {
                point p(j, i);
                pList.push_back(p);
            }
        }
        board.push_back(row);
    }

    vector<int> list = cal(board, pList, pIndex);

    for (int i = 0; i < list.size(); i++) {
        board[pList[pIndex].y][pList[pIndex].x] = list[i];
        find(board, pList, pIndex);
    }
}

void find(vector<vector<int>> board, vector<point> pList, int pIndex) {
    pIndex++;

    if (pIndex == pList.size()) {
        if (res == 0) {
            res = 1;
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    printf("%d ", board[i][j]);
                }
                printf("\n");
            }
        }
        return;
    }

    vector<int> list = cal(board, pList, pIndex);

    for (int i = 0; i < list.size(); i++) {
        board[pList[pIndex].y][pList[pIndex].x] = list[i];
        find(board, pList, pIndex);
    }
}

vector<int> cal(vector<vector<int>> board, vector<point> pList, int pIndex) {
    vector<int> list;
    int rowIndex = pList[pIndex].y / 3 * 3;
    int colIndex = pList[pIndex].x / 3 * 3;
    for (int i = 1; i <= 9; i++) {
        bool is = false;
        for (int j = 0; j < 9; j++) {
            if (board[pList[pIndex].y][j] == i) {
                is = true;
                break;
            }
        } if (is) continue;
        for (int j = 0; j < 9; j++) {
            if (board[j][pList[pIndex].x] == i) {
                is = true;
                break;
            }
        } if (is) continue;
        for (int j = rowIndex; j < rowIndex + 3; j++) {
            for (int k = colIndex; k < colIndex + 3; k++) {
                if (board[j][k] == i) {
                    is = true;
                    break;
                }
            }
        } if (is) continue;

        list.push_back(i);
    }
    return list;
}