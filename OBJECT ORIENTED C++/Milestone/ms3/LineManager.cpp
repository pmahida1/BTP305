// Name: Parth Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: 19 November, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include "LineManager.h"
#include "Utilities.h"
#include "Workstation.h"
#include "CustomerOrder.h"
#include "Station.h"

using namespace std;

LineManager::LineManager(const std::string& file, std::vector<Workstation*>& tasks, std::vector<CustomerOrder>& done)
{
	std::ifstream m_file(file);

	std::string temp, task1, task2;

	if (!m_file)
		std::cerr << "File does not exist!";
	else
	{
		ToBeFilled.resize(done.size());
		AssemblyLine.resize(tasks.size());
		std::move(done.begin(), done.end(), ToBeFilled.begin());
		std::copy(tasks.begin(), tasks.end(), AssemblyLine.begin());
		m_cntCustomerOrder = done.size();
		while (!m_file.eof())
		{
			string field;
			getline(m_file, field);
			Utilities m_util;
			size_t new_pos = 0;
			bool more = true;
			string one = m_util.extractToken(field, new_pos, more);
			string two = m_util.extractToken(field, new_pos, more);
			for (unsigned int i = 0u; i < AssemblyLine.size(); i++) {
				if (AssemblyLine[i]->getItemName() == one) {

					for (unsigned int j = 0u; j < AssemblyLine.size(); j++) {
						if (AssemblyLine[j]->getItemName() == two) 
							AssemblyLine[i]->setNextStation(*AssemblyLine[j]);
					}

				}
			}
		}

	}
}


// performs **one** cycle of operations on the assembly line by doing the following:
bool LineManager::run(std::ostream& os)
{
	static size_t m_cnt = 1;
	os << "Line Manager Iteration: " << m_cnt << std::endl;
	m_cnt++;
	bool flag = false;
	if (!ToBeFilled.empty())
	{
		int counter = 0;
		for (std::size_t i = 0; i < AssemblyLine.size(); ++i)
		{
			counter = i;
			for (std::size_t j = 0; j < AssemblyLine.size(); ++j)
			{
				if (AssemblyLine[j]->getNextStation() != nullptr && AssemblyLine[i]->getItemName().compare(AssemblyLine[j]->getNextStation()->getItemName()) == 0)
				{
					counter = flag;
				}
			}
			if (counter != flag)
			{
				break;
			}
		}
		*AssemblyLine[counter] += std::move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}
	for (std::size_t i = 0; i < AssemblyLine.size(); ++i)
	{
		AssemblyLine[i]->runProcess(os);
	}
	for (std::size_t i = 0; i < AssemblyLine.size(); ++i)
	{
		if (AssemblyLine[i]->getNextStation() == nullptr)
		{
			CustomerOrder done;
			if (AssemblyLine[i]->getIfCompleted(done))
			{
				Completed.push_back(std::move(done));
			}

		}
		else
		{
			AssemblyLine[i]->moveOrder();
		}
	}
	if (Completed.size() == m_cntCustomerOrder)
	{
		return true;
	}
	else
		return false;
}
//displays all the orders that were completed
void LineManager::displayCompletedOrders(std::ostream& os) const {
	for (auto& order : Completed)
		order.display(os);

}

//display all stations on the assembly line in the order they were received from the client
void LineManager::displayStations() const {
	for (size_t i = 0; i < AssemblyLine.size(); i++)
	{
		AssemblyLine[i]->display(std::cout);

	}
}



//display all stations on the assembly line in the order they are linked.
void LineManager::displayStationsSorted() const {
	//const Workstation* wstations = firstStation;

	int counter = 0;
	for (unsigned int i = 0; i < AssemblyLine.size(); i++)
	{
		counter = i;
		for (unsigned int s = 0; s < AssemblyLine.size(); s++)
		{
			if (AssemblyLine[s]->getNextStation() != nullptr && AssemblyLine[i]->getItemName().compare(AssemblyLine[s]->getNextStation()->getItemName()) == 0)
			{
				counter = -5;
			}
		}
		if (counter != -5)
		{
			break;
		}
	}

	const Workstation* cnt = AssemblyLine[counter];
	while (cnt != nullptr)
	{
		cnt->display(std::cout);
		cnt = cnt->getNextStation();
	}
}

