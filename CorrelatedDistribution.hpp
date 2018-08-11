//
//  CorrelatedDistribution.hpp
//  Heston Model
//
//  Created by Bikramjeet Singh on 8/6/18.
//  Copyright © 2018 Bikramjeet Singh. All rights reserved.
//

#ifndef CorrelatedDistribution_hpp
#define CorrelatedDistribution_hpp

#include "Distribution.hpp"

using namespace std;

class CorrelatedDistribution : public StandardNormalDistribution {
protected:
    double rho;
    const vector<double>* uncorrelatedDraws;
    
    //Modifying uncorrelated draws such that they are correlated
    virtual void correlationCalculation(vector<double>& distributionDraws);
    
public:
    CorrelatedDistribution(const double _rho,
                  const vector<double>* _uncorrelatedDraws);
    virtual ~CorrelatedDistribution();
    
    virtual void randomDraws(const vector<double>& uniformDraws,
                              vector<double>& distributionDraws);
};
#endif /* CorrelatedDistribution_hpp */
