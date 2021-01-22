// Name: Parthraj Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: November 15th, 2020
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
	std::string temp;    // Returning temp

	size_t new_pos = str.find(m_delimiter, next_pos + 1);

	size_t length = (new_pos - next_pos);

	temp = str.substr(next_pos, length);

	next_pos = new_pos + 1;

	if (m_widthField < temp.length())
		m_widthField = temp.length();

	if (temp == "")
	{
		more = false;
		throw "Error! No tokens can be found!";
	}
	else
	{
		more = true;
		return temp;
	}
}

char Utilities::getDelimiter()
{
	return m_delimiter;
}

void Utilities::setDelimiter(char delimiter)
{
	m_delimiter = delimiter;
}


