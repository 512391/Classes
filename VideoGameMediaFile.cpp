#include <iostream>
#include <cstring>
#include "./VideoGameMediaFile.h"
/*
this class is the object for video game objects holding info
author: jay williamson
date: 11/8/24
 */


using namespace std;
using namespace MediaFiles;

//constructor assigns variables
VideoGameMediaFile::VideoGameMediaFile(int year, int rating, char* publish, char* name)
{
  VideoGameMediaFile::year = year;
  VideoGameMediaFile::rating = rating;

  strcpy(VideoGameMediaFile::publisher, publish);
  
  strcpy(VideoGameMediaFile::title, name);
}

//gets and returns rating
int VideoGameMediaFile::getRating()
{
  return VideoGameMediaFile::rating;
}

//gets and returns publisher to a char[] inputed
void VideoGameMediaFile::getPublisher(char* outStr)
{
  strcpy(outStr, VideoGameMediaFile::publisher);
  return;
}

//prints the info
void VideoGameMediaFile::printInfo()
{
  cout << "title: " << VideoGameMediaFile::title << "\n";
  cout << "year: " << VideoGameMediaFile::year << "\n";
  cout << "publisher: " << VideoGameMediaFile::publisher << "\n";
  cout << "rating: " << VideoGameMediaFile::rating << "\n";
}

