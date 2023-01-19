#include "expression.h"
#include <cmath>
#include <vector>
#include <string>
#include <sstream>


//base cost model derived from expression
class BaseCost {
} ;


// Holding cost derived from Basecost
class HcostModel : BaseCost{
    public : 
        vector<double> half_spread ; // vector of one half the bid-ask spread (a)
        vector<double> volume ; //vector of total market volume traded for the asset in the time period (V)
        vector<double> sigma ; // vector of price volatility (standard devidation)
        vector<double> power  ; // The nonlinear tcost power ; 
        vector<double> b ; //
        double value ; // portfolio value
        vector<double> z ; // vector of trades

        /* We assume that  the transaction cost is the same for buying and selling, so asymmetry constant c is 0*/

    protected : 

        //constructor
        HcostModel(half_spred, volume, sigma, power, b, value, z) {
            (*this).half_spread = half_spread ;
            (*this).volume = volume ;
            (*this).sigma = sigma ;
            (*this).power = power ;
            (*this).b = b ; 
            (*this).value = value ;
            (*this).z = z ;
        }

        // Estimate tcosts of one asset given trades.
        double estimate_one_asset(int num, int t){
            /*
            * t: time of estimate
            * num : asset number
            */
            double res = (*this).half_spread[number-1]*abs(z[num-1]) + (*this).b[num-1]*(*this).sigma[num-1]*(abs(z[num-1])**(*this).power[num-1])*(((*this).volume[num - 1]/value[t])**(*this).power[num-1]) ;
            return res ;
        }

        // Estimate tcost of a bundle of assets 
        double estimate_whole(int t){
            int len = z.size(); // number of assets
            double h_cost_sum = 0 ;
            for(int num = 0; num<len; num++){
                try{h_cost_sum += (*this).estimate_one_asset(num, t) ;  throw 1;}
                catch(int e){break ;}
            }
            return h_cost_sum ;
        } ;

       // value_expr

        //optimization_log

        //optimization_log

     //   estimate_ahead

     //   est_period

};

// Trade cost derived from Basecost
class TcostModel : BaseCost{
    // See figure 2.3 in the paper https://stanford.edu/~boyd/papers/pdf/cvx_portfolio.pdf
    TcostModel : BaseCost(){};
}