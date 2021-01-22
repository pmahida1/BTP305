// Name: Parth Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: 19 November, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#pragma once
#ifndef Workstation_H
#define Workstation_H

#include <deque>
#include "Station.h"	
#include "CustomerOrder.h"

class Workstation : public Station {

	std::deque<CustomerOrder> m_orders; //new orders coming in one side and exiting out the other once filled
	Workstation* m_pNextStation; //a pointer to the next Task on the assembly line

public:
	Workstation(const std::string& str); //custom constructor
	Workstation(const Workstation& other) = delete;//copy constructor
	Workstation& operator=(const Workstation& other) = delete;//copy assignment operator
	Workstation(Workstation&& other) noexcept = delete;//move constructor
	Workstation& operator=(Workstation&& other) = delete;//move assignment operator
	void runProcess(std::ostream& os); //runs a single cycle of the assembly line for the current task
	bool moveOrder();
	void setNextStation(Station& station);
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream& os)const;
	Workstation& operator+=(CustomerOrder&& order);
};

#endif

