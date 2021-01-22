// Name: Parthraj Mahida
// Seneca Student ID:  140 172 180
// Seneca email: pmahida1@myseneca.ca
// Date of completion: 20 oct 2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.



#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>

namespace sdds {
	template<typename T>
	class Collection {
		std::string m_name = "";
		T* m_items = nullptr;
		size_t m_size = 0;
		void (*addItem)(const Collection<T>&, const T&) = nullptr;
	public:
		Collection(std::string name) {
			m_name = name;
		}
		Collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;
		~Collection() {
			delete[] m_items;
		}

		const std::string& name() const {
			return m_name;
		}
		size_t size() const {
			return m_size;
		}
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			addItem = observer;
		}

		Collection<T>& operator+=(const T& item) {
			for (size_t i = 0; i < m_size; i++) {
				if (m_items[i].title() == item.title()) {
					return *this;
				}
			}
			T* temp = new T[m_size + 1];
			for (size_t i = 0; i < m_size; i++) {
				temp[i] = m_items[i];
			}
			temp[m_size] = item;
			delete[] m_items;
			m_items = temp;
			++m_size;

			if (addItem != nullptr) {
				addItem(*this, m_items[m_size - 1]);
			}
			return *this;
		}

		T& operator[](size_t idx) const {
			if (idx >= m_size) {
				std::string msg = "";
				msg = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.";
				throw std::out_of_range(msg);
			}
			return m_items[idx];
		}

		T* operator[](std::string title) const {
			for (size_t i = 0; i < m_size; i++) {
				if (m_items[i].title() == title) {
					return &(m_items[i]);
				}
			}
			return nullptr;
		}
	};
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {
		for (size_t i = 0; i < collection.size(); i++) {
			os << collection[i];
		}
		return os;
	}
}
#endif