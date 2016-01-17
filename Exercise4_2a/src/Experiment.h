/*
 * Experiment.h
 *
 *  Created on: Jan 17, 2016
 *      Author: simon
 */

#ifndef EXPERIMENT_H_
#define EXPERIMENT_H_

#include "simpleMath.h"
#include <cmath>
#include <iostream>
#include <fstream>

#include "DoubleSlit.h"
#include "Electron.h"

using namespace std;

class Experiment : simpleMath {
private:
	DoubleSlit slit;
	Electron elec;
	double minima;
public:
	//	Experiment();
	Experiment(const Electron& el,const DoubleSlit& sli);
	virtual ~Experiment();


	double Minima(){
		return minima;
	}


	const double Intensity(double alpha,const double lambda);

	const void printEx(int aufloesungsSchritte);


};

#endif /* EXPERIMENT_H_ */
