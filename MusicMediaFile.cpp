#include <iostream>
#include <cstring>
#include "./MusicMediaFile.h"
/*
this class is the object for a music media file
author: jay williamson
date: 11/8/24
 */

using namespace std;
using namespace MediaFiles;

//constructor it just assigns variables basically
MusicMediaFile::MusicMediaFile(int year, int rating, char* publish, char* name, char* artists)
{
  MusicMediaFile::year = year;
  MusicMediaFile::rating = rating;

  strcpy(MusicMediaFile::publisher, publish);
  
  strcpy(MusicMediaFile::title, name);

  strcpy(MusicMediaFile::artist, artists);
}

//gets and rutns rating
int MusicMediaFile::getRating()
{
  return MusicMediaFile::rating;
}

//gets and returns publisher into a char[] inputed
void MusicMediaFile::getPublisher(char* outStr)
{
  strcpy(outStr, MusicMediaFile::publisher);
  return;
}

//gets and returns the artists into a char[] inputed
void MusicMediaFile::getArtist(char* outStr)
{
  strcpy(outStr, MusicMediaFile::artist);
  return;
}

//prints all the info about it
void MusicMediaFile::printInfo()
{
  cout << "title: " << MusicMediaFile::title << "\n";
  cout << "year: " << MusicMediaFile::year << "\n";
  cout << "publisher: " << MusicMediaFile::publisher << "\n";
  cout << "rating: " << MusicMediaFile::rating << "\n";
  cout << "artist: " << MusicMediaFile::artist << "\n";
}

