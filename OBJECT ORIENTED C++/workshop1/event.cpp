//Parthraj Mahida 
// 140 172 180
//workshop 1
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "event.h"
using namespace std;
unsigned int g_sysClock = 0;

namespace sdds {

	Event::Event() {
		description = nullptr;
		time = 0;
	}

	Event::Event(const Event& src) {
		if (src.description != nullptr) {
			description = new char[strlen(src.description) + 1];
			strcpy(description, src.description);
			time = src.time;
		}
		else {
			description = nullptr;
			time = 0;
		}
	}

	Event::~Event() {
		delete[] description;
		description = nullptr;
	}

	void Event::display() const {
		static int counter = 0;
		cout << setfill(' ') << setw(3) << ++counter << ". ";
		if (!description) {
			cout << "[ No Event ]" << endl;
		}
		else {
			cout << setfill('0')
				<< setw(2) << time / 3600 << ":"
				<< setw(2) << (time % 3600) / 60 << ":"
				<< setw(2) << time % 60 << " -> " << description << endl;
		}
	}

	void Event::setDescription(const char* src) {
		delete[] description;
		description = nullptr;

		if (!src || !*src) {
			description = nullptr;
			time = 0;
		}
		else {
			description = new char[strlen(src) + 1];
			strcpy(description, src);
			time = g_sysClock;
		}
	}

	Event& Event::operator=(const Event& src) {
		if (this != &src) {
			if (src.description != nullptr) {
				description = new char[strlen(src.description) + 1];
				strcpy(description, src.description);
				time = src.time;
			}
			else {
				description = nullptr;
				time = 0;
			}

		}
		return *this;
	}
}