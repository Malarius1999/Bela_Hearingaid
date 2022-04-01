/*
 * FIR.h
 *
 *  Created on: 10.03.2022
 *      Author: marius.baumann
 */

#ifndef FIR_H_
#define FIR_H_

#include "rtwtypes.h"

template<int length>
class FIR {
public:
	FIR(const real_T* const coeffs);
	~FIR(){};

	real_T step(real_T input);

	private:
	const real_T* coeffs;
	real_T registers[length];
};


template<int length>
FIR<length>::FIR(const real_T* const coeffs) {
	for(int i = 0; i < length; i++){
		registers[i] = 0;
	}
	this->coeffs = coeffs;
}

template<int length>
real_T FIR<length>::step(real_T input){
	real_T out = coeffs[0]*input;
	registers[0] = input;
	for(int i = length-1; i > 0; i--){
		out += coeffs[i]*registers[i];
		registers[i] = registers[i-1];
	}
	return out;
}


#endif /* FIR_H_ */

