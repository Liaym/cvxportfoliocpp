#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>


std::vector<double> PortfolioInitialization(int portfolio_size) // Initialize a double vector with (portfolio_size) zeroes
{
    std::vector<double> portfolio(portfolio_size);

    return portfolio;
}


void PrintVector(std::vector<double> vec) // Utility ; Print vector to console
{
    for (auto i: vec)
        {
            std::cout << i << std::endl;
        };

    std::cout << "" << std::endl;

}


std::vector<double> NoHoldingConstraint(int k, std::vector<double> portfolio) // We want to constrain (w_t + z_t)_k = 0, where x is our portfolio (no-hold constraint, p.35)
{
    std::vector<double> NoHoldingVector(portfolio.size());

    NoHoldingVector[k] = 1;

    return NoHoldingVector;
}

std::vector<double> NoSellingConstraint(int k, std::vector<double> portfolio) // We want to constrain z_k >= 0 (no sell restriction, p.37)
{
    std::vector<double> NoSellingVector(portfolio.size());

    NoSellingVector[k] = 1;

    return NoSellingVector;
}


bool PortfolioConstraint(std::vector<double> portfolio) // This is a much simpler version of the self-financing constraint : we simply want 1^T x = 1

{
    return (std::accumulate(portfolio.begin(), portfolio.end(), 0) == 1) // Check if portfolio adds up to 1; THIS IS NOT ROBUST AND needs to be changed (to something like abs(sum - 1)<=epsilon ?)

}






// Coder la fonction r^Tx - gamma x^T \sigma x avec EIGEN


