#include <iostream>
#include <vector>
#include "./MediaFileParent.h"
#include "./VideoGameMediaFile.h"
#include "./MusicMediaFile.h"
#include "./MovieMediaFile.h"
#include "cstring"
/*
  This is the main class that handles input adding deleting and searching the files
  author: jay wiliamson
  date: 11/8/2024
 */

using namespace std;
using namespace MediaFiles;

//add media
void AddMedia(vector<MediaFileParent*>& files)
{
  //gets input
  cout<<"What Type Of Media Would You Like To Make type the letter corresponding to it (Movie(M), Music(S), VideoGame(V)) \n";
  char input;
  cin >> input;

  //gets info for movie
    if(input == 'M')
      {
	int year;
	char director[20];
	char title[50];
	int rating;
	int length;

	cout << "what year \n";
	cin >> year;
	cin.ignore();
	cout << "Who directed it (20 chars max) \n";
	cin.getline(director, 20, '\n');
	cout << "whats the title (50 chars max) \n";
	cin.getline(title, 50, '\n');
	cout << "whats the rating \n";
	cin >> rating;
	cin.ignore();
	cout << "whats the length \n";
	cin >> length;
	cin.ignore();

	//makes movie files
	MovieMediaFile* movie = new MovieMediaFile(year, rating, length, director, title);
	files.push_back(movie);
      }//gets infor for music
    else if(input == 'S')
      {
	int year;
        char artist[20];
        char title[50];
        int rating;
        char publisher[20];

        cout << "what year \n";
        cin >> year;
	cin.ignore();
        cout << "Whos the artist (20 chars max) \n";
        cin.getline(artist, 20, '\n');
        cout << "whats the title (50 chars max) \n";
        cin.getline(title, 50, '\n');
        cout << "whats the rating \n";
        cin >> rating;
	cin.ignore();
        cout << "whats the publisher \n";
        cin.getline(publisher, 20, '\n');

	//makes music file
        MusicMediaFile* music = new MusicMediaFile(year, rating, publisher, title, artist);
        files.push_back(music);
      }//gets info for video game
    else if(input == 'V')
      {
	int year;
        char publisher[20];
        char title[50];
        int rating;

        cout << "what year \n";
        cin >> year;
	cin.ignore();
        cout << "Whos the publisher (20 chars max) \n";
        cin.getline(publisher, 20, '\n');
        cout << "whats the title (50 chars max) \n";
        cin.getline(title, 50, '\n');
        cout << "whats the rating \n";
        cin >> rating;
	cin.ignore();

	//make video game file
        VideoGameMediaFile* vg = new VideoGameMediaFile(year, rating, publisher, title);
        files.push_back(vg);
      }
}

//deletes something based on what u ask it to
void DeleteMedia(vector<MediaFileParent*>& files)
{
  int choice;
  int year;
  char title[50];

  //gets input for what to delete for
  cout << "Would you like to delete based on Title(1) or Year(2) type either 1 or 2 to choose";
  cin >> choice;
  cin.ignore();

  int i = 0;
  
  if(choice == 1)
    {
      //asks for what to delete
      cout << "what title would u like to delete";
      cin.getline(title, 50, '\n');

      //searches through all files
      for (std::vector<MediaFileParent*>::iterator it = files.begin(); it != files.end(); ++it)
	{
	  char titleCompare[50];
	  //gets the title
	  (*it)->getTitle(titleCompare);
	  //compares title
	  if(strcmp(titleCompare, title) == 0)
	    {

	      //gets the files
	      MediaFileParent* obj = (*it);

	   //asks whether u do actually want to delete it
          cout << "Are you sure you want to delete(Y/N): \n";
          obj->printInfo();

          char input;

          cin >> input;
          cin.ignore();

	  //if you do want to delete it it gets deleted
          if(input == 'Y')
            {
	      delete obj;
               auto pos = files.begin() + i;
               files.erase(pos);

               
            }
        }
      i++;
	}
    }
  else // does the same as above just with year instead of title
    {
      cout << "what year would u like to delete";
      cin >> year;
      cin.ignore();

      for (std::vector<MediaFileParent*>::iterator it = files.begin(); it != files.end(); ++it)
        {
	  if((*it)->getYear() == year)
	    {
	      MediaFileParent* obj = (*it);

             cout << "Are you sure you want to delete(Y/N): \n";
             (*it)->printInfo();

             char input;

             cin >> input;
             cin.ignore();

             if(input == 'Y')
              {
		delete obj;
               auto pos = files.begin() + i;
               files.erase(pos);

               
              }
	    }
	  i++;
	}
     

    }
}

//searched for media and prints it
void SearchMedia(vector<MediaFileParent*>& files)
{
  //gets your input
  int choice;
  int year;
  char title[50];
  cout << "Would you like to search based on Title(1) or Year(2) type either 1 or 2 to choose";
  cin >> choice;
  cin.ignore();

  if(choice == 1)
    {
      //asks for what to search for
      cout << "what title would u like to search";
      cin.getline(title, 50, '\n');
    }
  else
    {
      //asks for what to search for
      cout << "what year would u like to search";
      cin >> year;
      cin.ignore();
    }

  //looks through all fo them
          for (std::vector<MediaFileParent*>::iterator it = files.begin() ; it != files.end(); ++it)
            {
	      //depending on what your looking for it checks
              if(choice == 1)
                {
                 char currentTitle[50];
                 (*it)->getTitle(currentTitle);
		 //compares and prints if true
                 if(strcmp(currentTitle, title)==0)
                   {
		     (*it)->printInfo();
                   }
                }
              else
                {
		  //compares and prints if true
                  if((*it)->getYear() == year)
                    {
		      (*it)->printInfo();
                    }
                }
            }

}

//main function
int main()
{
  //th overall files
  vector<MediaFileParent*> files;

  char input;

  //gets first input
  cout << "Use the single capital letters to input ADD(A), SEARCH(S), DELETE(D), QUIT(Q)";
      cin >> input;
      cin.ignore();

      
      //crossrefrences input
  while(input != 'Q')
    {//A adds
      if(input == 'A')
	AddMedia(files);
      if(input == 'S')//S searches
	SearchMedia(files);
      if(input == 'D')//D deletes
	DeleteMedia(files);

      //gets next input
      cout << "Use the single capital letters to input ADD(A), SEARCH(S), DELETE(D), QUIT(Q)";
      cin >> input;
      cin.ignore();      
    }
  
  //this deletes all the rest of the remaining elements
   for (std::vector<MediaFileParent*>::iterator it = files.begin() ; it != files.end(); ++it)
            {
	      MediaFileParent* obj = (*it);
	      delete obj;
	      auto pos = files.begin();
	      files.erase(pos);
	    }

   cout << "deleted all";

  return 0;
}
