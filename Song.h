#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>

std::string getInput(std::string);

class Song
{
private:
	// Song Attributes
	short decade;
	short length;
	std::string name;
	std::string album;
	std::string artist;
	std::string fst_genre;
	std::string sec_genre;	// Optional
	std::string thr_genre;	// Optional

public:
	// Constructors
	Song();
	Song(short, short, std::string, std::string, std::string, std::string);
	Song(short, short, std::string, std::string, std::string, std::string, std::string);
	Song(short, short, std::string, std::string, std::string, std::string, std::string, std::string);
	Song(Song*);

	// Accessors
	short getDecade() const;
	short getLength() const;
	std::string getName() const;
	std::string getAlbum() const;
	std::string getArtist() const;
	std::string getFst_genre() const;
	std::string getSec_genre() const;
	std::string getThr_genre() const;

	// Mutators
	void setDecade(short);
	void setLength(short);
	void setName();
	void setName(std::string);
	void setAlbum();
	void setAlbum(std::string);
	void setArtist();
	void setArtist(std::string);
	void setFst_genre();
	void setFst_genre(std::string);
	void setSec_genre();
	void setSec_genre(std::string);
	void setThr_genre();
	void setThr_genre(std::string);

	// Functions
	std::string writeToFile();
	bool isEmpty();

	// Overloads
	friend std::ostream& operator<<(std::ostream& os, const Song* song);
};

#endif