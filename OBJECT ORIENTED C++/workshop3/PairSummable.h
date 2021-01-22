//
// Name: Parthraj Mahida
// Seneca Student ID: 140-172-180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: Oct 08 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_PairSummable_H_
#define SDDS_PairSummable_H_
#include <iostream>
#include <iomanip>

#include "Pair.h"
using namespace std;
namespace sdds
{
	/*Derive the PairSummable class template from Pair<K, V>. Your template receives 2 template parameters:
•	K: the type of the key
•	V: the type of the value
*/
	template <typename K, typename V>
	class PairSummable : public Pair<K, V>
	{
		static V m_initialValue;
		static size_t m_width;

	public:
		PairSummable() {}

		PairSummable(const K& key, const V& value = m_initialValue) : Pair <K, V>(key, value)
		{
			if (m_width < key.size())
			{
				m_width = key.size();
			}
		}
		PairSummable& operator+=(const PairSummable& copy)
		{
			if (this != &copy && this->key() == copy.key())
				*this = PairSummable(this->key(), this->value() + copy.value());
			return *this;
		}
		
		 void display(std::ostream& os) const 
		 {
			os.setf(ios::left);
			os.width(m_width);
			Pair<K, V> ::display(os);
			os.unsetf(ios::left);
		}
	};
	
	//Specializations
	template <typename K, typename V>
	size_t PairSummable<K, V>::m_width = 0;
	// initial value for summation is = empty string (" ")
	template<>
    string PairSummable<string, string> ::m_initialValue = "";
	template<> //initial value for summation should be 0.
	int PairSummable<string, int> ::m_initialValue = 0;

	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& copy)

	{
		if (this != &copy && copy.key() == this->key()) {
			if (this->value() != "")
				*this = PairSummable(this->key(), this->value() + ", " + copy.value());
			else
				*this = PairSummable(this->key(), this->value() + copy.value());
		}
		return *this;
	}
}

#endif