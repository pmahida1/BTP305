// Name: Parth Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: November 2nd, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles; // a vector that stores all vehicles available at this autoshop
	public:
		Autoshop& operator +=(Vehicle* theVehicle); //adds the vehicle received as parameter into the m_vehicles vector.
		void display(std::ostream& out) const; //iterates over the vehicles stored in m_vehicles and prints them into the parameter
		~Autoshop(); //destructor

		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {

			int i = 0;
			std::vector<Vehicle*>::const_iterator it;
			for (it = m_vehicles.begin(); it != m_vehicles.end(); ++it, ++i) {
				if (test(m_vehicles[i]))
					vehicles.push_back(m_vehicles[i]);
			}
		};
	};
}

#endif

