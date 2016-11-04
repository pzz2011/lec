#include<exception>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
class libcuckoo_maximum_hashpower_exceeded : public std::exception { 
public: 
    libcuckoo_maximum_hashpower_exceeded(const size_t hp)
        : hashpower_(hp) {  }

    virtual const char* what() const  { 
        return "Expansion beyond maximum hashpower";
    }

    size_t hashpower() { 
        return hashpower_;
    }
private:
    const size_t hashpower_;
};


int main() { 

    libcuckoo_maximum_hashpower_exceeded* e = new libcuckoo_maximum_hashpower_exceeded(3);
    std::cout << e->hashpower() << std::endl;
    return 0;
}
