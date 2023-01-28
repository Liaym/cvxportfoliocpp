#include "CSV.h"
using namespace std ;

       CSV :: CSV(){exit(EXIT_FAILURE);} ;

       CSV :: CSV(const string path){
            //string filename(path);
            string file_contents;
            file_contents = CSV::readFileIntoString(path); 
            vector <string> vect ;
            char delimiter = '\n';
            vect = CSV::split(file_contents, delimiter) ;
            //vect[vect.size()-1].pop_back() ;
            contents = vect ;
            for (int i = 0; i<vect.size(); i++){
                s_contents.append(vect[i]);
            }
        } ;


        string CSV:: readFileIntoString(const string path) {
            auto ss = ostringstream{};
            ifstream input_file(path);
            if (!input_file.is_open()) {
            cerr << "Could not open the file - '" << path << "'" << endl;
            exit(EXIT_FAILURE);
            }
            ss << input_file.rdbuf();
            return ss.str();
        } ;

        vector<string> CSV:: split(const string chaine, char delimiteur){
            vector<string>elements ;
            stringstream ss(chaine);
            string sousChaine;
            while (getline(ss, sousChaine, delimiteur)){
                elements.push_back(sousChaine);
            }
            return elements;
        };

        string CSV :: get_scontent(){
            return (*this).s_contents ;
        };

        vector <string> CSV :: get_vcontent(){
            return (*this).contents ;
        };

