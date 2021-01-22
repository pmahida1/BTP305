// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h"

using namespace sdds;

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";
	// get the books
	size_t counter = 0;
	sdds::Book library[7];
	{
		std::ifstream file(argv[1]);
		if (!file)
		{
			std::cerr << "Error: Can't Open File![" << argv[1] << "].\n";
			file.setstate(std::ios::badbit);

			return 1;
		}
		std::string stringbook;
		do
		{
			std::getline(file, stringbook);
			if (file)
			{
				if (stringbook[0] != '#')
				{
					counter++;
				}
			}
		} while (file);
		counter = 0;
		file.clear();
		file.seekg(std::ios::beg);
		do
		{
			std::getline(file, stringbook);
			if (file)
			{
				if (stringbook[0] != '#')
				{
					library[counter] = Book(stringbook);
					counter++;
				}
			}
		} while (file);
		file.close();


		// TODO: load the collection of books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the array "library"
		//       - lines that start with "#" are considered comments and should be ignored


	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object
	auto m_updatePrice = [&](Book& b)
	{double m_total = b.price();
	if (b.country() == "US")
	{
		b.price() = b.price() * usdToCadRate;
	}

	if ((b.country() == "UK") && ((b.year() >= 1990 && b.year() <= 1999)))
	{
		b.price() = b.price() * gbpToCadRate;
	}
	return m_total;

	};

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n\n";

	// TODO: iterate over the library and update the price of each book
	//         using the lambda defined above.
	for (size_t i = 0; i < counter; i++)
	{
		m_updatePrice(library[i]);
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n";

	return 0;
}