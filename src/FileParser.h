#include <bits/stdc++.h>
#include <string>
#include <fstream>

using namespace std;

class FileParser {
private:
    string filename;
    char delimiter;
    vector<string> data_lines;
    void parse();
    ifstream infile;
    ofstream outfile;

public:
    FileParser();                   //  Default constructor
    FileParser(string, char);       //  Parameterized constructor for filename and delimiter
    void set_filename(string);      //  Setter for filename
    string get_filename();          //  Getter for filename               
    void read_file();               //  Method to read file
    void clear();                   //  Clear data
    void set_delimiter(char);       //  Setter for filename
    char get_delimiter();           //  Getter for delimiter
    void display();                 //  Method to display file contents line by line                    
};