// reading a csv file
# pragma once
#include <iostream>
#include <fstream> // For ofstream using
#include <sstream> // for istringstream using
#include <string>
#include <vector>

class CSV {
    private :
        std::vector<std::string> contents ;
        std::string s_contents ;
    public :
        // constructors
        CSV() ;
        CSV(const std ::string path);

        // member functions
        std::string readFileIntoString(const std::string  &path) ;
        std::vector<std::string> split(const std::string &chaine, char delimiteer);
        std::string get_scontent () ;
        std::vector <std::string> get_vcontent ();
        std::string concatenated_content(int nrows);
};
