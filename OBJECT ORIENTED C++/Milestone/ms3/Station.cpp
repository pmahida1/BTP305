// Name: Parthraj Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: November 19th, 2020
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
	Utilities m_util;

	size_t new_pos = 0;
	bool more = true;

	m_id = ++id_generator;

	m_name = m_util.extractToken(line, new_pos, more);
	m_serialNumber = std::stoul(m_util.extractToken(line, new_pos, more));
	m_quantity = std::stoi(m_util.extractToken(line, new_pos, more));

	if (m_widthField < m_util.getFieldWidth()) {
		m_widthField = m_util.getFieldWidth();
	}
	m_description = m_util.extractToken(line, new_pos, more);

	if (m_widthField > m_util.getFieldWidth()) {
		m_widthField = m_util.getFieldWidth();
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