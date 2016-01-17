/*
 * simpleMath.h
 *
 *  Created on: Jan 17, 2016
 *      Author: simon
 */

#ifndef SIMPLEMATH_H_
#define SIMPLEMATH_H_

#include <iostream>
#include <cmath>
#include <cstdlib>

class simpleMath {
public:
	simpleMath();
	virtual ~simpleMath();

	double quadrat(double x);
	double sinc(double x);


	double gleichverteilteRand(double von,double bis);
	double normalverteiltRand(double sigma, double erw);

};

#endif /* SIMPLEMATH_H_ */
