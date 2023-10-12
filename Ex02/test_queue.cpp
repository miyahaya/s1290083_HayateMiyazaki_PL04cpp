#include <iostream>
#include <string>
#include "queue.cpp"
using namespace std;
#include <random>

struct imput{
    int number;
    string operate;
    int x, y ,z;
};

//　Function to operate the queue according to the input data.
void cal(imput im, queue &que){
    if(im.operate == "enqueue"){
        Point P = Point(im.x,im.y,im.z);
        que.enqueue(P);
    }
    else if(im.operate == "dequeue"){
        que.dequeue();
    }
    else if(im.operate == "peek"){
        Point p = que.peek();
    }
    else if(im.operate == "end"){
        cout << "end" << endl;
        exit(0);
    }
    else if(im.operate == "size"){
        cout << que.size() << "\n" << endl;
    }
    else{
        cout << "error" << endl;
        exit(1);
    }
}

// Function to randomly create data to be input.
imput *ramd(){
    random_device rd;
    mt19937 gen(rd());

    // Determine the number of instructions to be generated.
    uniform_int_distribution<> dis(0, 200);
    int number = dis(gen);
    imput *im = new imput[number];
    im[0].number = number;

    // Create orders and, if necessary, data for POINT.
    for(int i = 0; i < number - 1; i++){
        uniform_int_distribution<> dis(0, 5);
        int operate = dis(gen);
        if(0 <= operate && operate <= 2){
            im[i].operate = "enqueue";
            uniform_int_distribution<> dis(0,99);
            im[i].x = dis(gen);
            im[i].y = dis(gen);
            im[i].z = dis(gen);
        } 
        else if(operate == 3){
            im[i].operate = "dequeue";
        }
        else if(operate == 4){
            im[i].operate = "peek";
        }
        else if(operate == 5){
            im[i].operate = "size";
        }
    }
    im[number - 1].operate = "end";
    return im;
}

int main(){
    // Queue created.
    queue que(100);

    // Create random input data.
    imput *im = ramd();

    // Output the input data produced.
    cout << "Display the radom data to be entered." << endl;
    cout << im[0].number << endl;
    for(int i = 0; i < im[0].number; i++){
        if(im[i].operate == "enqueue"){
           cout << "enqueue "<< im[i].x << " " << im[i].y << " " << im[i].z << endl;
        }
        else {
            cout << im[i].operate << endl;
        }
        
    }
    cout << "" << endl;
    cout << "Displays the operations performed and the status of the queue." << endl;

    // Queue operations with input data one by one as function arguments.
    for(int i = 0; i < im[0].number; i++){
        cal(im[i], que);
    }

}
