#pragma once

#include <string>

#include <limits>

#include "CSV.h"

#include "QuadProg++.h"


CSV::CSV() {
  exit(EXIT_FAILURE);
};

CSV::CSV(const std::string path) {
  std::string file_contents;
  file_contents = CSV::readFileIntoString(path);
  std::vector < std::string > vect;
  char delimiter = '\n';
  vect = CSV::split(file_contents, delimiter);
  contents = vect;
  for (int i = 0; i < vect.size(); i++) {
    s_contents.append(vect[i]);
  }
};

std::string CSV::readFileIntoString(const std::string & path) {
  auto ss = std::ostringstream {};
  std::ifstream input_file(path);
  if (!input_file.is_open()) {
    std::cerr << "Could not open the file - '" << path << "'" << std::endl;
    exit(EXIT_FAILURE);
  }
  ss << input_file.rdbuf();
  return ss.str();
};

std::vector < std::string > CSV::split(const std::string & chaine, char delimiteur) {
  std::vector < std::string > elements;
  std::stringstream ss(chaine);
  std::string sousChaine;
  while (getline(ss, sousChaine, delimiteur)) {
    elements.push_back(sousChaine);
  }
  return elements;
};

std::string CSV::get_scontent() {
  return ( * this).s_contents;
};

std::vector < std::string > CSV::get_vcontent() {
  return ( * this).contents;
};

// Récupération des données depuis un .csv de matrices (type quadprogpp::Matrix)

void from_csvmatrix(const std::vector < std::string > & vec, quadprogpp::Matrix < double > & mat) {
  int rows = vec.size();
  int cols = 0;

  // count the number of columns in the first row
  std::istringstream iss(vec[0]);
  while (iss >> std::ws && (iss.peek() != EOF)) {
    double temp;
    iss >> temp;
    cols++;
    char ch;
    iss >> ch;
  }

  mat.resize(rows, cols);
  for (int i = 0; i < rows; i++) {
    std::istringstream iss(vec[i]);
    for (int j = 0; j < cols; j++) {
      iss >> mat[i][j];
      char ch;
      if (j < cols - 1) {
        iss >> ch;
      }
    }
  }
}


// Récupération des données depuis un .csv de vecteurs (type quadprogpp::Vector)

void from_csvvector(std::vector < std::string > & data, quadprogpp::Vector < double > & vec) {
  int n = data.size();
  vec.resize(n);
  for (int i = 0; i < n; ++i) {
    std::string line = data[i];
    std::istringstream iss(line);
    for (int j = 0; j < vec.size(); ++j) {
      if (!(iss >> vec[j]))
        break;
      iss.ignore(1, ',');
    }
  }
}
