/* 2차원 좌표계 상의 점들의 (x, y) 좌표들의 배열을 받아 다른 점들과 가장 가까이 있는 점들로 소팅된 배열을 반환하는 함수를 작성하시오.
(1,1), (5,4), (3,3)의 res = (3,3), (5,4), (1,1) */

/* 
17

1 1
3 3
4 0
4 2
5 4
5 0
6 5
8 0
8 5
8 10
8 15
9 17
15 3
15 0
16 2
16 16
17 15

value of dist square can be wrong, but it does not affect to the sequence
point: ( 4, 0 ) dist square: 1
point: ( 5, 0 ) dist square: 1
point: ( 3, 3 ) dist square: 2
point: ( 4, 2 ) dist square: 2
point: ( 5, 4 ) dist square: 2
point: ( 6, 5 ) dist square: 2
point: ( 15, 3 ) dist square: 2
point: ( 16, 2 ) dist square: 2
point: ( 16, 16 ) dist square: 2
point: ( 17, 15 ) dist square: 2
point: ( 8, 15 ) dist square: 5
point: ( 9, 17 ) dist square: 5
point: ( 15, 0 ) dist square: 5
point: ( 1, 1 ) dist square: 8
point: ( 8, 0 ) dist square: 25
point: ( 8, 5 ) dist square: 25
point: ( 8, 10 ) dist square: 25
*/

#include<iostream>
#include<algorithm>
#include<deque>
#include<set>
#include <random>
using namespace std;

class point {
private:
    int x, y, dist;

public:
    point() { ; };
    point(int a, int b) {
        x = a;
        y = b;
        dist = INT_MAX;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    int getDist() {
        return dist;
    }
    void setDist(int in) {
        dist = in;
    }
};

struct compare {
    bool operator() (reference_wrapper<point> A, reference_wrapper<point> B) const {
        if (A.get().getY() == B.get().getY())  {
            return A.get().getX() < B.get().getX();
        }
        else {
            return A.get().getY() < B.get().getY();
        }
    }
};

bool comp_x_y(point& A, point& B) {
    if (A.getX() < B.getX()) return true;
    else if (A.getX() > B.getX()) return false;
    else return A.getY() < B.getY();
}

bool comp_dist(point& A, point& B) {
    if (A.getDist() < B.getDist()) return true;
    else return false;
}

int cal_dis(point& A, point& B) {
    int dist = pow(A.getX() - B.getX(), 2) + pow(A.getY() - B.getY(), 2);
    if (dist < A.getDist()) A.setDist(dist);
    if (dist < B.getDist()) B.setDist(dist);
    return dist;
}

void sort_algorithm(deque <point>& plist, deque<point>& res_list);

int main() {
    int N; /* # of points */
    int x, y; /* point cordinates */
    deque<point> input_list;
    deque<point> res_list;

    //cin >> N;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 10000);
    for (int i = 0; i < 10000; i++) {
        x = dis(gen);
        y = dis(gen);
        //cin >> x >> y;
        point temp(x, y);
        input_list.push_back(temp);
    }

    sort(input_list.begin(), input_list.end(), comp_x_y); // x 오름차순 -> y 오름차순 정렬

    while (input_list.size() > 1) {
        sort_algorithm(input_list, res_list);
    }

    if (!input_list.empty()) {
        res_list.push_back(input_list.back());
    }

    sort(res_list.begin(), res_list.end(), comp_dist); // sort by dist
    cout << "value of dist square can be wrong, but it does not affect to the sequence" << endl;
    for (point p : res_list) cout << "point: ( " << p.getX() << ", " << p.getY() << " ) dist square: " << p.getDist() << endl;
    return 0;
}

void sort_algorithm(deque<point>& input_list, deque<point>& res_list) {
    set<reference_wrapper<point>, compare> candidate = { input_list[0], input_list[1] };
    int shortest = cal_dis(input_list[0], input_list[1]);
    int start = 0;
    int list_size = input_list.size();
    for (int i = 2; i < list_size; i++) {
        point& now = input_list[i];
        while (start < i) {
            point p = input_list[start];
            int distX = now.getX() - p.getX();
            if (distX * distX > shortest) {
                candidate.erase(p);
                start += 1;
            }
            else { // if it has any point inside the square
                break;
            }
        }

        int temp_d = (int)sqrt((double)shortest) + 1;
        point lower_point = point(-100000, now.getY() - temp_d);
        point upper_point = point(100000, now.getY() + temp_d);
        set<reference_wrapper<point>>::iterator lower = candidate.lower_bound(lower_point);
        set<reference_wrapper<point>>::iterator upper = candidate.upper_bound(upper_point);
        for (set<reference_wrapper<point>>::iterator it = lower; it != upper; it++) {
            int dist = cal_dis(now, (*it).get());
            if (dist < shortest) {
                shortest = dist;
            }
        }
        reference_wrapper<point> temp = now;
        candidate.insert(temp);
    }

    /* if dist is updated, point will be removed from input_list and push to res_list to avoid dup check*/
    for (deque<point>::iterator it = input_list.begin(); it != input_list.end();) {
        if (it->getDist() != INT_MAX) {
            point temp = *it;
            res_list.push_back(temp);
            it = input_list.erase(it);
        }
        else {
            it++;
        }
    }
}