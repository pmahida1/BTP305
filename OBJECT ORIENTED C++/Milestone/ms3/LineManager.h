// Name: Parth Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: 19 November, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _LINEMANAGER_H
#define _LINEMANAGER_H

#include <iostream>
#include <vector>
#include <deque>
#include "Workstation.h"
#include "Workstation.h"
#include "Station.h"


class LineManager
{
	std::vector<Workstation*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder = 0;





public:

	LineManager(const std::string&, std::vector<Workstation*>&, std::vector<CustomerOrder>&);
	bool run(std::ostream& os);
	void displayCompletedOrders(std::ostream& os) const;
	void displayStations() const;
	void displayStationsSorted() const;
};
#endif 

