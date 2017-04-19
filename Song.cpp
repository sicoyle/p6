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
	bool check;

	if((title == rs.title) && (artist == rs.artist) && (size == rs.size))
		check = false;
	else
		check = true;

	return check;
}

//Operator to check for equal songs
bool Song::operator == (const Song & rs)
{
	bool check;

	if((title != rs.title) && (artist != rs.artist) && (size != rs.size))
		check = false;
	else
		check = true;

	return check;
}

//Operator to check for greater than
bool Song::operator > (const Song & rs)
{
	bool check;

	if(title > rs.title)
		check = true;

	else
		check = false;

	return check;
}

//Operator to check for less than
bool Song::operator < (const Song & rs)
{
	bool check;
	
	if(title < rs.title)
		check = true;

	if(title == rs.title && artist < rs.artist)
		
		check = false;

	return check;
}
