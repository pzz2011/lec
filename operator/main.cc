#include <iostream>
using namespace std;

class value {
public:
    value(const int& a_, const int& b_, const int& c_)
          : a(a_), b(b_), c(c_) {  }
    
    friend ostream& operator<< (ostream& os, const value& rv) {
        return os << "a = " << rv.a << " b= " << rv.b << " c = " << rv.c;
    }
private:
    int a, b, c;
};

int main() {
    value v1(1, 2, 3);
    std::cout << "v1 = " << v1 << std::endl;
    return 0;
}
