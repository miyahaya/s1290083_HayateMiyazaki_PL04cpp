#include"K_closest.h"
#include<algorithm>
#include<queue>

bool Compare::operator()(const Point& p1, const Point& p2){
    if((p2.x*p2.x+p2.y*p2.y+p2.z*p2.z) - (p1.x*p1.x+p1.y*p1.y+p1.z*p1.z) > 0){
        return true;
    }
    else return false;
}

std::vector<Point> find_k_closest(const std::vector<Point>& points, int k) {
    std::priority_queue<Point, std::vector<Point>, Compare> pq;

    for (const Point& point : points) {
        pq.push(point);

        if (pq.size() > k) {
            pq.pop();
        }
    }

    std::vector<Point> result;
    while (!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }

    // 結果を元の順序に戻す
    std::reverse(result.begin(), result.end());

    return result;
}