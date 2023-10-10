# include <iostream>

struct Point {
    public: int x, y, z;
    Point(int x, int y, int z) : x(x), y(y), z(z) {};
    Point (int x) : x(x){
        x = 3;
    };
};

int main(){
    Point A(1, 2, 3);
    A.x = 3;

    std::cout << A.x << std::endl;

    return 0;
};