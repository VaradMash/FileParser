#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "FileParser.h"
using namespace std;

//  Default constructor implementation
FileParser :: FileParser() {
    /*
     *  Input   :   None
     *  Utility :   Default constructor
     *  Output  :   None     
     */
    this->filename = "";
    this->delimiter = ' ';
}

//  Parameterized constructors implementation
FileParser :: FileParser(string filename) {
    /*
     *  Input   :   Filename
     *  Utility :   Parameterized constructor
     *  Output  :   None       
     */
    this->filename = filename;
    this->delimiter = ' ';
}

FileParser :: FileParser(string filename, char delimiter) {
    /*
     *  Input   :   Filename, delimiter
     *  Utility :   Parameterized constructor
     *  Output  :   None       
     */
    this->filename = filename;
    this->delimiter = delimiter;
}

//  Parser method (PRIVATE)
void FileParser::parse(string line) {
    /*
     *  Input   :   Line    
     *  Utility :   Split line based on delimiter
     *  Output  :   Store split to vector
     */    
    // Clear previous output
    this->delimited_line.clear();
    string data = "";
    for(char c : line) {
        if(c == this->delimiter) {
            this->delimited_line.push_back(data);
            data = "";
        } else {
            data.push_back(c);
        }
    }
    this->delimited_line.push_back(data);    
}

//  Filename setter
void FileParser::set_filename(string filename) {
    /*
        Setter method for filename
    */
    this->filename = filename;
}

//  Filename getter
string FileParser::get_filename() {
    /*
        Getter method for filename
    */
    return this->filename;
}

//  Filename setter
void FileParser::set_delimiter(char delimiter) {
    /*
        Setter method for filename
    */
    this->delimiter = delimiter;
}

//  Filename getter
char FileParser::get_delimiter() {
    /*
        Getter method for filename
    */
    return this->delimiter;
}

// Read file and store lines
void FileParser::read_file() {
    /*
     *  Input   :   File name
     *  Utility :   Read file data and store lines
     *  Output  :   
     */
    //  Erase previous data
    this->data_lines.clear();
    try
    {
        this->infile.open(this->filename, ios_base::in);        
        for(string line ; getline(infile, line); ) {
            this->data_lines.push_back(line);
        }
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }    
}

// Display file contents line by line
void FileParser::display() {
    /*
     *  Input   :   None
     *  Utility :   Display file contents
     *  Output  :   Console display
     */
    for(string line : this->data_lines) {
        cout<<line<<endl;
    }
}

// Clear read data
void FileParser::clear() {
    /*
     *  Input   :   None
     *  Utility :   Clear read lines
     *  Output  :   None
     */
    this->data_lines.clear();
}

//  Count words in file
int FileParser::get_word_count() {
    /*
     *  Input   :   Lines, delimiter
     *  Utility :   Get count of words by parsing each line
     *  Output  :   integer
     */
    int count = 0;
    for(string line : this->data_lines) {
        parse(line);
        count += this->delimited_line.size();        
    }
    return count;
}

int FileParser::get_line_count() {
    /*
     *  Input   :   None
     *  Utility :   Count number of lines in file
     *  Output  :   integer
     */
    return this->data_lines.size();
}

string FileParser::get_line(int line_number) {
    /*
     *  Input   :   Line number (1 indexed)
     *  Utility :   Get specific line from file
     *  Output  :   string
     */
    if(line_number < 1) return "Invalid line";
    if(line_number > this->data_lines.size()) return "Line number exceeds file size";
    return this->data_lines[line_number - 1];
}