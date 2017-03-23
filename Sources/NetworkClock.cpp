//
//  NetworkClock.cpp
//  GamerServerClientCombo
//
//  Created by Thomas Redding on 11/8/15.
//  Copyright © 2015 Thomas Redding. All rights reserved.
//

#include "../Headers/NetworkClock.hpp"

void NetworkClock::add(long x) {
	estimatedClockDifferences.push_back(x);
	if(estimatedClockDifferences.size() > 40)
		estimatedClockDifferences.erase(estimatedClockDifferences.begin(), estimatedClockDifferences.begin()+1);
}

unsigned long NetworkClock::size() {
	return estimatedClockDifferences.size();
}

long NetworkClock::getLocalTime() {
	return std::chrono::duration_cast< std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

signed long NetworkClock::estimateClockDiff() {
	if(estimatedClockDifferences.size() > 0) {
		std::vector<long> vect = estimatedClockDifferences;
		std::sort(vect.begin(), vect.begin()+vect.size());
		unsigned long middleIndex = vect.size()/2;
		return vect[middleIndex];
	}
	else
		return 0;
}

long NetworkClock::getServerTime() {
	return getLocalTime() + estimateClockDiff();
}


long NetworkClock::serverToClientTime(long serverTime) {
	return serverTime - estimateClockDiff();
}
