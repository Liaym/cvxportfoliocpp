#include <iostream>

#include <filesystem>

#include "CSV.h"

#include <vector>

#include "CSV.cpp"

#include "QuadProg++.cpp"

#include "QuadProg++.h"


int main() {

  CSV G_matrix("./data/matrix.csv"); // initialisation de la matrice de variance-covariance

  CSV R_vector("./data/returns.csv"); // initialisation du vecteur des retours

  CSV CE_matrix("./data/equality_constraints_matrix.csv"); // initialisation de la (transposée) de la matrice des contraintes d'inegalité

  CSV CI_matrix("./data/inequality_constraints_matrix.csv"); // initialisation de la (transposée) de la matrice des contraintes d'inégalités

  CSV ce0_vector("./data/equality_constraints_vector.csv"); // initialisation du vecteur des contraintes d'égalités

  CSV ci0_vector("./data/inequality_constraints_vector.csv"); // initialisation du vecteur des contraintes d'inégalités


  // On récupère les données contenues dans les matrices et vecteurs qui viennent d'être initialisés

  std::vector < std::string > G_contents {
    G_matrix.get_vcontent()
  };

  std::vector < std::string > R_contents {
    R_vector.get_vcontent()
  };

  std::vector < std::string > CE_contents {
    CE_matrix.get_vcontent()
  };

  std::vector < std::string > CI_contents {
    CI_matrix.get_vcontent()
  };

  std::vector < std::string > ce0_contents {
    ce0_vector.get_vcontent()
  };

  std::vector < std::string > ci0_contents {
    ci0_vector.get_vcontent()
  };


  quadprogpp::Matrix < double > G, CE, CI;
  quadprogpp::Vector < double > R, ce0, ci0;

  int n = G_contents.size(); // nombre d'actifs dans le portefeuille

  from_csvmatrix(G_contents, G);
  from_csvmatrix(CE_contents, CE);
  from_csvmatrix(CI_contents, CI);
  from_csvvector(R_contents, R);
  from_csvvector(ce0_contents, ce0);
  from_csvvector(ci0_contents, ci0);

  quadprogpp::Vector < double > x;

  x.resize(n);

  // Appel de la méthode de résolution du programme d'optimisation quadratique

 solve_quadprog(G, R, CE, ce0, CI, ci0, x);

 std::cout << "La solution optimale à ce problème d'optimisation est obtenue en : " << std::endl << std::endl;
  for (int i = 0; i < n; i++)
    std::cout << "Choisissant "<<x[i] * 100 << " %" <<" de l'actif "<< i << std::endl;

}
