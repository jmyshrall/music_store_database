#ifndef STORE_H
#define STORE_H

#include "Inventory.h"
#include <string>

class Store
{

public:
    Store();
    void run();

private:

    Inventory inventory;

    void displayMenu();
    void handleSearch();
    void handleSale();
    void handleReturn();
    void updateInventoryFromFile();

    string getInput(string query);

};
#endif
