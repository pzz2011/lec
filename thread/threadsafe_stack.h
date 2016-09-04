#include <exception>

struct empty_stack: std::exception { 
    const char* what() const throw();
};

template<typename T>
class threadsafe_stack { 
private:
    std::stack<T> data;
    mutable std::mutex m;

public:
    threadsafe_stack(){  }
    threadsafe_stack(const threadsafe_stack& other) {
        std::lock_guard<std::mutex> lock(other.m);
        data = other.data;
    }


}
