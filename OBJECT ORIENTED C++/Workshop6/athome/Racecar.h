// Name: Parth Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: November 2nd, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <iostream>
#include <string>
#include "Car.h"
namespace sdds
{
	class Racecar : public Car
	{
		double m_booster; //the percentage (stored as a number between 0 and 1) by which this racecar can boost it's top speed

	public:

		Racecar(std::istream& in); //calls the constructor from Car to build the subobject, and then it extracts the last field from the stream containing the booster bonus.The input format for a racecar is TAG, MAKER, CONDITION, TOP_SPEED, BOOSTER
		void display(std::ostream& out) const; // calls Car::display() to print the information about the car, and adds* at the end.The format should be | MAKER | CONDITION | TOP_SPEED | *
		double topSpeed() const; //returns the top speed of the car, including any booster effects.
		//This class should not have access to the attributes of the parent class.
	};
}
#endif