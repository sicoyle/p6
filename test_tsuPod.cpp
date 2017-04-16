/****************************************************
Name: Samantha Coyle
Date: 4/18/2017
Problem Number: 6
Hours spent solving the problem: 
Instructor: Komogortsev, TSU
*****************************************************/
#include <iostream>
#include <fstream>
#include "tsuPod.h"

using namespace std;

int main()
{
	//instantiate myPod
	TsuPod myPod(256);

	int retCode = -1;

	Song mySong1("Hello", "Adele", 1);
        retCode = myPod.addSong(mySong1);
		cout << "Add song return code: " << retCode << endl;

	Song mySong2("Castle on the Hill", "Ed Sheeran",2);
	retCode = myPod.addSong(mySong2);
		cout << "Add song return code: " << retCode << endl;



	Song mySong3("Paris", "Chain Smokers", 3);
	retCode = myPod.addSong(mySong3);
		cout << "Add song return code: " << retCode << endl;

	Song mySong4("Issues", "Julia Michaels", 4);
	retCode = myPod.addSong(mySong4);
		cout << "Add song return code: " << retCode << endl;

	Song mySong5("Starboy", "The Weeknd", 5);
	retCode = myPod.addSong(mySong5);
		cout << "Add song return code: " << retCode << endl;

	cout << "Playlist with songs added:" << endl;
	myPod.showList();

	retCode = myPod.removeSong(mySong1);
		cout << "Remove song return code: " << retCode << endl;

	retCode = myPod.removeSong(mySong4);
		cout << "Remove song return code: " << retCode << endl;

	cout << "Playlist with song(s) removed:" << endl;
	myPod.showList();

}
