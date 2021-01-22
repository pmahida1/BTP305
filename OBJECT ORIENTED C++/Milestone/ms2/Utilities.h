// Name: Parthraj Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: November 15th, 2020
// // I confirm that I am the only author of this file
// and the content was created entirely by me.
#ifndef UTILITIES_H
#define UTILITIES_H
#include <string>

class Utilities
{
	size_t m_widthField; //length of token extracted
	static char m_delimiter; //seperates the tokens from a given std::string ,static because all utilities objects share the same delimiter

public:
	Utilities();
	void setFieldWidth(size_t newWidth);
	size_t getFieldWidth() const;
	std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(char delimiter);
	static char getDelimiter();
};


#endif