#include "../include/SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList() {
    this->length = 0;
}

SinglyLinkedList::SinglyLinkedList(Node *head) {
    this->head = head;
    this->length = 1;
}

SinglyLinkedList::SinglyLinkedList(int value) {
    this->head = new Node(value);
    this->length = 1;
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
    Node *ptr = new Node(this->head);
    while (index--) {
        ptr = ptr->next;
    }
    Node *newNode = new Node(value, ptr->next);
    ptr->next = newNode;
    this->length += 1;
    return newNode;
}

Node *SinglyLinkedList::deleteNode(int index) {
    if (index >= this->length || index < 0) {
        return this->head;
    }
    Node *ptr = new Node(this->head);
    while (index--) {
        ptr = ptr->next;
    }
    ptr->next = ptr->next->next;
    this->length -= 1;
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
    while (ptr != nullptr) {
        std::cout << ptr->value;
        if (ptr->next != nullptr) {
            std::cout << "->";
        }
        ptr = ptr->next;
    }
    std::cout << std::endl;
}