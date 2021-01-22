// Name: Parthraj Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: 11 Nov 2020
// // I confirm that I am the only author of this file
// and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include <string>
#include "Station.h"
#include "Utilities.h"

size_t Station::m_widthField = 0;
unsigned int Station::id_generator = 0;

Station::Station(const std::string& line)//custom constructor
{
	Utilities  utilities;
	char delimiter = utilities.getDelimiter();
	bool check = false;
	m_id = ++id_generator;
	size_t start = 0;
	size_t end = line.find(delimiter);
	this->m_name = line.substr(start, end);

	start = end + 1;
	end = line.find(delimiter, start);
	this->m_serialNumber = std::stoi(utilities.extractToken(line, start, check));

	start = end + 1;
	end = line.find(delimiter, start);
	this->m_quantity = std::stoi(utilities.extractToken(line, start, check));

	start = end + 1;
	this->m_description = utilities.extractToken(line, start, check);


	if (m_widthField < m_name.length())
	{
		m_widthField = m_name.length();
	}
}
const std::string& Station::getItemName() const
{
	return this->m_name;
}
unsigned int Station::getNextSerialNumber()
{
	return this->m_serialNumber++;
}

unsigned int Station::getQuantity() const
{
	return this->m_quantity;
}


void Station::updateQuantity() {
	if (m_quantity > 0)
		m_quantity--;
}

void Station::display(std::ostream& os, bool full) const
{

	if (full == false) {
		os << "[" << std::setw(3) << std::setfill('0') << std::right << m_id << "]" << std::setfill(' ')
			<< " Item: " << std::setw(m_widthField) << std::left << m_name << std::setfill(' ')
			<< " [" << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << "]" << std::setfill(' ')
			<< std::endl;
	}
	else {
		os << "[" << std::setw(3) << std::setfill('0') << std::right << m_id << "]" << std::setfill(' ')
			<< " Item: " << std::setw(m_widthField) << std::left << m_name << std::setfill(' ')
			<< " [" << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << "]" << std::setfill(' ')

			<< " Quantity: " << std::setw(m_widthField) << std::left << m_quantity << std::setfill(' ')
			<< " Description: " << m_description
			<< std::endl;
	}
}

