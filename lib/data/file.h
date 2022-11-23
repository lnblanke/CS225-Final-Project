#ifndef FILE_H
#define FILE_H

/*
Utility methods for file processing
*/

#include <fstream>
#include <vector>
#include <string> 
#include <stdexcept>

using namespace std;

namespace data {
    /*
    Read a csv-like file

    Return a 2D vector in which each entry is corresponding to a field in the csv file

    filename: the input csv file
    */
    vector<vector<string>> read_file(string filename);

    /*
    Split a string based on deliminator (auto trim)

    Return a vector of strings split by the deliminator

    str: the string to be split
    sep: the deliminator
    */
    vector<string> split_string(string str, char sep);

    /*
    Remove the spaces at the start and end of the string
    
    str: the string to be trimed
    */
    string trim(string str);
}

#endif 