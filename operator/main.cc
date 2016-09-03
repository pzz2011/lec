#include <iostream>
#include <cassert>
using namespace std;

class value {
public:
    value(const int& a_, const int& b_, const int& c_)
          : a(a_), b(b_), c(c_) {  }
   
    value& operator= (const value& rv) { 
        a = rv.a;
        b = rv.b;
        c = rv.c;
        return *this;
    }

    bool operator== (const value& rv) {
        return a == rv.a && b == rv.b && c == rv.c;
    }
    friend ostream& operator<< (ostream& os, const value& rv) {
        return os << "a = " << rv.a << " b= " << rv.b << " c = " << rv.c;
    }
private:
    int a, b, c;
};


class dog { 
public:
    dog(const string& name_):name(name_){ }
    dog& operator= (const dog& otherdog) {
        name = otherdog.name;
        return *this;
    }

    friend ostream& operator<< (ostream& os, const dog& otherdog) {
        return os << "[dog " << otherdog.name << "]";
    }
private:
    string name;
};

int main() {
    value v1(1, 2, 3);
    value v2(1, 2, 4);
    value v3 = v2;
    std::cout << "v1 = " << v1 << std::endl;
    assert(v1 == v2);
    return 0;
}
