#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node *next;
    int value;

    Node(int value);
    Node(Node *nextNode);
    Node(int value, Node *nextNode);
};

#endif
