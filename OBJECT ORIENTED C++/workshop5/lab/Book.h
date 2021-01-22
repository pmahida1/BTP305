// Name: Parthraj Mahida
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: Oct 24 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <string>
#include <string.h>

namespace sdds
{
	class Book
	{
		std::string m_author;
		std::string m_title;
		std::string m_cpublication;
		size_t m_yearpublication;
		double m_price;
		std::string m_description;
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		double& price();
		const size_t& year() const;
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& os, const Book& b);
	};
}
#endif