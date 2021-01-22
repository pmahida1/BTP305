// Name: Parth Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: November 2nd, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <string>
#include <fstream>
#include "Racecar.h"

namespace sdds {

	Racecar::Racecar(std::istream& in) : Car(in) {  //calls constructor from Car to create subobject

		std::string str = "";
		in.seekg(-5, std::ios_base::cur);
		std::getline(in, str);

		int index = 0;
		while (index != -1) {
			index = str.find(' ');
			if (index != -1) {
				str.erase(index, 1);
			}
		}

		str.erase(0, (str.find(',') + 1));
		m_booster = std::stod(str);
	}

	void Racecar::display(std::ostream& out) const {// calls Car::display() to print the information about the car, and adds* at the end.The format should be | MAKER | CONDITION | TOP_SPEED | *

		Car::display(out);
		out << "*";

	}

	double Racecar::topSpeed() const {

		return Car::topSpeed() * (1 + m_booster);
	}

}