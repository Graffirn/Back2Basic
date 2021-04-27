/*
 *  g++ .\test\testDoublyLinkedList.cpp .\src\*.cpp -o DoublyLinkedList.exe
 */

#include <iostream>
#include "../include/DoublyLinkedList.h"

using namespace std;

void printResult(DoublyLinkedList *list) {
    cout << "----" << endl;
    cout << "Length: " << list->getLength() << endl;
    int head = list->getHead() ? list->getHead()->value : NULL;
    int tail = list->getTail() ? list->getTail()->value : NULL;
    cout << "Head: " << head << endl;
    cout << "Tail: " << tail << endl;
    list->printForward();
    list->printBackward();
    cout << "----" << endl;
}

int main() {
    DoublyLinkedList *list = new DoublyLinkedList();
    printResult(list);

    list->pushTail(20);
    list->removeHead();
    printResult(list);

    list->pushTail(20);
    list->removeTail();
    printResult(list);

    list->pushTail(10);
    list->pushTail(2);
    list->pushTail(30);
    list->pushTail(40);
    list->pushHead(100);
    printResult(list);

    cout << "Test update\n"; 
    list->updateNode(5, 5);
    list->updateNode(2, 2);
    list->updateNode(4, 4);
    list->updateNode(0, 0);
    list->updateNode(-1, 0);
    list->updateNode(100, 0);
    list->updateNode(1, 1);
    list->updateNode(3, 3);
    printResult(list);

    cout << "Test insert\n"; 
    list->insertNode(2, 200);
    printResult(list);

    list->insertNode(0, 300);
    printResult(list);

    list->insertNode(list->length - 1, 300);
    printResult(list);

    cout << "Test insert\n"; 
    list->deleteNode(list->length - 1);
    printResult(list);

    list->deleteNode(0);
    printResult(list);

    list->deleteNode(2);
    printResult(list);

    return 0;
}
