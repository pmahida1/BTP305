/*
Name: Parthraj Mahida
Email: pmahida1@myseneca.ca
Student Number: 140 172 180
Date Completion: Oct - 03 - 2020
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H
#include <string>

namespace sdds {
	class RecordSet
	{
		std::string* record{ nullptr };
		size_t num{ 0 };

	public:
		RecordSet();
		RecordSet(const std::string&);
		RecordSet(const RecordSet&);
		RecordSet(RecordSet&&);
		RecordSet& operator=(const RecordSet&);
		RecordSet& operator=(RecordSet&&);
		~RecordSet();
		size_t size() const;
		std::string getRecord(size_t index);
	};

}
#endif