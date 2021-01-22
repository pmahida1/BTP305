// Name: Parthraj Mahida
// Seneca Student ID:  140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: 20 oct 2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS_
#include "SpellChecker.h"
#include <iostream>
#include <fstream>

#include <iomanip>
#include <fstream>
#include "SpellChecker.h"
using namespace std;

namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}
		for (size_t i = 0; i < MAX; i++) {
			file >> m_badWords[i];
			file >> m_goodWords[i];
		}
	}

	void SpellChecker::operator()(std::string& text) const {
		for (size_t i = 0; i < MAX; i++) {
			while (text.find(m_badWords[i]) != string::npos) {
				text = text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
			}
		}
	}
}