#include <iostream>
#include "../src/FileParser_implementation.cpp"
using namespace std;

int main() {
    //  Test for parse call on initialization    
    //  Constructor type 2
    FileParser obj("../data/Iris.csv", ',');
    cout<<obj.get_line_count()<<endl;
    cout<<obj.get_word_count()<<endl;

    //  Reset delimiter
    obj.set_delimiter(' ');
    cout<<obj.get_word_count()<<endl;

    cout<<endl<<"Next constructor"<<endl;
    // Constructor type 1
    FileParser obj1("../data/Iris.csv", ',');
    cout<<obj1.get_line_count()<<endl;

    cout<<endl<<"Next constructor"<<endl;
    // Constructor type 0
    FileParser obj2;
    obj2.set_filename("../data/Iris.csv");
    obj2.set_delimiter(',');
    cout<<obj2.get_word_count()<<endl;

    return 0;
}