//
//  Distribution.cpp
//  Heston Model
//
//  Created by Bikramjeet Singh on 8/6/18.
//  Copyright © 2018 Bikramjeet Singh. All rights reserved.
//

#include "Distribution.hpp"
#include <iostream>

using namespace std;


Distribution::Distribution() {}
Distribution::~Distribution() {}

StandardNormalDistribution::StandardNormalDistribution() {}
StandardNormalDistribution::~StandardNormalDistribution() {}

double StandardNormalDistribution::pdf(const double& x) const {
    return (1.0/sqrt(2.0 * M_PI)) * exp(-0.5*x*x);
}


double StandardNormalDistribution::mean() const { return 0.0; }

double StandardNormalDistribution::var() const { return 1.0; }

double StandardNormalDistribution::stdev() const { return 1.0; }

// Obtain a sequence of random draws from this distribution
void StandardNormalDistribution::randomDraws(const vector<double>& uniformDraws,
                                             vector<double>& distributionDraws) {
    //Using Box-Muller method
    if (uniformDraws.size() != distributionDraws.size()) {
        cout << "Size of vectors must be equal" << endl;
        return;
    }
    
    // Necessary condition for  B-M
    if (uniformDraws.size() % 2 != 0) {
        cout << "Uniform draw vector size should be even" << endl;
        return;
    }
    
    for (int i=0; i<uniformDraws.size() / 2; i++) {
        distributionDraws[2*i] = sqrt(-2.0*log(uniformDraws[2*i])) * sin(2*M_PI*uniformDraws[2*i+1]);
        distributionDraws[2*i+1] = sqrt(-2.0*log(uniformDraws[2*i])) * cos(2*M_PI*uniformDraws[2*i+1]);
    }
    
    return;
}
