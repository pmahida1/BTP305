// Name: Parthraj Mahida
// Seneca Student ID:  140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: 20 oct 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <iostream>
#include <string>

namespace sdds {
	const int MAX = 5;
	class SpellChecker {
		std::string m_badWords[MAX];
		std::string m_goodWords[MAX];
	public:
		SpellChecker(const char*);
		void operator()(std::string&) const;

	};
}

#endif