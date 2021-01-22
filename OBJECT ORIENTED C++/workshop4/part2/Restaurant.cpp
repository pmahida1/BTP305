// Name: Parthraj Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: Oct 14 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS_
#include <ostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "Restaurant.h"

namespace sdds
{
	Restaurant::Restaurant() {
		m_res = nullptr;
		m_num = 0;
	}

	sdds::Restaurant::Restaurant(Reservation* reservations[], size_t cnt)
	{
		if (reservations != nullptr && cnt > 0)
		{
			m_res = new Reservation * [cnt];
			for (size_t i = 0; i < cnt; i++) {
				m_res[m_num] = new Reservation(*reservations[i]); 
				m_num++;
			}

		}
		else
		{
			*this = Restaurant();
		}
	}

	

	Restaurant::Restaurant(const Restaurant& cp) 
	{
		*this = cp;
	}

	// Copy assignment
	Restaurant& Restaurant::operator= (const Restaurant& cp) {
		if (this != &cp) {
			delete[] m_res;
			m_num = cp.m_num;
			m_res = new Reservation * [m_num];

			for (size_t i = 0; i < m_num; i++) {
				m_res[i] = new Reservation;
				*(m_res[i]) = *(cp.m_res[i]);
			}
		}
		return *this;
	}
	//Move assignment
	Restaurant& Restaurant::operator=(Restaurant&& mv)
	{
		// TODO: insert return statement here
		if (this != &mv)
		{
			delete[] m_res;
			m_num = mv.m_num;
			m_res = mv.m_res;
			mv.m_num = 0;
			mv.m_res = nullptr;
		}
		return *this;
	}

	// Move constructor
	Restaurant::Restaurant(Restaurant&& mv)
	{
		*this = std::move(mv);
	}

	size_t Restaurant::size() const
	{
		return m_num;
	}

	Restaurant::~Restaurant()
	{

		for (size_t i = 0; i < m_num; i++)
		{
			delete m_res[i];
		}
		delete[] m_res; //you can do just this but memory leak
	}


	//overload insertion operator
	std::ostream& operator << (std::ostream& os, const Restaurant& res) {
		if (res.size() == 0) {
			os << "--------------------------" << std::endl;
			os << "Fancy Restaurant" << std::endl;
			os << "--------------------------" << std::endl;
			os << "The object is empty!" << std::endl;
			os << "--------------------------" << std::endl;

		}
		else {
			os << "--------------------------" << std::endl;
			os << "Fancy Restaurant" << std::endl;
			os << "--------------------------" << std::endl;

			for (size_t i = 0; i < res.m_num; i++) {
				os << *res.m_res[i];
			}

			os << "--------------------------" << std::endl;

		}
		return os;
	}

}
