// Name: Parthraj Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: Oct 14 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include "Reservation.h"
#include <iostream>

namespace sdds
{
	class Restaurant
	{
		Reservation** m_res = nullptr;
		size_t m_num = 0;

	public:
		
		Restaurant();
		Restaurant(const Restaurant& cp);
		Restaurant& operator=(const Restaurant& cp);
		Restaurant& operator = (Restaurant&&);
		Restaurant(Reservation* reservations[], size_t cnt);
		Restaurant(Restaurant&&);
		size_t size() const;
		friend std::ostream& operator << (std::ostream& os, const Restaurant& restaurant);
		~Restaurant();

	};
}


#endif