//
//  CorrelatedDistribution.cpp
//  Heston Model
//
//  Created by Bikramjeet Singh on 8/6/18.
//  Copyright © 2018 Bikramjeet Singh. All rights reserved.
//

#include "CorrelatedDistribution.hpp"
#include <iostream>
#include <cmath>

using namespace std;

CorrelatedDistribution::CorrelatedDistribution(const double _rho,
                             const std::vector<double>* _uncorrelatedDraws)
: rho(_rho), uncorrelatedDraws(_uncorrelatedDraws) {}

CorrelatedDistribution::~CorrelatedDistribution() {}


void CorrelatedDistribution::correlationCalculation(vector<double>& distributionDraws) {
    for (int i=0; i<distributionDraws.size(); i++) {
        distributionDraws[i] = rho * (*uncorrelatedDraws)[i] + distributionDraws[i] * sqrt(1-rho*rho);
    }
}

void CorrelatedDistribution::randomDraws(const vector<double>& uniformDraws,
                                 vector<double>& distributionDraws) {
    
    if (uniformDraws.size() != distributionDraws.size()) {
        cout << "Size of vectors must be equal" << endl;
        return;
    }
    
    if (uniformDraws.size() % 2 != 0) {
        cout << "Uniform draw vector size should be even" << endl;
        return;
    }
    
    for (int i=0; i<uniformDraws.size() / 2; i++) {
        distributionDraws[2*i] = sqrt(-2.0*log(uniformDraws[2*i])) * sin(2*M_PI*uniformDraws[2*i+1]);
        distributionDraws[2*i+1] = sqrt(-2.0*log(uniformDraws[2*i])) * cos(2*M_PI*uniformDraws[2*i+1]);
    }
    
    // Modify the random draws via the correlation calculation
    correlationCalculation(distributionDraws);
    
    return;
}
