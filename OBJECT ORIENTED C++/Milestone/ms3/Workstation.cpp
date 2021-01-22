// Name: Parth Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: 19 November, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include "Workstation.h"
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;



Workstation::Workstation(const std::string& str) : Station(str)
{
	m_pNextStation = nullptr; //set to safe state

}

void Workstation::runProcess(std::ostream& os)
{
	//if (!m_orders.empty())       //if there are orders in the queue
	//		m_orders.front().fillItem(*this, os);
	////fill the last order
	if (m_orders.empty())
	{
		return;
	}
	m_orders.front().fillItem(*this, os);
}

bool Workstation::moveOrder()
{
	if (m_orders.empty())
	{
		return false;
	}

	if (m_orders.front().isItemFilled(getItemName()) == true)
	{
		*m_pNextStation += std::move(m_orders.front());
		m_orders.pop_front();
		return true;
	}
	else
	{
		return false;
	}

}

void Workstation::setNextStation(Station& station) {
	if (this != &station)
	{
		m_pNextStation = (Workstation*)(&station);
	}
}

const Workstation* Workstation::getNextStation() const
{

	return m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder& _co) {

	// If the queue is not empty, remove the last item and place it in the received parameter
	if (m_orders.empty())
	{
		return false;
	}
	if (m_orders.front().isOrderFilled())
	{
		_co = std::move(m_orders.front());
		m_orders.pop_front();
		return true;
	}
	else
	{
		return false;
	}

}

void Workstation::display(std::ostream& os) const
{
	if (m_pNextStation == nullptr) {
		os << Station::getItemName() << " --> " << "END OF LINE" << std::endl;
	}
	else {
		os << Station::getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
	}

}

Workstation& Workstation::operator+=(CustomerOrder&& order)
{
	// TODO: insert return statement here

	m_orders.push_back(std::move(order));
	return *this;
}


