#include "TvShow.h"

TvShow::TvShow(string nm){
	numShows++;
    showName = nm; 
}

int TvShow::numberOfShows() {
    return numShows; 
}
      
void TvShow::setActor1(string act1) {
	actor1 = act1;
}

string TvShow::showActor2()
{
    return actor2;
}

string TvShow::showShowName()
{
    return showName;
}
