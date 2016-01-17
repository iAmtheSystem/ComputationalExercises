/*
 * SecondExperiment.h
 *
 *  Created on: Jan 17, 2016
 *      Author: simon
 */

#ifndef SECONDEXPERIMENT_H_
#define SECONDEXPERIMENT_H_

#include "simpleMath.h"
#include <cmath>
#include <iostream>
#include <fstream>

#include "DoubleSlit.h"
#include "Electron.h"
#include "Experiment.h"

#include "simpleMath.h"

using namespace std;

class SecondExperiment :simpleMath {
private:
	DoubleSlit slit;
	unsigned int numberOfElec;
	unsigned int numberOfBins;
	double minima;
	double binBreite;
	double U;
	double deltaU;
public:
//	SecondExperiment();
	SecondExperiment(DoubleSlit slit, unsigned int numberOfElec,unsigned int numberOfBins, double U,double deltaU);


	virtual ~SecondExperiment();

	const void printExp();
	const void printNormv();


};

#endif /* SECONDEXPERIMENT_H_ */
