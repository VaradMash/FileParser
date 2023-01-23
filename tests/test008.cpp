
#include <iostream>
#include "../src/FileParser_implementation.cpp"
using namespace std;

int main() {
    //  Test for get line
    FileParser obj("../data/Iris.csv", ',');    
    // Case 1
    cout<<"Case 1"<<endl;
    obj.save_frequency("../output/text_frequency.txt");
    // Case 2
    cout<<"Case 2"<<endl;
    obj.save_frequency("../output/text_frequency.json");
    // Case 3
    cout<<"Case 3"<<endl;
    obj.save_frequency("../output/text_frequency.xml");
    // Case 3
    cout<<"Case 4"<<endl;
    obj.save_frequency("../output/text_frequency");
    return 0;
}