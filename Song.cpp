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
	if(title == rs.title)
		return false;

	else if(artist == rs.artist)
		return false;

	else if(size == rs.size)
		return false;

	return true;
}

//Operator to check for equal songs
bool Song::operator == (const Song & rs)
{
	if(title != rs.title)
		return false;

	else if(artist != rs.artist)
		return false;

	else if(size != rs.size)
		return false;

	return true;
}

//Operator to check for greater than
bool Song::operator > (const Song & rs)
{
	if(!(title <= rs.title))
		return false;

	else if(!(artist <= rs.artist))
		return false;

	else if(!(size < rs.size))
		return false;

	return true;
}

//Operator to check for less than
bool Song::operator < (const Song & rs)
{
	if(!(title >= rs.title))
		return false;

	if(!(artist >= rs.artist))
		return false;

	if(!(size >= rs.size))
		return false;

	return true;
}
