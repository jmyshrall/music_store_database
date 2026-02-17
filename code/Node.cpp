#include "Node.h"

Node::Node(Album* album)
{
    data = album;
    next = nullptr;
}

Album* Node::getAlbum()
{
    return data;
}

void Node::setAlbum(Album* album)
{
    data = album;
}

Node* Node::getNext()
{
    return next;
}

void Node::setNext(Node* nextNode)
{
    next = nextNode;
}
