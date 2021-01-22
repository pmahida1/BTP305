//Name: parthraj Mahida  
//Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: November 19th, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"
#include <algorithm>

//#include "Station.h"

using namespace std;

size_t CustomerOrder::m_widthField = 0; //need to define static variables outside of the class in cpp file or else linking error


CustomerOrder::CustomerOrder()
{
	m_name = "";
	m_product = "";
	m_cntItem = 0;
	m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(std::string& str) { //custom constructor

	Utilities util;

	std::string temp = str;

	bool isFound = true;

	size_t next_pos = 0;

	m_name = util.extractToken(temp, next_pos, isFound);

	m_product = util.extractToken(temp, next_pos, isFound);

	m_cntItem = std::count(str.begin(), str.end(), util.getDelimiter()) - 1;

	m_lstItem = new Item * [m_cntItem];

	for (auto i = 0u; i < m_cntItem; ++i)
	{
		std::string data = util.extractToken(temp, next_pos, isFound);
		m_lstItem[i] = new Item(data);
	}

	if (m_widthField < util.getFieldWidth())
		m_widthField = util.getFieldWidth();

}

CustomerOrder::CustomerOrder(const CustomerOrder& other) {//copy constructor
	//throw an exception if called
	throw "Copy Operations Not Allowed";
}

CustomerOrder::CustomerOrder(CustomerOrder&& other) noexcept {//move constructor
	m_lstItem = nullptr;
	*this = std::move(other);

}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other)noexcept {//move assignment operator


	if (this != &other) {
		if (m_lstItem != nullptr)
		{
			for (size_t i = 0; i < m_cntItem; ++i) {
				delete m_lstItem[i];
				m_lstItem[i] = nullptr;
			}
			delete[] m_lstItem;
		}
		m_lstItem = other.m_lstItem;
		m_name = other.m_name;
		m_product = other.m_product;
		m_cntItem = other.m_cntItem;
		other.m_lstItem = nullptr;
		other.m_name = "";
		other.m_cntItem = 0;
		other.m_product = "";
	}
	return *this;


}

bool CustomerOrder::isItemFilled(const std::string& itemName) const
{
	//If the item doesn't exist in the order, return true

	bool flag = true;

	for (size_t i = 0; i < m_cntItem; i++)
	{
		if (m_lstItem[i]->m_itemName == itemName)
		{
			flag = m_lstItem[i]->m_isFilled;
		}
	}

	return flag;

}

bool CustomerOrder::isOrderFilled() const { //returns true if all the items in the order have been filled; false otherwise

	for (auto i = 0u; i < m_cntItem; i++)
	{
		if (!m_lstItem[i]->m_isFilled)
			return false;
	}
	return true;

}

void CustomerOrder::fillItem(Station& station, std::ostream& os)
{
	for (unsigned int i = 0; i < m_cntItem; ++i) {
		if (m_lstItem[i]->m_itemName == station.getItemName() && station.getQuantity() > 0) {
			station.updateQuantity();
			m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
			m_lstItem[i]->m_isFilled = true;
			cout << "    Filled " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << endl;
		}

		if (m_lstItem[i]->m_itemName == station.getItemName() && station.getQuantity() == 0)
			cout << "Unable to fill " << m_name << ", " << m_product << "[" << station.getItemName() << "]" << endl;
	}
}

void CustomerOrder::display(std::ostream& os) const {
	std::string status = "";
	os << m_name << " - " << m_product << std::endl;
	//for all the list in the items print out the following
	for (size_t i = 0; i < m_cntItem; i++)
	{
		os << "[" << std::setw(6) << std::right << std::setfill('0') << m_lstItem[i]->m_serialNumber << std::setfill(' ') << "] "
			<< std::left << std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";

		//conditional statement evaluating if fillstate is true than status is filled otherwise status is missing
		m_lstItem[i]->m_isFilled == true ? status = "FILLED" : status = "MISSING";

		os << status << std::endl;
	}

}

CustomerOrder::~CustomerOrder() {
	for (size_t i = 0; i < m_cntItem; ++i) {
		delete m_lstItem[i];
	}
	delete[] m_lstItem;
};

