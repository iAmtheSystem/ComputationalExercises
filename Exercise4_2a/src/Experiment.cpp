/*
 * Experiment.cpp
 *
 *  Created on: Jan 17, 2016
 *      Author: simon
 */

#include "Experiment.h"

//Experiment::Experiment() {
//	minima = 0;
//}

Experiment::Experiment(const Electron& el,const DoubleSlit& sli){
	this->elec = el;
	this->slit = sli;
	// double k = elec.K();
	minima = asin(elec.Lambda()/(2*slit.Width()));

}


Experiment::~Experiment() {
	// TODO Auto-generated destructor stub
}


const double Experiment::Intensity(double alpha,const double lambda){
	const double k = 2 * M_PI / lambda;
	// Normalized: I(alpha) / I_0
	// return pow(sin(k/2 * width * sin(alpha)/ (k/2 * width * sin(alpha)) ),2) * pow(cos(k/2*distance*sin(alpha)),2) ; // (k/2 * width * sin(alpha))^2; //* cos(k/2 *alpha *sin(alpha))^2;
	return quadrat(sinc(k/2. * slit.Width() *sin(alpha))) * quadrat(cos(k/2.*slit.Distance()*sin(alpha)));
}


const void Experiment::printEx(int aufloesungsSchritte){
	double alpha = -minima;
	ofstream myfile;
	myfile.open("Intensity.txt");
	myfile << "# alpha | Intensity\n";
	for(int i=0;i<2*aufloesungsSchritte;i++){
		alpha += minima/aufloesungsSchritte;
		myfile << alpha << "\t" << Intensity(alpha,elec.Lambda()) << "\n";
	} // end for
	myfile.close();
}
