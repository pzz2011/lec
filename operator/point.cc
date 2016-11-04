#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

class point { 
public: 
    point(float x_ = 0.0) : x_(x_) {  }

    float x() { return x_; }
    void setx(float x) { x_ = x; }

    virtual ~point() {  }
private:
    float x_;
};


class point2d : public point { 
public:
    point2d(float x = 0.0, float y = 0.0) 
      : point( x ), y_(y) {  }

    float y() { return y_; }
    void sety(float y) { y_ = y; }
    
    virtual ~point2d() {  }
private:
    float y_;
};


class point3d : public point2d { 
public: 
    point3d(float x = 0.0, float y = 0.0, float z = 0.0) 
      : point2d(x, y), z_(z) {  }

    float z() { return z_; }
    void setz(float z) { z_ = z; }

    virtual ~point3d() {  }
private: 
    float z_;
};






int main() {
    point* p1 = new point(1);
    point* p2 = new point2d(1,2);
    point3d* p3 = new point3d(3,4,5);

    point2d *p22 = dynamic_cast<point2d*>(p2); // at this moment, the source type is polymorphic, in consequence the
    cout << p22->y() << endl;                  // dynamic_cast convertion success
    
//    cout << p1->x() << endl;
//    cout << p2->y() << endl;
//    cout << p3->z() << endl;

    p3->setz(1000);
    cout << p3->z() << endl;

    point& p222 = *p2;
    cout << dynamic_cast<point2d*>(&p222)->y() << endl;
    cout << dynamic_cast<point2d*>(&p222)->point2d::y() << endl;
    delete p1;
    delete p2;
    delete p3;
    return 0;
}
