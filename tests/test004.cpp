#include <iostream>
#include "../src/FileParser_implementation.cpp"
using namespace std;

int main() {
    //  Test for line count
    FileParser obj("../data/Iris.csv", ',');
    obj.read_file();
    cout<<obj.get_word_count();
    return 0;
}