#include <bits/stdc++.h>
#include <string>
using namespace std;

class FileParser {
private:
    string filename;
    char delimiter;
    vector<string> data_lines;
    void parse();

public:
    FileParser();                   //  Default constructor
    FileParser(string, char);       //  Parameterized constructor for filename and delimiter
    void set_filename(string);      //  Setter for filename
    string get_filename();          //  Getter for filename               
    void read_file();               //  Method to read file
    void clear();
    void set_delimiter(char);
    void get_delimiter();
};