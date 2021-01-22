// Name: Parthraj Mahida
// Seneca Student ID:  140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: 20 oct 2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <string>

namespace sdds {
	class Book {
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year = 0;
		double m_price = 0;
		std::string m_desc;
		void trim(std::string& src) const;
	public:
		Book() {};
		Book(const std::string&);

		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();

		friend std::ostream& operator<<(std::ostream&, const Book&);

		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_desc);
		}
	};

}
#endif