#include "../include/Node.h"

Node::Node(int value) {
    this->value = value;
};

Node::Node(Node *nextNode) {
    this->next = nextNode;
    this->value = 0;
};

Node::Node(int value, Node *nextNode) {
    this->value = value;
    this->next = nextNode;
};