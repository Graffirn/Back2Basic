#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include "Node.h"


class DoublyLinkedList
{
public:
    Node *head;
    Node * tail;
    int length;
    
    DoublyLinkedList();
    DoublyLinkedList(int value);
    ~DoublyLinkedList();

    int getLength();
    Node *getHead();
    Node *appendNode(int value);
    Node *insertNode(int index, int value);
    Node *deleteNode(int index);
    Node *updateNode(int index, int value);
    void printList();
};

#endif
