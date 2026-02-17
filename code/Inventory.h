#ifndef INVENTORY_H
#define INVENTORY_H

#include "Node.h"
#include "Album.h"
#include <string>

class Inventory
{

public:

    Inventory();

    void searchTitle(string title);
    void searchBand(string band);
    void searchYear(string year);
    void searchMember(string member);

    void displayAlbums();

    bool sellAlbum(string albumId, string sellDate, string state);
    bool returnAlbum(string albumId, string state, string returnDate);

    bool updateInventory(string filename);
    void addAlbum(string albumId, string title, string band, string year, int numMembers, string members[], string state, string saleDate);

private:

    Node* head;

};
#endif
