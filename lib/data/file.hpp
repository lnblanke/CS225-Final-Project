#ifndef FILE_HPP
#define FILE_HPP

/*
Utility method for file processing
*/

#include <sstream>
#include <vector>

namespace file {
    using namespace std;

    /*
    Read a csv-like file

    Return a 2D vector in which each entry is corresponding to a field in the csv file

    filename: the input csv file
    */
    vector<vector<string>> read_file(string filename);

    /*
    Split a string based on deliminator

    Return a vector of strings split by the deliminator

    str: the string to be split
    sep: the deliminator
    */
    vector<string> split_string(string str, char sep);
}

#endif 