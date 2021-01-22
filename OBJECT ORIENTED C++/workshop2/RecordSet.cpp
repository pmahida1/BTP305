/*
Name: Parthraj Mahida
Email: pmahida1@myseneca.ca
Student Number: 140 172 180
Date Completion: Oct - 03 - 2020
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <string>
#include "RecordSet.h"

namespace sdds {
	RecordSet::RecordSet()
	{
		record = nullptr;
		num = 0;
	}

	RecordSet::RecordSet(const std::string& filename)
	{
		std::ifstream f(filename.c_str());
		num = 1; 
		record = nullptr;
		if (!f) return;

		do
		{
			char ch = f.get();

			if (ch == ' ')
				num++;
		} while (!f.eof());

		
		f.clear();// make eof() status NO
		f.seekg(std::ios::beg);
		record = new std::string[num];

		for (auto i = 0u; i < num; i++) {
			std::getline(f, record[i], ' ');
		}

	}

	RecordSet::RecordSet(const RecordSet& src)
	{
		*this = src;
	}

	RecordSet::RecordSet(RecordSet&& src) {
		*this = std::move(src);
	}

	RecordSet& RecordSet::operator=(const RecordSet& src)
	{
		if (this != &src)
		{
			num = src.num;
			delete[] record;
			record = nullptr;
			if (num != 0) {
				record = new std::string[num];
				for (auto i = 0u; i < num; i++) {
					record[i] = src.record[i];
				}
			}

		}
		return *this;
	}

	RecordSet& RecordSet::operator=(RecordSet&& src)
	{
		if (this != &src)
		{
			delete[] record;
			record = src.record;
			num = src.num;
			src.record = nullptr;
			src.num = 0;
		}
		return *this;
	}

	RecordSet::~RecordSet()
	{
		delete[] record;
	}

	size_t RecordSet::size() const
	{
		return num;
	}

	std::string RecordSet::getRecord(size_t index)
	{
		if (index >= num)
			return "";
		else
			return record[index];
	}

}