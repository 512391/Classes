#include "./MediaFileParent.h"
/*
this class is the .h for videogame files
author: jay williamson
date: 11/8/24
 */

namespace MediaFiles
{
  //inherits from parent
  class VideoGameMediaFile : public MediaFiles::MediaFileParent
  {
    //functions
  public:
      VideoGameMediaFile(int year, int rating, char* publish, char* name);
      int getRating();
    void printInfo() override;
      void getPublisher(char* outStr);
    //variables
      int rating;
      char publisher[20];
    
  };
}


