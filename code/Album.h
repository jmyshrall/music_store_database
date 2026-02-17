#ifndef ALBUM_H
#define ALBUM_H

#include <string>
using namespace std;

class Album
{

public:

    Album(string albumId, string albumTitle, string albumBand, string releaseYear, int numMem, string albumMembers[], string albumState);
    ~Album();
    string getId();
    string getTitle();
    string getBand();
    string getYear();
    int getNumMembers();
    string* getMembers();
    string getState();
    string getSaleDate();

    void setState(string newState);
    void setSaleDate(string newSaleDate);

private:

    string id;
    string title;
    string band;
    string year;
    int numMembers;
    string* members;
    string state;

    string saleDate;
};
#endif

