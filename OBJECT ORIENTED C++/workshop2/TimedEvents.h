/*
Name: Parthraj Mahida
Email: pmahida1@myseneca.ca
Student Number: 140 172 180
Date Completion: Oct - 03 - 2020
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <iostream>
#include <chrono>
#include <string>

namespace sdds {
	const int MAX_RECORDS = 7;
	class TimedEvents {
		int nr{ 0 };
		std::chrono::steady_clock::time_point ts;
		std::chrono::steady_clock::time_point te;
		struct {
			std::string msg{};
			std::string units{};
			std::chrono::steady_clock::duration duration{};
		} events[MAX_RECORDS];
	public:
		void startClock();
		void stopClock();
		void recordEvent(const char*);
		friend std::ostream& operator<<(std::ostream& out, const TimedEvents& events);
	};
}
#endif