/*
 *  g++ .\test\testNode.cpp .\src\*.cpp -o testNode.exe
 */

#include <iostream>
#include "../include/Node.h"

int main() {
    Node *second = new Node(2);
    Node *first = new Node(1, second);
    Node *dump = new Node(first);
    Node *ptr = dump;
    while (ptr != nullptr) {
        std::cout << ptr->value;
        if (ptr->next != nullptr)
            std::cout << "->";
        ptr = ptr->next;  
    }
    return 0;
}