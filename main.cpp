#include <iostream>

#include <filesystem>

#include "CSV.h"

#include <vector>

#include "csvfun.h"


int main() {

  CSV G_matrix("matrix.csv");

  CSV R_vector("returns.csv");

  CSV CE_matrix("equality_constraints_matrix.csv");

  CSV CI_matrix("inequality_constraints_matrix.csv");

  CSV ce0_vector("equality_constraints_vector.csv");

  CSV ci0_vector("inequality_constraints_vector.csv");

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

  std::cout << "f: " << solve_quadprog(G, R, CE, ce0, CI, ci0, x) << std::endl;
  std::cout << "x: " << x << std::endl;
  for (int i = 0; i < n; i++)
    std::cout << x[i] << ' ';
  std::cout << std::endl;

}
