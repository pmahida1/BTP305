// Name: Parthraj Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: Oct 14 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.																				
#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <cstring>
#include "ConfirmationSender.h"
using namespace std;
namespace sdds
{
	sdds::ConfirmationSender::ConfirmationSender()
	{
		m_res = nullptr;
		m_size = 0;
	}

	sdds::ConfirmationSender::~ConfirmationSender()
	{
		delete[] m_res;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& res)
	{
		*this = std::move(res);
	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool equal = false;

		for (size_t i = 0; i < m_size; i++) {
			if (m_res[i] == &res) {
				equal = true;
			}
		}

		if (equal == false) {
			const Reservation** temp = nullptr;
			temp = new const Reservation * [m_size + 1];
			for (size_t i = 0; i < m_size; ++i)
				temp[i] = m_res[i];
			temp[m_size] = &res;

			++m_size;
			delete[] m_res;
			m_res = temp;
		}

		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		for (size_t i = 0; i < m_size; i++) {
			if (m_res[i] == &res) {
				m_res[i] = nullptr;
			}
		}
		return *this;
	}

	//Copy
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& cp) {
		*this = cp;
	}
	//Copy assignment
	ConfirmationSender& ConfirmationSender::operator= (const ConfirmationSender& cp) {
		if (this != &cp) {
			delete[] m_res;
			m_size = cp.m_size;
			m_res = new const Reservation * [m_size];

			for (size_t i = 0; i < m_size; i++) {
				m_res[i] = cp.m_res[i];
			}
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& mv)
	{
		// TODO: insert return statement here
		if (this != &mv) {
			delete[] m_res;
			m_res = mv.m_res;
			m_size = mv.m_size;
			mv.m_size = 0;
			mv.m_res = nullptr;
		}
		return *this;
	}

	


	std::ostream& operator << (std::ostream& os, const ConfirmationSender& confirm) {
		if (confirm.m_res == nullptr) {

			os << "--------------------------" << std::endl;
			os << "Confirmations to Send" << std::endl;
			os << "--------------------------" << std::endl;
			os << "The object is empty!" << std::endl;
			os << "--------------------------" << std::endl;

		}
		else {
			os << "--------------------------" << std::endl;
			os << "Confirmations to Send" << std::endl;
			os << "--------------------------" << std::endl;
			for (size_t i = 0; i < confirm.m_size; i++) {
				if (confirm.m_res[i] != nullptr) {
					os << *confirm.m_res[i];
				}
			}

			os << "--------------------------" << std::endl;

		}
		return  os;
	}
}


