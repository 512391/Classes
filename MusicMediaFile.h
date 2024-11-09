#include "./MediaFileParent.h"
/*
this class is h file for the music media file
author: jay williamson
date: 11/8/24
 */

namespace MediaFiles
{
  //inherit from media file parent
  class MusicMediaFile : public MediaFiles::MediaFileParent
  {
    //functions
    public:
    MusicMediaFile(int year, int rating, char* publish, char* name, char* artists);
      int getRating();
    void printInfo() override;
      void getPublisher(char* outStr);
    void getArtist(char* artists);
    //variables
      int rating;
      char publisher[20];
    char artist[20];
  };
}


