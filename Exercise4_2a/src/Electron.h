/*
 * Electron.h
 *
 *  Created on: Jan 17, 2016
 *      Author: simon
 */

#ifndef ELECTRON_H_
#define ELECTRON_H_

#include <cmath>

#include "PhysicalConstants.h"


class Electron : PhysicalConstants{
private:
	static const double mass; // eV/c^2
	// double e = 1;
	static const double h; // = 4.135667662; // * 10^-15 eV * s
	double lambda; // in nm
	double k;

public:

	// constructors

	Electron(double U){
		// lamda = h / sqrt (2 * m * Ekin)
		// lamda = h / sqrt (2 * m * e * U)
		// Units and power:
		// [lambda] = 10^-15 eV * s / ( sqrt ( 10^6 eV/c^2 * e * V)
		// 			= 10^-18 c * s
		//			= 10^-10 m => go to nm
		lambda = this->h * 2.99792458 / sqrt(2*this->mass*U) / 10;

		k = 2 * M_PI /lambda;
	}

	Electron(){
		k = 0;
		lambda = 0;
	}

	Electron(const Electron& electron){
		Electron *elec = new Electron;
		*elec = electron;
		lambda = elec->Lambda();
		k = elec->K();
		delete elec;
	}

	// Getter

	double H(){
		return h;
	}

	double Mass(){
		return mass;
	}

	double Lambda(){
		return lambda;
	}

	double K(){
		return k;
	}

};

#endif /* ELECTRON_H_ */
