#include"K_closest.cpp"
#include"queue"

int main(){
    std::vector<Point> points = {Point(1, 2, 3), Point(3, 4, 5), Point(5, 6, 7), Point(-1, -2, -3), Point(-3, -4, -5)};
    int k = 3;


    std::cout << "imput data: " << "k = " << k <<", ";
    for (const Point& point : points) {
        std::cout << "(" << point.x << ", " << point.y << ", " << point.z << ") ";
    }
    std::cout << std::endl;

    std::vector<Point> closestPoints = find_k_closest(points, k);

    std::cout << "Closest points to the origin: ";
    for (const Point& point : closestPoints) {
        std::cout << "(" << point.x << ", " << point.y << ", " << point.z << ") ";
    }
    std::cout << std::endl;

    return 0;
}