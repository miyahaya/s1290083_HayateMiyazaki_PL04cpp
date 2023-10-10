# include <iostream>

struct Point {
    public: int x, y, z;
    Point(int x, int y, int z) : x(x), y(y), z(z) {}
}

void main(){
    Point A;
    A.x = 1;

    std::cout << A.x << std::endl;
}