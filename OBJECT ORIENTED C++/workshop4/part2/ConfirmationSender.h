// Name: Parthraj Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: Oct 14 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include "Reservation.h"

namespace sdds
{
	class ConfirmationSender
	{
		const Reservation** m_res = nullptr;
		size_t m_size = 0;
	public:
		//DID NOT INCLUDE IN INSTRUCTIONS
		ConfirmationSender();
		~ConfirmationSender();
		ConfirmationSender(ConfirmationSender&& res);
		ConfirmationSender(const ConfirmationSender& cp);
		ConfirmationSender& operator = (const ConfirmationSender& res);
		ConfirmationSender& operator = (ConfirmationSender&&);

		// FUNCTIONS FOR WORKSHOP
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator << (std::ostream& os, const ConfirmationSender& confirm);

	};
}


#endif