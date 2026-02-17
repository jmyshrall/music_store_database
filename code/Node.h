#ifndef NODE_H
#define NODE_H

#include "Album.h"

class Node
{

public:

    Node(Album* album);
    Album* getAlbum();
    void setAlbum(Album* album);
    Node* getNext();
    void setNext(Node* nextNode);

private:
    Album* data;
    Node* next;

};
#endif
