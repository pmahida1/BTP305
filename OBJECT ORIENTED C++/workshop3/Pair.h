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
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H

#include <iostream>

using namespace std;

namespace sdds
{
	template <typename K, typename V>

	class Pair
	{
		K m_keyType;
		V m_valueType;
	public:
		Pair() {
			//m_keyType = 0;
			//m_keyType = 0;
		}
		Pair(const K& key, const V& value)//copies the values referred to by the parameters into the instance variables
		{
			m_keyType = key;
			m_valueType = value;
		}
		const K& key() const//returns the key component of the pair
		{
			return m_keyType;
		}
		const V& value() const //returns the value component of the pair
		{
			return m_valueType;
		}
		virtual void display(std::ostream& os) const
		{
			cout << m_keyType << " : " << m_valueType << endl;
		}

	};
	template <typename K, typename V>
	ostream& operator<<(ostream& os, const Pair<K, V>& pair)
	{
		pair.display(os);
		return os;
	}
}


#endif