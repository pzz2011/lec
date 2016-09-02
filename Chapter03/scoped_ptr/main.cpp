#include <stdexcept>
#include <iostream>
class foo_class {
public:
    char data[100000000];

    explicit foo_class(const char* /*param*/){}
};

bool some_function1(foo_class* param) {
    return !!param;
}

void some_function2(foo_class* /*param*/) {
    throw std::exception();                                       //
}

bool foo1() {
    foo_class* p = new foo_class("Some initialization data");     // 

    bool something_else_happened = some_function1(p);             // 
    if (something_else_happened) {                                // 
        delete p;
        return false;
    }

    some_function2(p);                                            // 
    delete p;
    return true;
}

bool foo2() {
    foo_class* p = new foo_class("Some initialization data");
//    std::cout << sizeof(*p) << std::endl;
    try {
        bool something_else_happened = some_function1(p);
        if (something_else_happened) {
            std::cout << "reach here " << std::endl;
//            delete p;
            return false;
        }

       some_function2(p);
    } catch (...) {
        delete p;
        throw;
    }

    delete p;
    return true;
}


#include <boost/scoped_ptr.hpp>

bool foo3() {
    boost::scoped_ptr<foo_class> p(new foo_class("Some initialization data"));

    bool something_else_happened = some_function1(p.get());      //  
    if (something_else_happened) {
       return false;
    }

    some_function2(p.get());
    return true;
}

int main() {
//    int a = 1;
//    a = !a;
//    std::cout << a << std::endl;
//    std::exception();
    for(int i = 0; i < 10000000; i++) try { foo2(); } catch(...){}
    try { foo3(); } catch(...){}

    return 0;
}

