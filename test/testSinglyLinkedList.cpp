/*
 *  g++ .\test\testSinglyLinkedList.cpp .\src\*.cpp -o SinglyLinkedList.exe
 */

#include <iostream>
#include "../include/SinglyLinkedList.h"

using namespace std;

void printSep() {
    cout << "----" << endl;
}

int main() {
    SinglyLinkedList *list = new SinglyLinkedList(0);
    cout << list->getLength() << endl;
    list->printList();
    printSep();

    list->appendNode(1);
    cout << list->getLength() << endl;
    list->printList();
    printSep();
    
    list->insertNode(1, 1);
    cout << list->getLength() << endl;
    list->printList();
    printSep();
    
    list->insertNode(0, 5);
    cout << list->getLength() << endl;
    list->printList();
    printSep();
    
    list->updateNode(2, 2);
    cout << list->getLength() << endl;
    list->printList();
    printSep();
    
    list->deleteNode(1);
    cout << list->getLength() << endl;
    list->printList();
    printSep();

    return 0;
}
