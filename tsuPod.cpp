/****************************************************
Name: Samantha Coyle
Date: 4/18/2017
Problem Number: 6
Hours spent solving the problem:6 
Instructor: Komogortsev, TSU
*****************************************************/
#include <iostream>
#include <fstream>
#include "tsuPod.h"
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <stdlib.h>
#include <string>

using namespace std;

//Constructor for tsuPod with parameters
TsuPod::TsuPod(int mem)
{
	head = NULL;		//initialize head to null
	totMem = mem;		//initialize total memory
	cmem = csongs = 0;	//initialize consumed mem and songs to 0
}

//Deconstructor for tsuPod
TsuPod::~TsuPod(){}

//Function to check if song can be added to playlist
int TsuPod::checkAddSong(Song mySong)
{
	//Error if blank title and artist for song
	if(mySong.getTitle() == "" || mySong.getArtist() == "")
	{
		cout << "Error: title and artist can not be blank." << endl;
		return -1;
	}
	
	//Error if invalid size and not enough memory
	if((mySong.getSize() < 1) || (mySong.getSize() > getRemainingMem()))
	{
		cout << "Error: size must be valid. ";
		cout << "There also needs to be enough memory available" << endl;
		return -1;
	}
}

//Function to add a song to playlist
int TsuPod::addSong(Song mySong)
{
	//Call function to check if song can be added
	if((checkAddSong(mySong)) < 0)
		return -1;

	//Pointer for new node and to traverse through list
	songNode * newNode, * nodePtr;

	//Initialize new node
	newNode = new songNode;
	newNode -> s = mySong;
	newNode -> next = NULL;

	//Increment consumed songs and memory
	csongs++;
	cmem = cmem + mySong.getSize();

	//If empty list, make head
	if(head == NULL)
		head = newNode;

	else
	{
		nodePtr = head;

		//Traverse to last node
		while(nodePtr -> next != NULL)
			nodePtr = nodePtr -> next;

		//Point node to a new node
		nodePtr -> next = newNode;
	}
	
	return 0;
}

//Function to remove a song from the playlist
int TsuPod::removeSong(Song mySong)
{
	//Variable for finding song to remove
	bool found = false;
	
	//Pointer for traversal and previous node
	//Initialize pointers
	songNode * previousNode = NULL;
	songNode * nodePtr = head;

	while(found != true)
	{
		//Check for empty list
		if(head == NULL)
		{
			cout << "Error: empty list." << endl;
			return -1;
		}

		//If head is the song
		else if(head -> s == mySong)
		{
			nodePtr = head -> next;
			delete head;
			head = nodePtr;
			found = true;
		}	
	
		else
		{
			nodePtr = head;
		
			//Traverse through playlist
			while(nodePtr != NULL && nodePtr -> s != mySong)
			{
				previousNode = nodePtr;
				nodePtr = nodePtr -> next;
			}
		
			if(nodePtr != NULL)
			{
				previousNode -> next = nodePtr -> next;
				delete nodePtr;
				found = true;
			}
		}
	
	}
	
	//Update consumed song count and memory
	if(found)
	{
		csongs--;
		cmem = cmem - mySong.getSize();
	}

	return 0;
}

//Show the contents of the song list
void TsuPod::showList()
{
	//Pointer to traverse through list
	songNode *nodePtr;

	//Initialize to start
	nodePtr = head;

	//Provide header
	cout << endl;
	cout << left << setw(25) << "Title" << left << setw(20) << "Artist";
	cout << left << setw(15) << "Size (MB)" << endl;

	//While there are still songs to print, show content and move to next song
	while(nodePtr != NULL)
	{
		cout << left << setw(25) << nodePtr -> s.getTitle();
		cout << left << setw(20) << nodePtr -> s.getArtist();
		cout << left << setw(15) << nodePtr -> s.getSize() << endl;

		nodePtr = nodePtr -> next;
	}
	cout << endl;

	cout << "csongs: " << csongs << endl;
}

//Function to find the lowest song in playlist
Song TsuPod::findLowest()
{
	//Pointer to traverse through list
	songNode * nodePtr = head;
	
	//Temperary song for sorting
	Song tempSong = nodePtr -> s;

	//Move positions in list
	//nodePtr = nodePtr -> next;
	
	//While still songs
	while(nodePtr != NULL)
	{
		//Find lowest alphabetic song
		if(nodePtr -> s < tempSong)
			tempSong = nodePtr -> s;

		//Traverse a node
		nodePtr = nodePtr -> next;
	}

	return tempSong;
}

//Function to sort the playlist
int TsuPod::sortList()
{
	//Pointers for traversal
	songNode * nodePtr;
	songNode * tptr;

	//Initialize pointer
	nodePtr = head;

	//Loop through playlist
	for(nodePtr = head; nodePtr -> next != NULL; nodePtr = nodePtr -> next)
	{
		//Traverse through list
		tptr = nodePtr -> next;

		//Check if songs need to be swapped
		if(nodePtr -> s > tptr -> s)
		{
			Song temp = nodePtr -> s;
			nodePtr -> s = tptr -> s;
			tptr -> s = temp;
		}
	}

	return 0;
}

//Function to return a random number
int TsuPod::randomNumber() 
{
	srand(time(0));
	return (rand() % csongs);
}

//Function to shuffle the playlist
int TsuPod::shuffle()
{

	//Variables for for loops
	int i;
	int index;

	//Variable to hold song for swapping
	Song temp;

	//Varibale to hold random number
	int num = -1;

	//Pointers to traverse and swap nodes
	songNode * tptr;
	songNode * mySwap;
	songNode * myPrevious;

	//Initialize pointer
	songNode * nodePtr = head;

	//Give error if list is empty
	if(head == NULL)
	{
		cout << "Error: empty list." << endl;
		return -2;
	}

	//Loop through number of consumed songs to shuffle them
	for(i = 0; i < csongs; i++)
	{		
		//Get random number
		num = randomNumber();

		//Pointer initialization
		tptr = head;
		myPrevious = nodePtr;

		for(index = 1; index <= num; index++)
		{	
			//Swap equals tptr pointer
			if(index == num)
				mySwap = tptr;

			//Traverse in playlist
			tptr = tptr->next;
		}
		
		//Swap the songs
		temp = myPrevious -> s;
		myPrevious -> s = mySwap -> s;
		mySwap -> s = temp;
		nodePtr = nodePtr -> next;
	}

}


//Functin to clear the playlist
int TsuPod::clearList()
{
	songNode * nodePtr;
	nodePtr = head;
	cmem = csongs = 0;

	while((nodePtr != NULL))
	{
		head -> next = nodePtr -> next;
		nodePtr -> next = NULL;
		delete nodePtr;
		nodePtr = head -> next;
	}

	head = NULL;
	
	return 0;

}

//Get the total memory of the tsuPod
int TsuPod::getTotalMem() {return totMem;}

//Get the remaining memory space left in the tsuPod
int TsuPod::getRemainingMem() {return (getTotalMem() - cmem);}
