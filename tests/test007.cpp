
#include <iostream>
#include "../src/FileParser_implementation.cpp"
using namespace std;

int main() {
    //  Test for get line
    FileParser obj("../data/Iris.csv", ',');    
    // Case 1
    cout<<"Case 1"<<endl;
    obj.save_frequency("../output/file");
    // Case 2
    cout<<"Case 2"<<endl;
    obj.save_frequency("");
    // Case 3
    cout<<"Case 3"<<endl;
    obj.save_frequency("../output/output_file.txt");
    return 0;
}