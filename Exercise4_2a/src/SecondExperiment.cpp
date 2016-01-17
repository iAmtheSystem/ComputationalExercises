/*
 * SecondExperiment.cpp
 *
 *  Created on: Jan 17, 2016
 *      Author: simon
 */

#include "SecondExperiment.h"

//SecondExperiment::SecondExperiment() {
//	// TODO Auto-generated constructor stub
//
//
//
//}

SecondExperiment::SecondExperiment(DoubleSlit slit, unsigned int numberOfElec,unsigned int numberOfBins, double U,double deltaU){
	this->slit=slit;
	this->numberOfElec=numberOfElec;
	this->numberOfBins=numberOfBins;
	this->U=U;
	this->deltaU=deltaU;


	Experiment* epx1 = new Experiment(*(new Electron(U)),slit);
	minima = epx1->Minima();
	binBreite = epx1->Minima()*2/numberOfBins;

	delete epx1;

}



SecondExperiment::~SecondExperiment() {
	// TODO Auto-generated destructor stub
}


const void SecondExperiment::printExp(){
	cout << "Printing Second Exp" << endl;
	unsigned int bin[numberOfBins];
	ofstream myfile;
	myfile.open("SecondExperiment.txt");
	myfile << "# BinNr | NumberOfElektron\n";
	srand(time(NULL));
	for(unsigned int i=0;i<numberOfBins;i++){
		bin[i] = 0;
	}

	double binBreite = 2*minima/numberOfBins;

	for(unsigned int i=0;i<numberOfElec;i++){
		Electron* elec = new Electron(normalverteiltRand(deltaU,U));
		Experiment* exp1 = new Experiment(*elec,slit);

		// Idee: VerwerfMethode:

		double randAngle = gleichverteilteRand(-minima,+minima);

		double randInt = exp1->Intensity(randAngle, elec->Lambda());


		delete elec;
		delete exp1;

		if(randInt<gleichverteilteRand(0,1)){
			i--;
			continue;
		}
		else {
			// cout << "randAngle = " << randAngle << "\n";
			int binNr = randAngle/binBreite + numberOfBins/2;
			if(binNr >= 0 && binNr <= numberOfBins) bin[binNr]++;
		}

	} // end for

	// Normieren
	unsigned int max=0;
	for(unsigned int i=0;i<numberOfBins;i++){
		if(max<bin[i]) max=bin[i];
	}

	for(unsigned int i=0;i<numberOfBins;i++){
		myfile << (i-numberOfBins/2.)*binBreite << "\t" << (double) bin[i]/max  << "\n";
	}


	myfile.close();
}

const void SecondExperiment::printNormv(){

	unsigned int bin[numberOfBins];
	for(unsigned int i=0;i<numberOfBins;i++){
		bin[i] = 0;
	}

	ofstream myfile;
	myfile.open("NormalverteilteSpannung.txt");
	myfile << "# BinNr | NumberOfElektron\n";

	double binBreite = 10*deltaU/numberOfBins;
	// cout << "Binbreite ist " << binBreite << endl;
	for(unsigned int i=0;i<numberOfElec;i++){
		double URand = normalverteiltRand(deltaU,U);
		int binNr = (URand - U)/binBreite + numberOfBins/2;

		if(binNr >= 0 && binNr <= numberOfBins) bin[binNr]++;

		// Idee: Histgrammservice schreiben

	} // end for

	// Print in File
	for(unsigned int i=0;i<numberOfBins;i++){
		myfile << (i-numberOfBins/2.)*binBreite+U << "\t" << bin[i]  << "\n";
	}


	myfile.close();
}

