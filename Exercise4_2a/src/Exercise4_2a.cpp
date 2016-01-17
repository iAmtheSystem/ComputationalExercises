//============================================================================
// Name        : Exercise4_2a.cpp
// Author      : SimonReichel
// Version     :
// Copyright   : None
// Description : Computational Exercise 4.2a)
//============================================================================

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib> //rand()

#include "simpleMath.h"
#include "DoubleSlit.h"
#include "Electron.h"
#include "Experiment.h"
#include "SecondExperiment.h"

using namespace std;



int main() {
	cout << "Computational Exercise 4.2a)\n\nDouble Slit\n" << endl;

	DoubleSlit *slit = new DoubleSlit(62,272);
	cout << "Slit has width = " <<  slit->Width() << " nm and Distance = " << slit->Distance() <<  " nm" << endl;

	Electron *elec = new Electron(300);
	cout << "The Electron has a lambda of " << elec->Lambda() << endl;

	// Idee: Electron erzeugen
	// Winkel zuordnen nach Wahrscheinlichkeitsverteilung

	// Seeding
	srand(time(NULL));



	Experiment *expe = new Experiment(*elec,*slit);
	cout << "\nDie Minima der Intensität liegen bei: " << expe->Minima() << endl;
	expe->printEx(10000);


	cout << "\n *** Starte Experiment mit normalverteilter Spannung ***" << endl;
	// SecondExperiment(DoubleSlit slit, unsigned int numberOfElec,unsigned int numberOfBins, double U,double deltaU,
	SecondExperiment *expe2 = new SecondExperiment(*slit,10000,200,300.,10.);
	expe2->printExp();
	expe2->printNormv();


	cout << "\n +++ Finished! +++" << endl;

	delete expe;
	delete elec;
	delete slit;
	return 0;
}
