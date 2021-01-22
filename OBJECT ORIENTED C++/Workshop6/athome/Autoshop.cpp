// Name: Parth Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: November 2nd, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <vector>
#include "Autoshop.h"

namespace sdds {

	Autoshop& Autoshop::operator +=(Vehicle* theVehicle) { //adds the vehicle received as parameter into the m_vehicles vector.
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const { //iterates over the vehicles stored in m_vehicles and prints them into the parameter

		out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;

		std::vector<Vehicle*>::const_iterator it;
		for (it = m_vehicles.begin(); it != m_vehicles.end(); ++it) { //can do auto it instead of line 25
			(*it)->display(out);
			out << std::endl;
		}
		out << "--------------------------------" << std::endl;
	}

	Autoshop::~Autoshop() { //destructor
		std::vector<Vehicle*>::const_iterator it;
		for (it = m_vehicles.begin(); it != m_vehicles.end(); ++it) { //can do auto it instead of line 25
			delete* it;
		}
	}
}