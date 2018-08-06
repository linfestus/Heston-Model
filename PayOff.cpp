//
//  PayOff.cpp
//  Heston Model
//
//  Created by Bikramjeet Singh on 8/5/18.
//  Copyright © 2018 Bikramjeet Singh. All rights reserved.
//

#include "PayOff.hpp"

using namespace std;

PayOff::PayOff() {}


PayOffCall::PayOffCall(const double& _strikePrice) { strikePrice = _strikePrice; }

double PayOffCall::operator() (const double& spotPrice) const {
    return max(spotPrice-strikePrice, 0.0);
}
