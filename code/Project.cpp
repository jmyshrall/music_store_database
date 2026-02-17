#include "Store.h"

int main()
{
    Store* store = new Store();
    store->run();
    delete store;
    return 0;
}
