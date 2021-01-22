// Name: Parthraj Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: 11 Nov 2020
// // I confirm that I am the only author of this file
// and the content was created entirely by me.
#include <iostream>
#include <string>
#include "Utilities.h"

Utilities::Utilities()
{
	m_widthField = 1;
	//m_delimiter = 0;
}
char Utilities::m_delimiter = '\0';

void Utilities::setFieldWidth(size_t newWidth)
{
	this->m_widthField = newWidth;


}
size_t Utilities::getFieldWidth() const
{
	return	this->m_widthField;

}
std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
	std::string m_temp = str;
	std::string m_token = "";
	size_t m_delim = m_temp.find(this->m_delimiter, next_pos);
	m_token = m_temp.substr(next_pos, (m_delim - next_pos));
	if (m_token.empty()) {
		more = false;
		throw "No more delimiters!";
	}
	else {
		this->setFieldWidth(m_token.size());
		return m_token;
	}

	return std::string();
}

char Utilities::getDelimiter()
{
	return m_delimiter;
}

void Utilities::setDelimiter(char delimiter)
{
	m_delimiter = delimiter;
}


