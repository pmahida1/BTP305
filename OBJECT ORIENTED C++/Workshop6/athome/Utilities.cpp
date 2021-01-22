// Name: Parth Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: November 2nd, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include "Utilities.h"

namespace sdds {

	Vehicle* createInstance(std::istream& in) {
		Vehicle* car = nullptr; //a pointer of type Car to hold a dynamically created instance of type Car
		std::string str = "";
		char dummy;
		in >> dummy; //this actually takes first char out of stream

		if (in.eof()) {
			std::string str;
			getline(in, str);
			return car;
		}
		if (dummy == 'c' || dummy == 'C') {
			car = new Car(in);
		}
		if (dummy == 'r' || dummy == 'R') {
			car = new Racecar(in);
		}
		else if (dummy != 'c' && dummy != 'C' && dummy != 'r' && dummy != 'R') {
			std::getline(in, str);
			throw(dummy);
		}



		return car;

	}

}