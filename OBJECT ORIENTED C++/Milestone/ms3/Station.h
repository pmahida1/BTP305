// Name: Parthraj Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: November 15th, 2020
// // I confirm that I am the only author of this file
// and the content was created entirely by me.
#ifndef STATION_H
#define STATION_H
#include <string>
class Station
{
	unsigned int m_id;
	std::string m_name;
	std::string m_description;
	int	m_serialNumber;
	unsigned int m_quantity;


	static size_t m_widthField;
	static unsigned int id_generator;
public:

	Station(const std::string& str);
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
};
#endif