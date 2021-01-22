// Name: Parth Mahida 
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: November 19th 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers

		for (size_t i = 0; i < desc.size(); ++i) {  //loops through desc list
			for (size_t j = 0; j < price.size(); ++j) { //loops through price list
				if (desc[i].code == price[j].code) {
					Product* temp = new Product(desc[i].desc, price[j].price);
					temp->validate();
					priceList += temp;
					delete temp;
				}
			}

		}

		return priceList;
	}


	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers

		for (size_t i = 0; i < desc.size(); ++i) {  //loops through desc list
			for (size_t j = 0; j < price.size(); ++j) { //loops through price list
				if (desc[i].code == price[j].code) {
					std::unique_ptr<Product> temp(new Product(desc[i].desc, price[j].price));
					temp->validate();
					priceList += temp;
				}
			}

		}

		return priceList;
	}
}
