//
//  Distribution.hpp
//  Heston Model
//
//  Created by Bikramjeet Singh on 8/6/18.
//  Copyright © 2018 Bikramjeet Singh. All rights reserved.
//

#ifndef Distribution_hpp
#define Distribution_hpp

#include <cmath>
#include <vector>

using namespace std;

class Distribution {
public:
    Distribution();
    virtual ~Distribution();
    
    virtual double pdf(const double& x) const = 0;
    
    
    virtual double mean() const = 0;
    virtual double var() const = 0;
    virtual double stdev() const = 0;
    
    virtual void randomDraws(const vector<double>& uniformDraws,
                              vector<double>& distributionDraws) = 0;
};

class StandardNormalDistribution : public Distribution {
public:
    StandardNormalDistribution();
    virtual ~StandardNormalDistribution();
    
    virtual double pdf(const double& x) const;
    
    
    virtual double mean() const;
    virtual double var() const;
    virtual double stdev() const;
    
    // Obtain a sequence of random draws from the standard normal distribution
    virtual void randomDraws(const vector<double>& uniformDraws,
                              vector<double>& distributionDraws);
};

#endif /* Distribution_hpp */
