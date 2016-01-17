/*
 * PhysicalConstants.h
 *
 *  Created on: Jan 17, 2016
 *      Author: simon
 */

#ifndef PHYSICALCONSTANTS_H_
#define PHYSICALCONSTANTS_H_

class PhysicalConstants {
private:
protected:
	static const double speedOfLight = 299792458; // m/s
	static const double electronMass = 0.5109989461; // eV/c^2
	static const double planckH = 4.135667662; // * 10^-15 eV * s
public:
	PhysicalConstants();
	virtual ~PhysicalConstants();

	const double getElectronMass() const {
		return electronMass;
	}

	const double getPlanckH() const {
		return planckH;
	}

	const double getSpeedOfLight() const {
		return speedOfLight;
	}
};

#endif /* PHYSICALCONSTANTS_H_ */
