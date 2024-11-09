#include <iostream>
#include <cstring>
#include "./MovieMediaFile.h"
/*
this class is the object for a movie media file
author: jay williamson
date: 11/8/24
 */

using namespace std;
using namespace MediaFiles;

//constructor assigns variables
MovieMediaFile::MovieMediaFile(int year, int rate, int length, char* direct, char* name)
{
  MovieMediaFile::year = year;
  MovieMediaFile::duration = length;
  MovieMediaFile::rating = rate;
  
  strcpy(MovieMediaFile::director, direct);
  
  strcpy(MovieMediaFile::title, name);
}

//gets and returns duration
int MovieMediaFile::getDuration()
{
  return MovieMediaFile::duration;
}

//gets and returns ratings
int MovieMediaFile::getRating()
{
  return MovieMediaFile::rating;
}

//gets and returns director into a chr[] inputed
void MovieMediaFile::getDirector(char* outStr)
{
  strcpy(outStr, MovieMediaFile::director);
  return;
}

//prints info
void MovieMediaFile::printInfo()
{
  cout << "title: " << MovieMediaFile::title << "\n";
  cout << "year: " << MovieMediaFile::year << "\n";
  cout << "director: " << MovieMediaFile::director << "\n";
  cout << "duration: " << MovieMediaFile::duration << " minutes" << "\n";
  cout << "rating: " << MovieMediaFile::rating << "\n";
}

