// reading a csv file
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::ostringstream;
using std::istringstream;


class CSV{
    protected :
    std::map<int, std::vector<string>> csv_contents;
    //constructor
    CSV(const string& path){
    string filename(path);
    string file_contents;
    char delimiter = ',';

    file_contents = readFileIntoString(filename);

    istringstream sstream(file_contents);
    std::vector<string> items;
    string record;

    int counter = 0;
    while (std::getline(sstream, record)) {
        istringstream line(record);
        while (std::getline(line, record, delimiter)) {
            items.push_back(record);
        }
        (*this).csv_contents[counter] = items;
        items.clear();
        counter += 1;
    }

}

    string readFileIntoString(const string& path) {
    auto ss = ostringstream{};
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    return ss.str();
}

};

