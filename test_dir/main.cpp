#include <iostream>
#include <sstream>
#include <string>
#include "QuadProg++.h"

int main (int argc, char *const argv[]) {
  quadprogpp::Matrix<double> G, CE, CI;
  quadprogpp::Vector<double> g0, ce0, ci0, x;
	int n, m, p;
	double sum = 0.0;
	char ch;

  n = 2;
  G.resize(n, n);
  {
		std::istringstream is("0.1, 0.2,"
                              "0.2, 0.8 ");

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				is >> G[i][j] >> ch;
	}

  g0.resize(n);
  {
		std::istringstream is("-0.3, -0.6 ");

		for (int i = 0; i < n; i++)
			is >> g0[i] >> ch;
	}

  m = 2;
  CE.resize(n, m);
	{
		std::istringstream is("1.0, 2.0, "
													"1.0 0.0");

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				is >> CE[i][j] >> ch;
	}

  ce0.resize(m);
	{
		std::istringstream is("-1.0, -1.0");

		for (int j = 0; j < m; j++)
			is >> ce0[j] >> ch;
  }

	p = 2;
  CI.resize(n, p);
  {
		std::istringstream is("1.0, 0.0, "
													"0.0, 1.0");

		for (int i = 0; i < n; i++)
			for (int j = 0; j < p; j++)
				is >> CI[i][j] >> ch;
	}

  ci0.resize(p);
  {
		std::istringstream is("0.0, 0.0");

		for (int j = 0; j < p; j++)
			is >> ci0[j] >> ch;
	}
  x.resize(n);

  std::cout << "f: " << solve_quadprog(G, g0, CE, ce0, CI, ci0, x) << std::endl;
	std::cout << "x: " << x << std::endl;
/*  for (int i = 0; i < n; i++)
    std::cout << x[i] << ' ';
	std::cout << std::endl;	 */

	/* FOR DOUBLE CHECKING COST since in the solve_quadprog routine the matrix G is modified */

	{
    std::istringstream is("0.1, 0.2,"
													"0.2, 0.8 ");

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				is >> G[i][j] >> ch;
	}

  std::cout << "Double checking cost: ";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			sum += x[i] * G[i][j] * x[j];
	sum *= 0.5;

	for (int i = 0; i < n; i++)
		sum += g0[i] * x[i];
	std::cout << sum << std::endl;
}
