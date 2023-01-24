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
    this->word_count = 0;
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
    this->word_count = 0;
    parse();
}

FileParser :: FileParser(string filename, char delimiter) {
    /*
     *  Input   :   Filename, delimiter
     *  Utility :   Parameterized constructor
     *  Output  :   None       
     */
    this->filename = filename;
    this->delimiter = delimiter;
    this->word_count = 0;
    parse();
}

//  Parser method (PRIVATE)
void FileParser::parse() {
    /*
     *  Input   :   Line    
     *  Utility :   Split line based on delimiter
     *  Output  :   Store split to vector
     */    
    //  Read file
    this->read_file();    
    for(string line : this->data_lines) {
        // Define placeholder for storing split data    
        vector<string> delimited_line;      
        string data = "";
        for(char c : line) {
            if(c == this->delimiter) {
                this->frequency_count[data] += 1;
                delimited_line.push_back(data);
                data = "";                
            } else {
                data.push_back(c);
            }    
        }
        delimited_line.push_back(data);          
        this->frequency_count[data] += 1; 
        // Store line to placeholder
        this->delimited_lines.push_back(delimited_line);
        this->word_count += delimited_line.size();
    } 
}

//  LCS Method (PRIVATE)
int FileParser::longest_common_subsequence(string a, string b) {
    /*
     *  Compute length of longest common subsequence
     */
    int n = a.length(), m = b.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }             
        }
    }
    return dp[n][m];
}

//  Filename setter
void FileParser::set_filename(string filename) {
    /*
        Setter method for filename
    */
    this->filename = filename;
    // Re parse file
    this->parse();
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
    // Re parse file
    this->parse();
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
    this->clear();
    try
    {
        this->infile.open(this->filename, ios_base::in);        
        for(string line ; getline(infile, line); ) {
            this->data_lines.push_back(line);
        }
        this->infile.close();
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
    //  Erase previous data
    this->data_lines.clear();
    this->frequency_count.clear();
    this->delimited_lines.clear();  
    this->word_count = 0;
}

//  Count words in file
int FileParser::get_word_count() {
    /*
     *  Input   :   Lines, delimiter
     *  Utility :   Get count of words by parsing each line
     *  Output  :   integer
     */    
    return this->word_count;
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


// Save Frequency count (all overrides)

void FileParser::save_frequency(string outfile_name){
    /*
     *  Input   :   File name
     *  Utility :   Save frequency count to plain text
     *  Output  :   File
     */
    if(this->is_empty()) {
        cout<<"File empty"<<endl;
        return;
    }    
    int name_length = outfile_name.length();
    string word_seperator = ""; 
    string line_seperator = "";
    string line_start = "";
    // Find file extension
    string extension = "";
    for(int i = name_length - 1; i >= 0; i--) {
        extension = outfile_name[i] + extension;
        if(outfile_name[i] == '.') break;
    }
    //  No extension found
    if(extension == outfile_name) {
        cout<<"Invalid file name.\nError code : No Extension provided."<<endl;
        return;
    }
    //  Check for extensions
    //  Supported extensions : .txt, .json, .xml
    if(extension == ".txt") {
        word_seperator = "\t\t";
        line_seperator = "\n";
    } else if(extension == ".json") {
        line_start = "\t\"";
        word_seperator = "\"\t:\t";
        line_seperator = ",\n";
    } else if(extension == ".xml") {        
        line_start = "\t<word>\n\t\t";
        word_seperator = "\n\t</word>\n\t<frequency>\n\t\t";
        line_seperator = "\n\t</frequency>\n";
    } else {
        cout<<"Invalid file extension\n";
        return;
    }
    string output_data = "";
    if(extension == ".json") output_data += "{\n";
    if(extension == ".xml") output_data += "<root>\n";
    int n = this->frequency_count.size();
    for(auto frequency_pair : this->frequency_count) {
        n -= 1;
        string word = frequency_pair.first;
        string frequency = to_string(frequency_pair.second);
        output_data += line_start + word + word_seperator + frequency ;
        if(n == 0 && extension == ".json") continue;
        output_data += line_seperator;               
    }
    if(extension == ".json") output_data += "\n}";
    if(extension == ".xml") output_data += "</root>\n";
    this->outfile.open(outfile_name, ios::out);
    outfile<<output_data;
    this->outfile.close();    
}

bool FileParser::is_empty() {
    /*
     *  Return true if file is empty
     */
    return this->data_lines.size() == 0;
}

vector<string> FileParser::search_lines(string query) {
    /*
     *  Input   :   Query
     *  Utility :   Search lines for given query based on LCS.
     *  Output  :   Lines with threshold set to length of query     
     */
    vector<string> result;
    int length = query.length();
    for(string line : this->data_lines) {
        int common = this->longest_common_subsequence(line, query);
        if(common == length) result.push_back(line);
    }        
    return result;
}