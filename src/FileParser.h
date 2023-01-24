#include <bits/stdc++.h>
#include <string>
#include <fstream>

using namespace std;

class FileParser {
private:
    string filename;
    char delimiter;
    int word_count;
    vector<string> data_lines;                          //  Placeholder to store all lines
    vector<vector<string>> delimited_lines;             //  Placeholder to store all delimited lines
    map<string, int> frequency_count;                   //  Placeholder to store frequency count
    void parse();
    int longest_common_subsequence(string, string);     //  Method for computing length of longest common subsequence
    ifstream infile;
    ofstream outfile;

public:
    FileParser();                                       //  Default constructor
    FileParser(string);                                 //  Parameterized constructor for filename
    FileParser(string, char);                           //  Parameterized constructor for filename and delimiter
    void set_filename(string);                          //  Setter for filename
    string get_filename();                              //  Getter for filename               
    void read_file();                                   //  Method to read file
    void clear();                                       //  Clear data
    void set_delimiter(char);                           //  Setter for filename
    char get_delimiter();                               //  Getter for delimiter
    void display();                                     //  Method to display file contents line by line                 
    int get_word_count();                               //  Method to get word count based on delimiter  
    int get_line_count();                               //  Method to get line count
    string get_line(int);                               //  Method to get specific line from file
    void save_frequency(string);                        //  Method to save word frequencies to file to desired text file
    bool is_empty();                                    //  Method to check whether file is empty
    void display_lines();
    vector<string> search_lines(string);                //  Method to search query in lines
};