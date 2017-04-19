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

	retCode = myPod.getTotalMem();
	cout << "Total memory: " << retCode << " MB" << endl;

	//Unsuccessfully try to remove a song from the playlist
	Song mySong20("Cold Like Minnesota", "Lil Yati", 3);
	retCode = myPod.removeSong(mySong20);
		cout << "Invalid song removal - song not in playlist: " << retCode << endl;

	//Add a song to playlist
	Song mySong1("Hello", "Adele", 1);
        retCode = myPod.addSong(mySong1);
		cout << "Add song return code: " << retCode << endl;

	//Add a song to playlist
	Song mySong2("Castle on the Hill", "Ed Sheeran",2);
	retCode = myPod.addSong(mySong2);
		cout << "Add song return code: " << retCode << endl;

	//Add a song to playlist
	Song mySong3("Paris", "Chain Smokers", 3);
	retCode = myPod.addSong(mySong3);
		cout << "Add song return code: " << retCode << endl;

	//Add a song to playlist
	Song mySong4("Issues", "Julia Michaels", 4);
	retCode = myPod.addSong(mySong4);
		cout << "Add song return code: " << retCode << endl;

	//Add a song to playlist
	Song mySong5("Starboy", "The Weeknd", 5);
	retCode = myPod.addSong(mySong5);
		cout << "Add song return code: " << retCode << endl;

  	//Adds song to playl;ist
  	Song mySong6("Mattress", "Front Bottoms", 6);
	retCode = myPod.addSong(mySong6);
		cout << "Add song return code: " << retCode << endl;

	//Unsuccessful song addition - lack of memory
	Song mySong7("Earned it", "The Weeknd", 22);
    	retCode = myPod.addSong(mySong7);
		cout << "Add song return code: " << retCode << endl;

    	//Adds song to playlist
	Song mySong8("Dream On", "Aerosmith", 1);
    	retCode = myPod.addSong(mySong8);
		cout << "Add song return code: " << retCode << endl;

    	//Adds song to playlist
	Song mySong9("Caroline", "Amine", 1);
    	retCode = myPod.addSong(mySong9);
		cout << "Add song return code: " << retCode << endl;
 
    	//Adds song to playlist
	Song mySong10("Irresistible", "Fall Out Boys", 1);
    	retCode = myPod.addSong(mySong10);
		cout << "Add song return code: " << retCode << endl;

    	//Unsuccessful song addition - size is less than zero
	Song mySong11("Formation", "Beyonce", 700);
    	retCode = myPod.addSong(mySong11);
		cout << "Unsuccessful song addition - invalid size: " << retCode << endl;

	//Display playlist contents
	cout << "Playlist with songs added:" << endl;
	myPod.showList();

	//Remove a song from the playlist
	retCode = myPod.removeSong(mySong1);
		cout << "Remove song return code: " << retCode << endl;

	//Display playlist contents with song(s) removed
	cout << "Playlist with song(s) removed:" << endl;
	myPod.showList();

	//Sort the playlist
	myPod.sortList();
	myPod.sortList();
	myPod.sortList();
	myPod.sortList();
	myPod.sortList();
	myPod.sortList();
	myPod.sortList();
	myPod.sortList();
	myPod.sortList();
		cout << "Playlist with songs sorted: " << endl;

	//Display sorted playlist contents
	myPod.showList();	

	//Display shuffled playlist contents
	myPod.shuffle();
	myPod.shuffle();
	myPod.shuffle();
	cout << "Playlist with songs shuffled: " << endl;	
	myPod.showList();
	

	retCode = myPod.getRemainingMem();
	cout << endl << "Remaining memory: " << retCode << " MB" << endl;

	//Display cleared list
	myPod.clearList();
	cout << "Cleared list: " << endl;
	myPod.showList();


	return 0;
}
