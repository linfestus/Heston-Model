//
//  Option.hpp
//  Heston Model
//
//  Created by Bikramjeet Singh on 8/6/18.
//  Copyright © 2018 Bikramjeet Singh. All rights reserved.
//

#ifndef Option_hpp
#define Option_hpp

#include "PayOff.hpp"

class Option {
public:
    PayOff* payOff;
    double strikePrice;
    double interestRate;
    double time;
    
    Option(double _strikePrice, double _interestRate,
           double _time, PayOff* _payOff);
    
    virtual ~Option();
};

#endif
