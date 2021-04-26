#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
#include "Node.h"


class SinglyLinkedList
{
public:
    Node *head;
    int length;
    
    SinglyLinkedList();
    SinglyLinkedList(int value);
    ~SinglyLinkedList();

    int getLength();
    Node *getHead();
    Node *appendNode(int value);
    Node *insertNode(int index, int value);
    Node *deleteNode(int index);
    Node *updateNode(int index, int value);
    void printList();
};

#endif
