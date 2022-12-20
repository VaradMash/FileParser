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

//  Parameterized constructor implementation
FileParser :: FileParser(string filename, char delimiter) {
    /*
     *  Input   :   Filename, delimiter
     *  Utility :   Parameterized constructor
     *  Output  :   None       
     */
    this->filename = filename;
    this->delimiter = delimiter;
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