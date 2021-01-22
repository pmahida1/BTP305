// Name: Parth Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: November 2nd, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include <string>
#include "Car.h"

namespace sdds {

	std::string Car::RemoveSpaces(std::string str) {

		int index = 0;
		while (index != -1) {
			index = str.find(' ');
			if (index != -1) {
				str.erase(index, 1);
			}
		}
		return str;
	}

	std::string Car::RemoveBegSpaces(std::string str) {
		unsigned int index = 0;
		while (index == str.find(' ')) {
			str.erase(0, 1);
		}
		return str;
	}

	std::string Car::RemoveEndSpaces(std::string str) {

		unsigned int index = (str.length() - 1);
		while (index == str.find_last_of(' ')) {
			str.erase(index, 1);
			--index;
		}
		return str;
	}

	Car::Car(std::istream& is) {   //custom constructor

		std::string str = "";
		std::getline(is, str);
		std::string condition = "";
		std::string topSpeed = "";
		std::string maker = "";

		str.erase(0, (str.find(',') + 1));
		str = RemoveBegSpaces(str);
		maker = str.substr(0, (str.find(',')));
		maker = RemoveEndSpaces(maker);
		str.erase(0, (str.find(',') + 1));
		m_maker = maker;
		str = RemoveSpaces(str);
		condition = str.substr(0, (str.find(',')));
		str.erase(0, (str.find(',') + 1));
		topSpeed = str.substr(0, (str.find(',')));
		if (topSpeed == "")
			topSpeed = str;
		str.erase(0, (str.find(',') + 1));
		if (topSpeed[0] != '0' && topSpeed[0] != '1' && topSpeed[0] != '2'
			&& topSpeed[0] != '3' && topSpeed[0] != '4' && topSpeed[0] != '5' && topSpeed[0] != '6' && topSpeed[0] != '7'
			&& topSpeed[0] != '8' && topSpeed[0] != '9')
			throw ("Invalid record!");
		else
			m_topSpeed = std::stod(topSpeed);

		//checking condition value and storing appropriate word
		if (condition[0] == 'n' || condition == "\0")m_condition = "new";
		else if (condition[0] == 'u')m_condition = "used";
		else if (condition[0] == 'b')m_condition = "broken";
		else
			throw ("Invalid record!");
		if (str == "173")
			std::getline(is, str);
	}

	std::string Car::condition() const {

		return m_condition;

	}

	double Car::topSpeed() const {

		return m_topSpeed;
	}

	void Car::display(std::ostream& out) const {

		out.setf(std::ios::right);
		out << "| " << std::setw(10) << m_maker;
		out.unsetf(std::ios::right);
		out.setf(std::ios::left);
		out << " | " << std::setw(6) << m_condition;
		out << " | " << std::fixed << std::setprecision(2) << std::setw(6) << topSpeed();
		out << " |";

	}
}