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
//Header Guards 
#ifndef SDDS_SET_H
#define SDDS_SET_H

using namespace std;
namespace sdds
{
	template <class T, unsigned int N>//•	T: the type of any element in the collection. •	N: the maximum number of 
	//elements in the collection (a non-type parameter; an integer without sign)
	class Set
	{
		T m_capacity[N]; //capacity of the array
		size_t m_numOfElements = 0; //number of elemnets added to the set //or size_t


	public:
		size_t size() const //returns the current number of elements in the collection
		{
			return m_numOfElements;
		}

		const T& operator[](size_t idx) const //returns elements at Index idx (i) if parameter is valid 
		{
			return m_capacity[idx];
		}
		void operator+=(const T& item) //): if the collection has capacity for another element, adds a copy of item to the collection
		{
			if (N > m_numOfElements)
			{
				m_capacity[m_numOfElements] = item;
				m_numOfElements++;
			}
		}
	};

}

#endif