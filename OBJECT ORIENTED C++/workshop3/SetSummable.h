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
#ifndef SDDS_SetSummable_H_
#define SDDS_SetSummable_H_
#include "Set.h"
using namespace std;
namespace sdds
{

	template < typename T, unsigned int N>
	class SetSummable :public Set <T, N>
	{
	public:
		T accumulate(const std::string& filter) const
		{
			
			T m_accumulator(filter);
			
			for (size_t i = 0; i < N; i++) {
				
				m_accumulator += (*this)[i];
			}
			return m_accumulator;
		}
		
	};
}




#endif