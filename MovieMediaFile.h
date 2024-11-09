#include "./MediaFileParent.h"
/*
this class is the .h for the movie
author: jay williamson
date: 11/8/24
 */

namespace MediaFiles
{
  //inherit from media file parent
  class MovieMediaFile : public MediaFiles::MediaFileParent
  {
    //functions
    public:
    MovieMediaFile(int year, int rate, int length, char* direct, char* name);
      int getDuration();
    int getRating();
    void printInfo() override;
      void getDirector(char* outStr);
    //variables
      int duration;
      char director[20];
    int rating;
  };
}


