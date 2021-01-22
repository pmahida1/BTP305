// Name: parthraj mahida
// Seneca Student ID: 140 172 180
// Seneca email: pmahida1@myseneca.ca	
// Date of completion: Nov 14 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include<string>
#include <vector>
#include<list>

namespace sdds
{
	struct Song {
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price;
		int m_length = 0; //seconds
		std::string m_year;
	};

	class SongCollection {
		std::vector<Song> m_songs; //manages a collection of objects of type Song
		std::string RemoveEndSpaces(std::string str);
		std::string RemoveBegSpaces(std::string str);

	public:
		SongCollection(const char* filename);  //recives as parameter the name of the file
		void display(std::ostream& out) const;
		void sort(const char* field);
		//receives as a parameter the name of the field used to 
		//sort the collection of songs in ascending order.The parameter can have one of the values 
		//title, album, or length.DO NOT USE MANUAL LOOPS!

		void cleanAlbum();
		//removes the token[None] from the album field of the songs that do not have a valid album.DO NOT USE MANUAL LOOPS!

		bool inCollection(const char* artist) const;
		//receives the name of an artist as a parameter, and returns true if the 
		//collection contains any song by that artist.DO NOT USE MANUAL LOOPS!

		std::list<Song> getSongsForArtist(const char* artist) const;
		//receives the name of an artist as a parameter, and returns 
		//the list of songs of that artist available in the collection.DO NOT USE MANUAL LOOPS!

	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);

}

#endif
