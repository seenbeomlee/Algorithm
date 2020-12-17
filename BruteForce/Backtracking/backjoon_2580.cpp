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
    // pIndex++

    // endPoint check

    // row check
    // col check
    // square check
    // if not possible -> return;
    // possible array -> for loop

    // i == pList[pIndex].y
    // j == pList[pIndex].x
    vector<int> rowList;
    vector<int> colList;
    vector<int> squareList;
    vector<int> possibleList;
    for (int j = 0; j < 9; j++) {
        if (j == pList[pIndex].x || board[pList[pIndex].y][j] == 0) continue;
        rowList.push_back(board[pList[pIndex].y][j]);
    }
    for (int i = 0; i < 9; i++) {
        if (i == pList[pIndex].y || board[i][pList[pIndex].x] == 0) continue;
        colList.push_back(board[i][pList[pIndex].x]);
    }

    // 012 345 678
    // i == pList[pIndex].y % 3 * 3
    int rowIndex = pList[pIndex].y / 3 * 3;
    int colIndex = pList[pIndex].x / 3 * 3;
    for (int i = rowIndex; i < rowIndex + 3; i++) {
        for (int j = colIndex; j < colIndex + 3; j++) {
            if ((i == pList[pIndex].y && j == pList[pIndex].x) || board[i][j] == 0) continue;
            squareList.push_back(board[i][j]);
        }
    }

    for (int i = 1; i <= 9; i++) {
        bool is = false;
        for (int j = 0; j < rowList.size(); j++) {
            if (i == rowList[j]) {
                is = true;
                break;
            }
        }
        if (!is) possibleList.push_back(i);
    }

    for (int i = 0; i < possibleList.size(); i++) {
        for (int j = 0; j < colList.size(); j++) {
            if (possibleList[i] == colList[j]) possibleList[i] = 0;
        }
        for (int j = 0; j < squareList.size(); j++) {
            if (possibleList[i] == squareList[j]) possibleList[i] = 0;
        }
    }

    vector<int> list;
    for (int i = 0; i < possibleList.size(); i++) {
        if (possibleList[i] != 0) list.push_back(possibleList[i]);
    }

    return list;
}