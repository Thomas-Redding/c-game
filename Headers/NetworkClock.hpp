//
//  networkClock.hpp
//  GamerServerClientCombo
//
//  Created by Thomas Redding on 11/8/15.
//  Copyright © 2015 Thomas Redding. All rights reserved.
//

#ifndef NetworkClock_cpp
#define NetworkClock_cpp

#include <stdio.h>
#include <chrono>
#include <vector>
#include <algorithm>

class NetworkClock {
public:
	void add(long x);
	unsigned long size();
	long getLocalTime();
	long estimateClockDiff();
	long getServerTime();
	long serverToClientTime(long serverTime);
private:
	std::vector<long> estimatedClockDifferences;
};


#endif /* networkClock_cpp */
