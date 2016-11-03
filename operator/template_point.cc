#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

template< class type> 
class point3d { 
public: 
    point3d(type x = 0.0, type y = 0.0, type z = 0.0)
      : x_(x), y_(y), z_(z) {  }

    type x() { return x_; }
    type y() { return y_; }
    type z() { return z_; }
    void setx(type x) { x_ = x; }
    void sety(type y) { y_ = y; }
    void setz(type z) { z_ = z; }
private:
    type x_;
    type y_;
    type z_;
};

int main() { 
    point3d<int> p1(1,2,3);
    point3d<float>* p2 = new point3d<float>(4,5,6);

    cout << p2->x() << endl;
    cout << p2->y() << endl;
    cout << p2->z() << endl;
    return 0;
}
