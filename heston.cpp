//
//  Heston.cpp
//  Heston Model
//
//  Created by Bikramjeet Singh on 8/6/18.
//  Copyright © 2018 Bikramjeet Singh. All rights reserved.
//

#include "Heston.hpp"

using namespace std;

Heston::Heston(Option* _option,
                         double _kappa, double _theta,
                         double _xi, double _rho) :
option(_option), kappa(_kappa), theta(_theta), xi(_xi), rho(_rho) {}

Heston::~Heston() {}

void Heston::calculateVolatilityProcess(const vector<double>& volDraws,
                                vector<double>& volPath) {
    size_t vecSize = volDraws.size();
    double dt = option->time/static_cast<double>(vecSize);
    
   
    for (int i=1; i<vecSize; i++) {
        double vMax = std::max(volPath[i-1], 0.0);
        volPath[i] = volPath[i-1] + kappa * dt * (theta - vMax) +
        xi * sqrt(vMax * dt) * volDraws[i-1];
    }
}

void Heston::calculateSpotPriceProcess(const vector<double>& spotDraws,
                                 const vector<double>& volPath,
                                 vector<double>& spotPath) {
    size_t vecSize = spotDraws.size();
    double dt = option->time/static_cast<double>(vecSize);
    
    
    for (int i=1; i<vecSize; i++) {
        double vMax = std::max(volPath[i-1], 0.0);
        spotPath[i] = spotPath[i-1] * exp( (option->interestRate - 0.5*vMax)*dt +
                                            sqrt(vMax*dt)*spotDraws[i-1]);
    }
}
