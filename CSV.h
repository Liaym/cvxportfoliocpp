// reading a csv file
#include <iostream>
#include <fstream> // For ofstream using
#include <sstream> // for istringstream using
#include <string>
#include <vector>

using namespace std ; 
class ReadCVSFile {
    public :
        // constructors
        ReadCVSFile() ;
        ReadCVSFile(const string &path){}
    private :
        vector<string> contents ;
        string s_contents ;
        // member functions 
        string readFileIntoString(const string& path) {}
        vector<string> split(const string &chaine, char delimiteur, vector<string>&elements){}
};
