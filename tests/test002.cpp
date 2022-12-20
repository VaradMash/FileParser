#include <iostream>
#include "../src/FileParser_implementation.cpp"
using namespace std;

int main() {
    //  Test for file read
    FileParser obj;
    obj.set_filename("../data/Iris.csv");
    obj.read_file();
    obj.display();
    return 0;
}