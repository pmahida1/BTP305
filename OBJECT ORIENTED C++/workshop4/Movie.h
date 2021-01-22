// Name: Parthraj Mahida
// Seneca Student ID:  140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: 20 oct 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#ifndef _SDDS_Movie_H_
#define _SDDS_Movie_H_

#include <string>
#include <iostream>
#include "SpellChecker.h"


#include <iostream>
#include <string>
namespace sdds {
	class Movie {
		std::string m_title;
		size_t m_year;
		std::string m_desc;
		void trim(std::string&) const;
	public:
		Movie();
		Movie(const std::string& strMovie);
		~Movie() {};

		const std::string& title() const {
			return m_title;
		}

		template <typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_title);
			spellChecker(m_desc);
		}
		friend std::ostream& operator<<(std::ostream&, const Movie&);

	};
}

#endif