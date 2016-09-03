#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv){
    char file[20];
    std::cout << "Input filename: ";

    std::cin >> file;
    
    string filename;
    filename = string(file);

    if(filename.empty()) { 
        exit(EXIT_FAILURE);
    }

    std::cout << "This example is used for test seekg(p) or tellg(p)" << std::endl;

    fstream finout, fout;

    finout.open(filename.c_str(), ios_base::in | ios_base::out);

    if (finout.is_open()) {
        std::cout << finout.rdbuf();
        finout.seekg(20, ios_base::beg);;
        std::cout << finout.rdbuf();
    }

    return 0;
}
