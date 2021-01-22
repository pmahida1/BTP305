// Name: Parthraj Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: Oct 14 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef _SDDS_RESERVATION_H_
#define _SDDS_RESERVATION_H_
#include <iostream>
using namespace std;
namespace sdds
{
	class Reservation
	{
	private:
		string m_reservationID;
		string m_reservationName;
		string m_email;
		unsigned int m_numOfppl;
		unsigned int m_day;
		unsigned int m_hour;
	public:
		Reservation();
		void trim(std::string& str);
		Reservation(const string& res);
		friend ostream& operator<<(ostream& os, const Reservation& copy);
	};
}
#endif