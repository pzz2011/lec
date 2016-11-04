#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

class A { 
public: 
    void Foo() {}
};

class B : public virtual A{};
class C : public virtual A{};
class D: public B, public C{};
int f(int){return 0;}
int main() {

    D d;
    d.Foo();

    int (*pq)(int);
    int a = 1;
//    pq = &a;


    pq = f;
    cout << pq << endl;
    int (*pq)(20);
    return 0;

}
