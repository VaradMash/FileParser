
#include <iostream>
#include "../src/FileParser_implementation.cpp"
using namespace std;

//  Test for line search using LCS
int main() {
    //  Test for get line
    FileParser obj("../data/sample.txt", ' ');    
    string query;
    cout<<"Query : ";
    cin>>query;
    vector<string> result = obj.search_lines(query);
    cout<<endl<<"Result"<<endl;
    for(string res : result) cout<<res<<endl;
    return 0;
}