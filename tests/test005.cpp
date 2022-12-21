#include <iostream>
#include "../src/FileParser_implementation.cpp"
using namespace std;

int main() {
    //  Test for get line
    FileParser obj("../data/Iris.csv", ',');
    obj.read_file();
    cout<<obj.get_line(0)<<endl;
    cout<<obj.get_line(15)<<endl;
    cout<<obj.get_line(1921)<<endl;
    return 0;
}