//Name: parthraj Mahida  
//Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: November 15th, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#pragma once
#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "Station.h"

struct Item
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;

	Item(std::string src) : m_itemName(src) {};
};

class CustomerOrder
{
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	Item** m_lstItem;
	static size_t m_widthField;

public:
	CustomerOrder();
	CustomerOrder(std::string&);
	CustomerOrder(const CustomerOrder&);
	CustomerOrder& operator=(const CustomerOrder&) = delete;
	CustomerOrder(CustomerOrder&&) noexcept;
	CustomerOrder& operator=(CustomerOrder&&) noexcept;
	~CustomerOrder();
	bool isItemFilled(const std::string& itemName) const;
	bool isOrderFilled() const;
	void fillItem(Station&, std::ostream&);
	void display(std::ostream&) const;
};


#endif 