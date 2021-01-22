// Name: parthraj mahida
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca	
// Date of completion: Nov 14 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
#include <numeric>
#include "SongCollection.h"

namespace sdds {
	std::string SongCollection::RemoveBegSpaces(std::string str) {

		unsigned int index = 0;
		while (index == str.find(' ')) {
			str.erase(0, 1);
		}
		return str;
	}

	std::string SongCollection::RemoveEndSpaces(std::string str) {

		unsigned int index = (str.length() - 1);
		while (index == str.find_last_of(' ')) {
			str.erase(index, 1);
			--index;
		}
		return str;
	}

	SongCollection::SongCollection(const char* filename) {//recives as parameter the name of the file

		//If the filename is incorrect, this constructor should throw an exception.
		std::ifstream file(filename);
		if (!file)
			throw("Incorrect filename!");

		while (file)
		{
			std::string str;
			std::getline(file, str);
			Song tmp;

			if (file) {

				std::string checkYear;
				std::string checkLength;
				std::string checkPrice;

				std::string title = RemoveBegSpaces(str.substr(0, 25));
				tmp.m_title = RemoveEndSpaces(title);
				str.erase(0, 25);
				std::string artist = RemoveBegSpaces(str.substr(0, 25));
				tmp.m_artist = RemoveEndSpaces(artist);
				str.erase(0, 25);
				std::string album = RemoveBegSpaces(str.substr(0, 25));
				tmp.m_album = RemoveEndSpaces(album);
				str.erase(0, 25);
				std::string year = (str.substr(0, 5));
				if (str[0] != ' ')
					tmp.m_year = RemoveEndSpaces(year);
				str.erase(0, 5);
				checkLength = RemoveEndSpaces(str.substr(0, 5));
				if (checkLength != "")
					tmp.m_length = std::stoi(checkLength);
				str.erase(0, 5);
				checkPrice = RemoveEndSpaces(str.substr(0, 5));
				if (checkPrice != "")
					tmp.m_price = std::stod(checkPrice);
				str.erase(0, 5);
				m_songs.push_back(tmp);
			}
		}
		file.close();//close file
		//TITLE ARTIST ALBUM - 25 characters 
		//YEAR LENGTH PRICE -  5 characters

	}

	void SongCollection::sort(const char* field) {

		std::string title = "title";
		std::string album = "album";
		std::string length = "length";
		if (field == title) {
			std::sort(m_songs.begin(), m_songs.end(), [&](const Song& song1, const Song& song2) {
				return song1.m_title < song2.m_title; });
		}
		if (field == album) {
			std::sort(m_songs.begin(), m_songs.end(), [&](const Song& song1, const Song& song2) {
				return song1.m_album < song2.m_album; });
		}
		if (field == length) {
			std::sort(m_songs.begin(), m_songs.end(), [&](const Song& song1, const Song& song2) {
				return song1.m_length < song2.m_length; });
		}
	}

	void SongCollection::cleanAlbum() {
		//removes the token[None] from the album field of the songs that do not have a valid album.DO NOT USE MANUAL LOOPS!

		for_each(m_songs.begin(), m_songs.end(), [&](Song& song) {
			if (song.m_album == "[None]")
				song.m_album = " ";
			});
	}

	bool SongCollection::inCollection(const char* artist) const {
		bool flag = false;
		std::string art = artist;
		//receives the name of an artist as a parameter, and returns true if the 
		//collection contains any song by that artist.DO NOT USE MANUAL LOOPS!
		if (std::any_of(m_songs.begin(), m_songs.end(), [art](const Song& song) {
			return (song.m_artist == art);

			}))
			flag = true;
	return flag;
	}

	std::list<Song> SongCollection::getSongsForArtist(const char* artist) const {
		//receives the name of an artist as a parameter, and returns 
		//the list of songs of that artist available in the collection.DO NOT USE MANUAL LOOPS!
		std::list<Song> songs;
		std::string art = artist;
		std::copy_if(m_songs.begin(), m_songs.end(), back_inserter(songs), [art](const Song& song)
			{ return (song.m_artist == art); });

		return songs;
	}

	void SongCollection::display(std::ostream& out) const {

		for_each(m_songs.begin(), m_songs.end(), [&out](const Song& song) {out << song << std::endl; });

		auto sum = std::accumulate(m_songs.begin(), m_songs.end(), 0u,
			[](size_t i, const Song& song) { return song.m_length + i; });


		out << "----------------------------------------------------------------------------------------" << std::endl;
		out.setf(std::ios::right);
		int min = (sum / 60);
		int sec = (sum % 60);
		int hour = (min / 60);
		int Fmin = (min % 60);
		std::string total = ("Total Listening Time: " + std::to_string(hour) + ":" + std::to_string(Fmin) + ":" + std::to_string(sec));
		out << "|" << std::setw(85) << total << " |" << std::endl;
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong) {

		out.unsetf(std::ios::right);
		out.setf(std::ios::left);
		out << std::setfill(' ');
		out << "| " << std::setw(20) << theSong.m_title;
		out << " | " << std::setw(15) << theSong.m_artist;
		out << " | " << std::setw(20) << theSong.m_album;
		out.unsetf(std::ios::left);
		out.setf(std::ios::right);
		out << " | " << std::setw(6) << theSong.m_year;
		out << " | " << (theSong.m_length / 60) << ":" << std::setw(2) << std::setfill('0') << (theSong.m_length % 60);
		out << std::setfill(' ') << " | " << theSong.m_price << " |";

		return out;
	}

}