#include "Inventory.h"
#include <iostream>
#include <fstream>

using namespace std;

Inventory::Inventory() : head(nullptr) {}

// reads album data from file and updates the inventory internally
bool Inventory::updateInventory(string filename)
{
    ifstream file(filename);
    int albumCount;
    string albumId;
    file >> albumCount;
    file >> albumId;

    for (int i = 0; i < albumCount; ++i)
    {
        string albumId;
        string title;
        string band;
        string year;
        int numMembers;
        string state;
        string saleDate = "";

        file >> albumId >> title >> band >> year >> numMembers;
        string* members = new string[numMembers];
        for (int j = 0; j < numMembers; ++j)
        {
            file >> members[j];
        }
        file >> state;
        if (file.peek() != '\n' && !file.eof())
        {
            file >> saleDate;
        }
        addAlbum(albumId, title, band, year, numMembers, members, state, saleDate);
        delete[] members;
    }
    file.close();
    return true;
}

// adds a new album to the inventory with all the data
void Inventory::addAlbum(string albumId, string title, string band, string year, int numMembers, string members[], string state, string saleDate)
{
    Album* album = new Album(albumId, title, band, year, numMembers, members, state);
    Node* newNode = new Node(album);
    newNode->setNext(head);
    head = newNode;
}

// searches albums based on a title query
void Inventory::searchTitle(string title)
{
    Node* current = head;
    bool found = false;
    int count = 0;

    while (current != nullptr)
    {
        Album* album = current->getAlbum();
        if (album->getTitle() == title)
        {
            if (!found)
            {
                cout << "Album(s) Found:\n";
                found = true;
            }
            cout << ++count << ". " << album->getId() << " " << album->getTitle() << " " << album->getBand() << " " << album->getYear() << " ";

            string* members = album->getMembers();
            int numMembers = album->getNumMembers();
            for (int i = 0; i < numMembers; ++i)
            {
                cout << members[i] << " ";
            }

            cout << album->getState() << "\n";
        }
        current = current->getNext();
    }
    if (!found)
    {
        cout << "***No Album Found***";
    }
}

// searches albums based on a band query
void Inventory::searchBand(string band)
{
    Node* current = head;
    bool found = false;
    int count = 0;

    while (current != nullptr)
    {
        Album* album = current->getAlbum();
        if (album->getBand() == band)
        {
            if (!found)
            {
                cout << "Album(s) Found:\n";
                found = true;
            }
            cout << ++count << ". " << album->getId() << " " << album->getTitle() << " " << album->getBand() << " " << album->getYear() << " ";

            string* members = album->getMembers();
            int numMembers = album->getNumMembers();
            for (int i = 0; i < numMembers; ++i)
            {
                cout << members[i] << " ";
            }

            cout << album->getState() << "\n";
        }
        current = current->getNext();
    }
    if (!found)
    {
        cout << "***No album found***";
    }
}

// searches albums based on a year query
void Inventory::searchYear(string year)
{
    Node* current = head;
    bool found = false;
    int count = 0;

    while (current != nullptr)
    {
        Album* album = current->getAlbum();
        if (album->getYear() == year)
        {
            if (!found)
            {
                cout << "Album(s) Found:\n";
                found = true;
            }
            cout << ++count << ". " << album->getId() << " " << album->getTitle() << " " << album->getBand() << " " << album->getYear() << " ";

            string* members = album->getMembers();
            int numMembers = album->getNumMembers();
            for (int i = 0; i < numMembers; ++i)
            {
                cout << members[i] << " ";
            }

            cout << album->getState() << "\n";
        }
        current = current->getNext();
    }
    if (!found)
    {
        cout << "***No Album Found***";
    }
}

// searches albums based on a member query
void Inventory::searchMember(string member)
{
    Node* current = head;
    bool found = false;
    int count = 0;

    while (current != nullptr)
    {
        Album* album = current->getAlbum();
        string* members = album->getMembers();
        int numMembers = album->getNumMembers();

        for (int i = 0; i < numMembers; ++i)
        {
            if (members[i] == member)
            {
                if (!found)
                {
                    cout << "Album(s) Found:\n";
                    found = true;
                }
                cout << ++count << ". " << album->getId() << " " << album->getTitle() << " " << album->getBand() << " " << album->getYear() << " ";

                for (int i = 0; i < numMembers; ++i)
                {
                    cout << members[i] << " ";
                }

                cout << album->getState() << "\n";
            }
        }
        current = current->getNext();
    }
    if (!found)
    {
        cout << "***No Album Found***";
    }
}

// helper function used to see if file is read properly
// outputs all important album information
void Inventory::displayAlbums()
{
    Node* current = head;

    if (current == nullptr)
    {
        cout << "***Inventory Is Empty***" << endl;
        return;
    }

    while (current != nullptr)
    {
        Album* album = current->getAlbum();

        cout << "Album Id: " << album->getId() << "\n";
        cout << "Album Title: " << album->getTitle() << "\n";
        cout << "Album Band: " << album->getBand() << "\n";
        cout << "Album Year: " << album->getYear() << "\n";
        cout << "Album Number of Members: " << album->getNumMembers() << "\n";

        string* members = album->getMembers();
        int numMembers = album->getNumMembers();

        cout << "Band members: ";
        for (int i = 0; i < numMembers; ++i)
        {
            cout << members[i] << " ";
        }
        cout << "\n";

        cout << "Album State: " << album->getState() << "\n";
        cout << "______________________________" << endl;

        current = current->getNext();
    }
}

// marks album as sold by updating its state and sale date
bool Inventory::sellAlbum(string albumId, string saleDate, string state)
{
    Node* current = head;
    while (current != nullptr)
    {
        Album* album = current->getAlbum();
        if (album->getId() == albumId)
        {
            album->setState(state);
            album->setSaleDate(saleDate);

            cout << "Sold Album: \n";
            cout << albumId << "\n";
            cout << album->getTitle() << "\n";
            cout << album->getBand() << "\n";
            cout << album->getYear() << "\n";
            cout << saleDate << "\n";
            cout << "\n";
            return true;
        }
        current = current->getNext();
    }
    cout << "***No Album Found With ID " << albumId << "***" << endl;
    return false;
}

// marks album as returned by updating its state and clearing the sale date
bool Inventory::returnAlbum(string albumId, string state, string returnDate)
{
    Node* current = head;
    while (current != nullptr)
    {
        Album* album = current->getAlbum();
        if (album->getId() == albumId)
        {
            album->setState(state);
            album->setSaleDate("");
            cout << "Album With ID " << albumId << " Has Been Returned On: " << returnDate << "\n";
            cout << "\n";
            return true;
        }
        current = current->getNext();
    }
    cout << "***No Album Found With ID " << albumId << "***" << endl;
    return false;
}

