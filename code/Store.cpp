#include "Store.h"
#include <iostream>

using namespace std;

Store::Store() {}

// main function for running program will determine what function to call
// based on query from user
void Store::run()
{
    int choice;
    do
    {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                updateInventoryFromFile();
                break;
            case 2:
                handleSearch();
                break;
            case 3:
                handleSale();
                break;
            case 4:
                handleReturn();
                break;
            case 5:
                inventory.displayAlbums();
                break;
            case 6:
                cout << "Exiting, Thank You For Using This Program\n";
                break;
            default:
                cout << "***Invalid Choice Try Again***\n";
        }
    } while (choice != 6);
}

// simple function for displaying menu options on start
void Store::displayMenu()
{
    cout << "\n--- Store Menu ---\n";
    cout << "\n";
    cout << "1. Update Inventory from File\n";
    cout << "2. Search Inventory\n";
    cout << "3. Sell an Album\n";
    cout << "4. Return an Album\n";
    cout << "5. Display Entire Inventory\n";
    cout << "6. Exit\n";
    cout << "\n";
    cout << "Enter Your Choice: ";
}

// determines type of search (name, year, etc) then calls inventory class function
void Store::handleSearch()
{
    int searchOption;

    cout << "\nSearch by:\n";
    cout << "\n";
    cout << "1. Title\n";
    cout << "2. Band\n";
    cout << "3. Year\n";
    cout << "4. Members\n";
    cout << "\n";
    cout << "Enter Your Choice: ";

    cin >> searchOption;
    cin.ignore();

    string query;
    switch (searchOption)
    {
        case 1:
            query = getInput("Enter Album Title: ");
            cout << "\n";
            inventory.searchTitle(query);
            break;
        case 2:
            query = getInput("Enter Band Name: ");
            cout << "\n";
            inventory.searchBand(query);
            break;
        case 3:
            query = getInput("Enter Album Year: ");
            cout << "\n";
            inventory.searchYear(query);
            break;
        case 4:
            query = getInput("Enter Album Member: ");
            cout << "\n";
            inventory.searchMember(query);
            break;
        default:
            cout << "***Invalid Choice Try Again***\n";
            break;
    }
}

// handles the sale of items
void Store::handleSale()
{
    string albumId = getInput("Enter album Id to sell: ");
    string saleDate = getInput("Enter sale date (MM-DD-YY): ");
    cout << "\n";
    if (inventory.sellAlbum(albumId, saleDate, "sold"))
    {
        cout << "Album Sold\n";
    }
    else
    {
        cout << "***Album Not Found***\n";
    }
}

// handles return of items
void Store::handleReturn()
{
    string albumId = getInput("Enter album ID to return: ");
    string returnDate = getInput("Enter Return Date (MM-DD-YY): ");
    cout << "\n";
    if (inventory.returnAlbum(albumId, "return", returnDate))
    {
        cout << "Album Returned\n";
    }
    else
    {
        cout << "***Album Not Found***\n";
    }
}

void Store::updateInventoryFromFile()
{
    string filename = getInput("Enter filename to load inventory: ");
    if (inventory.updateInventory(filename))
    {
        cout << "Inventory Updated From " << filename << "\n";
    }
    else
    {
        cout << "***Error Updating Inventory***\n";
    }
}

string Store::getInput(string query)
{
    cout << query;
    string input;
    getline(cin, input);
    return input;
}

