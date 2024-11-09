#ifndef MEDIAFILEPARENT_H
#define MEDIAFILEPARENT_H

/*
this class is the parent to all media files sharing the comanalities
author: jay williamson
date: 11/8/24
 */

namespace MediaFiles
{
  class MediaFileParent
  {
    //variables
    protected:
      int year;
      char title[50];
    //functions
    public:
      virtual void printInfo();
      int getYear();
      void getTitle(char* out); 
  };
}
#endif
