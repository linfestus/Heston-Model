//
//  Option.cpp
//  Heston Model
//
//  Created by Bikramjeet Singh on 8/6/18.
//  Copyright © 2018 Bikramjeet Singh. All rights reserved.
//

#include "Option.hpp"


Option::Option(double _strikePrice, double _interestRate,
               double _time, PayOff* _payOff) :
strikePrice(_strikePrice), interestRate(_interestRate), time(_time), payOff(_payOff) {}

Option::~Option() {}
