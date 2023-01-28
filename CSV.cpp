#include "CSV.h"

       ReadCVSFile :: ReadCVSFile(){exit(EXIT_FAILURE);} ;

       ReadCVSFile :: ReadCVSFile(const string &path){
            string filename(path);
            string file_contents;
            char delimiter = ',';
            file_contents = readFileIntoString(filename); 
            vector <string> vect ;
            vect = split(file_contents, '\n', vect) ;
            vect[vect.size()-1].pop_back() ;
            contents = vect ;
            for (int i = 0; i<vect.size(); i++){
                s_contents.append(vect[i]);
            }
        } ;


        string ReadCVSFile:: readFileIntoString(const string& path) {
            auto ss = ostringstream{};
            ifstream input_file(path);
            if (!input_file.is_open()) {
            cerr << "Could not open the file - '" << path << "'" << endl;
            exit(EXIT_FAILURE);
            }
            ss << input_file.rdbuf();
            return ss.str();
        } ;

        vector<string> ReadCVSFile:: split(const string &chaine, char delimiteur, vector<string>&elements){
            stringstream ss(chaine);
            string sousChaine;
            while (getline(ss, sousChaine, delimiteur)){
                elements.push_back(sousChaine+=",");
            }
            return elements;
        }    ;

