#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

class A { 
public: 
    void Foo() {}
};

class B : public A{};
class C : public A{};
class D: public B, public C{};

int main() {

    D d;
    d.Foo():
    return 0;

}
