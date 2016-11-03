#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

// point to member example  
// http://stackoverflow.com/questions/670734/c-pointer-to-class-data-member



class Car { 
public: 
    int speed;
};
int main() {
    int Car::*pspeed = &Car::speed;

    Car c1;
    c1.speed = 1; // direct access
    cout << "speed is " << c1.speed << endl;

    c1.*pspeed = 2;
    cout << "speed is " << c1.speed << endl;
    return 0;

}
