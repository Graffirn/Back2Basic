#include "../include/SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList(int value) {
    this->head = new Node(value);
    this->length = 1;
}

SinglyLinkedList::~SinglyLinkedList() {
    Node *ptr = this->head;
    Node *next;
    while (ptr != nullptr) {
        next = ptr->next;
        delete ptr;
        ptr = next;
    }
}

int SinglyLinkedList::getLength() {
    return this->length;
}

Node *SinglyLinkedList::getHead() {
    return this->head;
}

Node *SinglyLinkedList::appendNode(int value) {
    Node *ptr = this->head;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    ptr->next = new Node(value);
    this->length += 1;
    return ptr->next;
}

Node *SinglyLinkedList::insertNode(int index, int value) {
    if (index >= this->length || index < 0) {
        return nullptr;
    }
    Node *dump = new Node();
    Node *ptr = dump;
    ptr->next = head;
    while (index--) {
        ptr = ptr->next;
    }

    Node *newNode = new Node(value);
    newNode->next = ptr->next;
    ptr->next = newNode;
    
    this->length += 1;
    this->head = dump->next;
    delete dump;
    return newNode;
}

Node *SinglyLinkedList::deleteNode(int index) {
    if (index >= this->length || index < 0) {
        return this->head;
    }
    Node *dump = new Node();
    Node *ptr = dump;
    ptr->next = head;
    while (index--) {
        ptr = ptr->next;
    }
    
    Node *temp = ptr->next->next;
    delete ptr->next;
    ptr->next = temp;

    this->length -= 1;
    delete dump;
    return this->head;
}

Node *SinglyLinkedList::updateNode(int index, int value) {
    if (index >= this->length || index < 0) {
        return this->head;
    }
    Node *ptr = this->head;
    while (index--) {
        ptr = ptr->next;
    }
    ptr->value = value;
    return ptr;
}

void SinglyLinkedList::printList() {
    Node *ptr = head;
    int cnt = this->length;
    while (cnt--) {
        std::cout << ptr->value;
        if (ptr->next != nullptr) {
            std::cout << "->";
        }
        ptr = ptr->next;
    }
    std::cout << std::endl;
}