#include <iostream>
#include <string>
// #include "queue.h"
#include "queue.cpp"
using namespace std;

void cal(string operate, queue &que){
    if(operate == "enqueue"){
//        cout << "Please enter the 3 number" << endl;
        int x, y, z;
        cin >> x;
        cin >> y;
        cin >> z;
        Point P = Point(x,y,z);
        que.enqueue(P);
    }
    else if(operate == "dequeue"){
        que.dequeue();
    }
    else if(operate == "peek"){
        Point p = que.peek();
        cout << "x = " << p.x << ", y = " << p.y << ", z = " << p.z << endl; 
    }
    else{
        cout << "error:Please enter correct value" << endl;
    }
    return;
}

int main(){
    queue que(100);
    while(true){
//        cout << "Please enter the operation(enqueue or dequeue or peek or end)" << endl;
        string operate;
        cin >> operate;
        if(operate == "end")exit(0);

        else cal(operate, que);
    }

}

void print(int x){
    cout << x << endl;
}

