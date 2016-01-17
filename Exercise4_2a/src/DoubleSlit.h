/*
 * DoubleSlit.h
 *
 *  Created on: Jan 17, 2016
 *      Author: simon
 */

#ifndef DOUBLESLIT_H_
#define DOUBLESLIT_H_

class DoubleSlit {
private:
	int width,distance; // in nm
public:

	// Constructors

	DoubleSlit(int width,int distance){
		this->width = width;
		this->distance = distance;
	}

	DoubleSlit(){
		width = 0;
		distance = 0;
	}


	DoubleSlit(const DoubleSlit& sl){
		DoubleSlit *slit = new DoubleSlit();
		*slit = sl;
		width = slit->Width();
		distance = slit->Distance();
		delete slit;
	}

	// Getter

	int Distance(){
		return distance;
	}
	int Width(){
		return width;
	}


};



#endif /* DOUBLESLIT_H_ */
