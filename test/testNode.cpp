/*
 *  g++ .\test\testNode.cpp .\src\*.cpp -o testNode.exe
 */

#include <iostream>
#include "../include/Node.h"

int main() {
    Node *head = new Node(0);
    Node *second = new Node(1);
    Node *third = new Node(2);
    head->next = second;
    second->next = third;
    Node *ptr = head;
    while (ptr != nullptr) {
        std::cout << ptr->value;
        if (ptr->next != nullptr)
            std::cout << "->";
        ptr = ptr->next;  
    }
    return 0;
}