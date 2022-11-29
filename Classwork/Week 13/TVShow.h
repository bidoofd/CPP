#ifndef TVSHOW_H
#define TVSHOW_H
#include <string>
using namespace std;

class TvShow {
 private:
 
  string actor1 ="Moe";
  static string actor2;
  static int numShows;
  string showName;
  int y=10;
  
 public: 
      TvShow(string nm);
      static int numberOfShows();
      void setActor1(string act1);
      static string showActor2();
      string showShowName();
};
#endif
