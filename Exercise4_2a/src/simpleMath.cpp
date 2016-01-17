/*
 * simpleMath.cpp
 *
 *  Created on: Jan 17, 2016
 *      Author: simon
 */

#include "simpleMath.h"
#include <iostream>

using namespace std;

simpleMath::simpleMath() {

}

simpleMath::~simpleMath() {
	// TODO Auto-generated destructor stub
}

double simpleMath::quadrat(double x){
	return x*x;
}

double simpleMath::sinc(double x){
	return sin(x)/x;
}

double simpleMath::gleichverteilteRand(double von,double bis){
	return (double) rand()/RAND_MAX *(bis-von)+von;
}


double simpleMath::normalverteiltRand(double err, double erw){
	float rand1 = (float) rand()/RAND_MAX;
	float rand2 = (float) rand()/RAND_MAX;
	// cout << "rand1 = " << rand1 << "rand2 = " << rand2 << endl;
	return err * sqrt(-2*log(rand1)) * sin( 2*M_PI*rand2 )+erw;
}
