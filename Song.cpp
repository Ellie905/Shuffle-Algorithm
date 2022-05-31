#include "Song.h"

std::string getInput(std::string);

// Constructors
Song::Song()
{
	decade = 0;
	length = 0;
	name = "";
	album = "";
	artist = "";
	fst_genre = "";
	sec_genre = "";
	thr_genre = "";
}

Song::Song(short newDecade, short newLength, std::string newName, std::string newAlbum, std::string newArtist, std::string newFst_genre)
{
	decade = newDecade;
	length = newLength;
	name = newName;
	album = newAlbum;
	artist = newArtist;
	fst_genre = newFst_genre;
	sec_genre = "";
	thr_genre = "";
}

Song::Song(short newDecade, short newLength, std::string newName, std::string newAlbum, std::string newArtist, std::string newFst_genre, std::string newSec_genre)
{
	decade = newDecade;
	length = newLength;
	name = newName;
	album = newAlbum;
	artist = newArtist;
	fst_genre = newFst_genre;
	sec_genre = newSec_genre;
	thr_genre = "";
}

Song::Song(short newDecade, short newLength, std::string newName, std::string newAlbum, std::string newArtist, std::string newFst_genre, std::string newSec_genre, std::string newThr_genre)
{
	decade = newDecade;
	length = newLength;
	name = newName;
	album = newAlbum;
	artist = newArtist;
	fst_genre = newFst_genre;
	sec_genre = newSec_genre;
	thr_genre = newThr_genre;
}

Song::Song(Song* newSong)
{
	decade = newSong->decade;
	length = newSong->length;
	name = newSong->name;
	album = newSong->album;
	artist = newSong->artist;
	fst_genre = newSong->fst_genre;
	sec_genre = newSong->sec_genre;
	thr_genre = newSong->thr_genre;
}

// Accessors
short Song::getDecade() const
{
	return decade;
}

short Song::getLength() const
{
	return length;
}

std::string Song::getName() const
{
	return name;
}

std::string Song::getAlbum() const
{
	return album;
}

std::string Song::getArtist() const
{
	return artist;
}

std::string Song::getFst_genre() const
{
	return fst_genre;
}

std::string Song::getSec_genre() const
{
	return sec_genre;
}

std::string Song::getThr_genre() const
{
	return thr_genre;
}


// Mutators
void Song::setDecade(short newDecade)
{
	decade = newDecade;
}

void Song::setLength(short newLength)
{
	length = newLength;
}

void Song::setName()
{
	name = getInput("Updated Track Name: ");
}

void Song::setName(std::string input)
{
	name = input;
}

void Song::setAlbum()
{
	album = getInput("Updated Album Name: ");
}

void Song::setAlbum(std::string input)
{
	album = input;
}

void Song::setArtist()
{
	artist = getInput("Updated Artist Name: ");
}

void Song::setArtist(std::string input)
{
	artist = input;
}

void Song::setFst_genre()
{
	fst_genre = getInput("Updated Primary Genre: ");
}

void Song::setFst_genre(std::string input)
{
	fst_genre = input;
}

void Song::setSec_genre()
{
	sec_genre = getInput("Updated Secondary Genre: ");
}

void Song::setSec_genre(std::string input)
{
	sec_genre = input;
}

void Song::setThr_genre()
{
	thr_genre = getInput("Updated Tertiary Genre: ");
}

void Song::setThr_genre(std::string input)
{
	thr_genre = input;
}


// Functions
std::string Song::writeToFile()
{
	std::string temp;

	// Add attributes to temporary string
	temp = ("dec," + std::to_string(decade) + ",len," + std::to_string(length) + ",nam," + name + ",alb," + album + ",art," + artist + ",fst," + fst_genre + ",");

	// Add optional attributes
	if (thr_genre != "")
	{
		temp += ("sec," + sec_genre + ",thr," + thr_genre + ",");
	}
	else if (sec_genre != "")
	{
		temp += ("sec," + sec_genre + ",");
	}

	// Return temporary string so program can write line by line
	return temp;
}

bool Song::isEmpty()
{
	if (decade != 0) { return false; }
	if (length != 0) { return false; }
	if (name != "") { return false; }
	if (album != "") { return false; }
	if (artist != "") { return false; }
	if (fst_genre != "") { return false; }

	return true;
}

// Overloads
std::ostream& operator<<(std::ostream& os, const Song* song)
{
	os << std::endl;
	os << "Decade: " << song->decade << std::endl;
	os << "Track Length: " << song->length << std::endl;
	os << "Track: " << song->name << std::endl;
	os << "Album: " << song->album << std::endl;
	os << "Artist: " << song->artist << std::endl;
	os << "Genre: " << song->fst_genre << std::endl;

	if (song->thr_genre != "")
		os << "Secondary Genre: " << song->sec_genre << std::endl << "Tertiary Genre: " << song->thr_genre << std::endl;
	else if (song->sec_genre != "")
		os << "Secondary Genre: " << song->sec_genre << std::endl;

	os << std::endl;

	return os;
}
