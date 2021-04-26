#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node *next;
    int value;

    Node();
    Node(int value);
};

#endif
