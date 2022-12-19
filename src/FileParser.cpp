#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "FileParser_header.h"
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