#include "../include/Node.h"

Node::Node() {
    this->next = nullptr;
};

Node::Node(int value) {
    this->value = value;
    this->next = nullptr;
};