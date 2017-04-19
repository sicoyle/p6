/*****************************************************
Name: Samantha Coyle
Date: 3/23/2017
Problem Number: 5
Hours spent solving the problem: 
Instructor: Komogortsev, TSU
*****************************************************/
#include <string>
#include "Song.h"

using namespace std;

//Default constructor
Song::Song()
{
	setTitle("EMPTY");
	setArtist("EMPTY");
	setSize(0);
}

//Constructor with parameters
Song::Song(string t, string a, int s)
{
	setTitle(t);
	setArtist(a);
	setSize(s);
}

//Operator to check for unequal songs
bool Song::operator != (const Song & rs)
{
	bool check = true;

	if(title == rs.title)
		check = false;

	else if(artist == rs.artist)
		check = false;

	else if(size == rs.size)
		check = false;

	return check;
}

//Operator to check for equal songs
bool Song::operator == (const Song & rs)
{
	bool check = false;
	
	if((title != rs.title) && (artist != rs.artist) && (size != rs.size))
		check = false;

//	if(title != rs.title)
//		return false;

//	else if(artist != rs.artist)
//		return false;

//	else if(size != rs.size)
//		return false;

	else
		check = true;

	return check;
}

//Operator to check for greater than
bool Song::operator > (const Song & rs)
{
	bool check = false;

	if(title > rs.title)
		check = true;

//	else if(!(artist <= rs.artist))
//		return false;

//	else if(!(size < rs.size))
//		return false;
	
	else
		return check;
}

//Operator to check for less than
bool Song::operator < (const Song & rs)
{
	bool check = false;

	if(title < rs.title)
		check = true;
		
//	if(artist < rs.artist)
//		check = true;

//	if(size >= rs.size)
//		check = true;

	else
		return check;
}
