#include <iostream>
#include <cstring>
#include "./MediaFileParent.h"

/*
this class is the parent to all media files sharing the comanalities
author: jay williamson
date: 11/8/24
 */
using namespace std;
using namespace MediaFiles;

//gets the year and returns it
  int MediaFileParent::getYear()
   {
     return MediaFileParent::year;
   }

//gets the title and returns it
void MediaFileParent::getTitle(char* out)
{
  strcpy(out, MediaFileParent::title);
}

//this is just so you can inherit it
void MediaFileParent::printInfo()
{
  cout << "base";
}
