//
//  main.cpp
//  Heston Model
//
//  Created by Bikramjeet Singh on 8/5/18.
//  Copyright © 2018 Bikramjeet Singh. All rights reserved.
//

#include <iostream>
#include "PayOff.hpp"
#include "Option.hpp"
#include "Distribution.hpp"
#include "CorrelatedDistribution.hpp"
#include "Heston.hpp"

using namespace std;

void generate_normal_correlation_paths(double rho,
                                       vector<double>& spot_normals, vector<double>& cor_normals) {
    long vals = spot_normals.size();
    
    // Create the Standard Normal Distribution and random draw vectors
    StandardNormalDistribution snd;
    vector<double> snd_uniform_draws(vals, 0.0);
    
    // Simple random number generation method based on RAND
    for (int i=0; i<snd_uniform_draws.size(); i++) {
        snd_uniform_draws[i] = rand() / static_cast<double>(RAND_MAX);
    }
    
    // Create standard normal random draws
    snd.randomDraws(snd_uniform_draws, spot_normals);
    
    // Create the correlated standard normal distribution
    CorrelatedDistribution csnd(rho, &spot_normals);
    vector<double> csnd_uniform_draws(vals, 0.0);
    
    // Uniform generation for the correlated SND
    for (int i=0; i<csnd_uniform_draws.size(); i++) {
        csnd_uniform_draws[i] = rand() / static_cast<double>(RAND_MAX);
    }
    
    // Now create the -correlated- standard normal draw series
    csnd.randomDraws(csnd_uniform_draws, cor_normals);
}

int main(int argc, char **argv) {
    
    unsigned numberOfsimulations = ;   // Number of simulated asset paths
    unsigned numberOfIntervals = ;  // Number of intervals for the asset path to be sampled
    
    double S = ;    // Initial spot price
    double K = ;      // Strike price
    double r = ;     // Risk-free rate
    double v = ; // Initial volatility
    double T = ;       // One year until expiry
    
    double rho = ;     // Correlation of asset and volatility
    double kappa = ;   // Mean-reversion rate
    double theta = ;  // Long run average volatility
    double xi = ;      // "Vol of vol"
    
    // Create the PayOff, Option and Heston objects
    PayOff* pPayOffCall = new PayOffCall(K);
    Option* pOption = new Option(K, r, T, pPayOffCall);
    Heston hest_euler(pOption, kappa, theta, xi, rho);
    
    // Create the spot and vol initial normal and price paths
    vector<double> spot_draws(numberOfIntervals, 0.0);  // Vector of initial spot normal draws
    vector<double> vol_draws(numberOfIntervals, 0.0);   // Vector of initial correlated vol normal draws
    vector<double> spot_prices(numberOfIntervals, S);  // Vector of initial spot prices
    vector<double> vol_prices(numberOfIntervals, v);   // Vector of initial vol prices
    
    // Monte Carlo options pricing
    double payOffSum = 0.0;
    for (unsigned i=0; i<numberOfsimulations; i++) {
        
        generate_normal_correlation_paths(rho, spot_draws, vol_draws);
        hest_euler.calculateVolatilityProcess(vol_draws, vol_prices);
        hest_euler.calculateSpotPriceProcess(spot_draws, vol_prices, spot_prices);
        payOffSum += pOption->payOff->operator()(spot_prices[numberOfIntervals-1]);
    }
    double optionPrice = (payOffSum / static_cast<double>(numberOfsimulations)) * exp(-r*T);
    cout << "Option Price: " << optionPrice << std::endl;
    
    delete pOption;
    delete pPayOffCall;
    
    return 0;
}
