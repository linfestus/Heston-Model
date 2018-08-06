//
//  PayOff.hpp
//  Heston Model
//
//  Created by Bikramjeet Singh on 8/5/18.
//  Copyright © 2018 Bikramjeet Singh. All rights reserved.
//

#ifndef PayOff_hpp
#define PayOff_hpp

#include <iostream>
#include <algorithm>

class PayOff {
public:
    PayOff(); 
    virtual ~PayOff() {}; 
    
    virtual double operator() (const double& spotPrice) const = 0;
};

class PayOffCall : public PayOff {
private:
    double strikePrice; 
    
public:
    PayOffCall(const double& strikePrice);
    virtual ~PayOffCall() {};
    
    virtual double operator() (const double& spotPrice) const;
};


#endif 
