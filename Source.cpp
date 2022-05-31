/*
	Programmer: Ellie Day
	Date: October 25, 2021
	Purpose:
		Adaptive Shuffle

		Spotify uses a shuffle algorithm that over time adjusts to play your liked songs more frequently

		I want to make a similar algorithm but more responsive. After 30 seconds played, or if the song is skipped
		in 30 seconds or less, the algorithm takes note of that and reshuffles the songs based on that song's
		attributes, such as genre. It uses a weighted system to seed the new shuffles, and doesn't repeat until the
		shuffle is complete

	Needed:
		File I/O - Read CSV of "songs" and attributes into List/Array/Whatever of "song" objects
		Shuffle Function - At user's command, reshuffles list of "song" objects (minus "played" songs) using weighted
						   RNG shuffling system
		Timer - Keeps track of how long between commands. Used in various places, such as changing song weight after
			    'skip' command is issued or auto-play next song in the shuffle in the absence of 'skip' command

	Notes: 
		Example Saving Song List:

			Song temp = new Song(1990, 301, "Smells Like Teen Spirit", "Nevermind", "Nirvana", "Grunge", "Hard Rock");
			std::list<Song> songs;

			songs.push_back(temp);

			save(songs);
	
		Example Loading Song List + Iterating/Displaying Library:

			load(songs);

			for (auto const& i : songs)
			{
				Song* song = new Song(i);
				std::cout << song;
			}
*/

#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Song.h"

/*
	To Do:
	DONE - Create Song Object
	DONE - File I/O
	Create function to count seconds passed, on a new CPU thread. Or find a function that does this
	
*/

// File Input/Output Functions
void save(std::list<Song> songs)
{
	// Local Variables
	std::ofstream myFile("Shuffle.csv");

	// Loop Through List of Songs
	std::list<Song>::iterator it;
	for (it = songs.begin(); it != songs.end(); it++)
	{
		std::string temp = it->writeToFile();
		myFile << temp;
	}

	// Close The File
	myFile.close();
}

// Passes List by Reference to avoid Global Variables
void load(std::list<Song>& songs)
{
	// Local Variables
	std::fstream myFile;

	try
	{
		myFile.open("Shuffle.csv", std::ios::in);
	}
	catch (const std::exception&)
	{
		std::ofstream newFile("Shuffle.csv");
		newFile.close();
	}

	if (myFile.is_open())
	{
		// Local Variables
		bool firstIter = true;
		int counter = 0;
		std::string temp;
		std::string prevStr;
		Song* newSong = new Song(); // Used to build Song objects from myFile

		while (std::getline(myFile, temp, ','))
		{
			counter++;

			// First Iteration
			if (firstIter)
			{
				prevStr = "dec";
				firstIter = false;
				counter--;
				continue;
			}
			else if (counter % 2 == 0) // Every other Iteration, Skip
			{
				prevStr = temp;
				continue;
			}

			if (prevStr == "dec")
			{
				// If the Song Object Isn't Empty
				if (!newSong->isEmpty())
				{
					// Add Song to List Before Getting Next Song
					songs.emplace_front(newSong);

					delete newSong; // Delete Old Data
					newSong = new Song(); // Declare New Memory for New Data
				}

				newSong->setDecade(std::stoi(temp));
				continue;
			}
			else if (prevStr == "len")
			{
				newSong->setLength(std::stoi(temp));
				continue;
			}
			else if (prevStr == "nam")
			{
				newSong->setName(temp);
				continue;
			}
			else if (prevStr == "alb")
			{
				newSong->setAlbum(temp);
				continue;
			}
			else if (prevStr == "art")
			{
				newSong->setArtist(temp);
				continue;
			}
			else if (prevStr == "fst")
			{
				newSong->setFst_genre(temp);
				continue;
			}
			else if (prevStr == "sec")
			{
				newSong->setSec_genre(temp);
				continue;
			}
			else if (prevStr == "thr")
			{
				newSong->setThr_genre(temp);
				continue;
			}
		}

		songs.emplace_front(newSong); // Add Final Song to List
		delete newSong; // Delete Old Data

		myFile.close();
	}
}

std::string getInput(std::string prompt)
{
	// Temporary String Variable
	std::string input = "";

	// Prompt User For Input
	std::cout << prompt << std::endl;

	std::cin.ignore();

	// Get Input
	std::getline(std::cin, input);

	// Return Input
	return input;
}

// Main Function
int main()
{
	// Variables
	std::list<Song> songs;
	std::string userInput;
	std::vector<std::string> songNames;

	// Load Song Library if File Exists
	load(songs);

	for (auto i : songs)
		songNames.push_back(i.getName());

	// Main Loop
	while (true)
	{
		std::cout << "Shuffle Algorithm Project" << std::endl << std::endl;

		std::cout << "Now Playing: " << songNames[0] << std::endl;


	}
}