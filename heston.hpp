#ifndef Heston_hpp
#define Heston_hpp

#include <cmath>
#include <vector>
#include "Option.hpp"

using namespace std;

class Heston {
private:
    Option* option;
    double kappa;
    double theta;
    double xi;
    double rho;
    
public:
    Heston(Option* _option,
                double _kappa, double _theta,
                double _xi, double _rho);
    virtual ~Heston();
    
    void calculateVolatilityProcess(const vector<double>& volDraws,
                       vector<double>& volPath);
    
    // Calculate the asset price path
    void calculateSpotPriceProcess(const vector<double>& spotDraws,
                        const vector<double>& volPath,
                        vector<double>& spotPath);
};

#endif /* Heston_hpp */
