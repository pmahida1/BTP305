// Name: Parth Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: November 2nd, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle
	{
		std::string m_maker;
		std::string m_condition;
		double m_topSpeed;
		std::string RemoveSpaces(std::string str);
		std::string RemoveBegSpaces(std::string str);
		std::string RemoveEndSpaces(std::string str);

	public:

		Car(std::istream& is); //custom constructor
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}

#endif
