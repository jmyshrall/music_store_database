#include "Album.h"

using namespace std;

Album::Album(string albumId, string albumTitle, string albumBand, string releaseYear, int numMem, string albumMembers[], string albumState)
{
    id = albumId;
    title = albumTitle;
    band = albumBand;
    year = releaseYear;
    numMembers = numMem;

    members = new string[numMembers];
    for (int i = 0; i < numMembers; ++i)
    {
        members[i] = albumMembers[i];
    }

    state = albumState;
}

Album::~Album()
{
    delete[] members;
}

string Album::getId()
{
    return id;
}

string Album::getTitle()
{
    return title;
}

string Album::getBand()
{
    return band;
}

string Album::getYear()
{
    return year;
}

int Album::getNumMembers()
{
    return numMembers;
}

string* Album::getMembers()
{
    return members;
}

string Album::getState()
{
    return state;
}

void Album::setState(string newState)
{
    state = newState;
}

void Album::setSaleDate(string newSaleDate)
{
    saleDate = newSaleDate;
}

string Album::getSaleDate()
{
    return saleDate;
}


