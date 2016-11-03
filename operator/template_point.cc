#include<iostream>
#include<cstring>
#include<cstdio>
//#include<assert>
#include<cassert>
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


template< class type, int dim>
class point_ {
public: 
    point_();
    point_(type coords[dim]) { 
        for (int index = 0; index < dim; ++index) { 
            _coords[index] = coords[index];    
        }
    }

    type& operator[] (int index) { 
        assert (index < dim && index >= 0);
        return _coords[index];
    }

    type operator[] (int index) const { 
        // same as non-const instance
        assert (index < dim && index >= 0);
        return _coords[index];
    }
private:
    type _coords[dim];
};

int main() { 
    point3d<int> p1(1,2,3);
    point3d<float>* p2 = new point3d<float>(4,5,6);

    float data[3] = {1, 2, 3};
    point_<float, 3>* p3 = new point_<float, 3>(data);
    cout << p2->x() << endl;
    cout << p2->y() << endl;
    cout << p2->z() << endl;


    cout << "^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << (*p3)[0]<< endl;
//    cout << p3->[1]<< endl;
//    cout << p3->[2]<< endl;
    return 0;
}
