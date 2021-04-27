#include "../include/DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}

DoublyLinkedList::DoublyLinkedList(int value) {
    this->head = new Node(value);
    this->tail = this->head;
    this->length = 1;
}

DoublyLinkedList::~DoublyLinkedList() {
    Node *ptr = this->head;
    Node *next;
    while (ptr != nullptr) {
        next = ptr->next;
        delete ptr;
        ptr = next;
    }
}

int DoublyLinkedList::getLength() {
    return this->length;
}

Node *DoublyLinkedList::getHead() {
    return this->head;
}

Node *DoublyLinkedList::getTail() {
    return this->tail;
}

Node *DoublyLinkedList::pushHead(int value) {
    Node *newNode = new Node(value);
    if (this->head != nullptr)
        this->head->prev = newNode;
    newNode->next = this->head;
    
    this->length += 1;
    this->head = newNode;
    if (this->length == 1) {
        this->tail = newNode;
    }
    return this->head;
}

Node *DoublyLinkedList::pushTail(int value) {
    Node *newNode = new Node(value);
    if (this->tail != nullptr)
        this->tail->next = newNode;
    newNode->prev = this->tail;
    
    this->length += 1;
    this->tail = newNode;
    if (this->length == 1) {
        this->head = newNode;
    }
    return this->tail;
}

Node *DoublyLinkedList::removeHead() {
    if (this->length == 0) {
        return nullptr;
    }
    Node *temp = this->head;
    this->head = this->head->next;
    delete temp;
    this->length -= 1;
    if (this->length == 0)
        this->tail = nullptr;
    return this->head;
}

Node *DoublyLinkedList::removeTail() {
    if (this->length == 0) {
        return nullptr;
    }
    Node *temp = this->tail;
    this->tail = this->tail->prev;
    delete temp;
    temp = nullptr;
    this->length -= 1;
    if (this->length == 0)
        this->head = nullptr;
    return this->tail;
}

Node *DoublyLinkedList::insertNode(int index, int value) {
    if (index >= this->length || index < 0) {
        return nullptr;
    } else if (index == this->length - 1) {
        return this->pushHead(value);
    } else if (index == 0) {
        return this->pushTail(value);
    }
    Node *newNode = new Node(value);
    Node *dump = new Node();
    Node *ptr = dump;
    if (index <= this->length / 2) {
        ptr->next = this->head;
        while (index--) {
            ptr = ptr->next;
        }

        newNode->next = ptr->next;
        newNode->next->prev = newNode;
        ptr->next = newNode;
        newNode->prev = ptr;
        this->head = dump->next;
    } else {
        index = this->length - 1 - index;
        ptr->prev = this->tail;
        while (index--) {
            ptr = ptr->prev;
        }

        newNode->prev = ptr->prev;
        newNode->prev->next = newNode;
        ptr->prev = newNode;
        newNode->next = ptr;
        this->tail = dump->prev;
    }
    this->length += 1;
    delete dump;
    return newNode;
}

Node *DoublyLinkedList::deleteNode(int index) {
    if (index >= this->length || index < 0) {
        return this->head;
    } else if (index == 0) {
        return this->removeHead();
    } else if (index == this->length - 1) {
        return this->removeTail();
    }
    Node *dump = new Node();
    Node *ptr = dump;
    if (index <= this->length / 2) {
        ptr->next = this->head;
        while (index--) {
            ptr = ptr->next;
        }
        Node *temp = ptr->next->next;
        temp->prev = ptr;
        delete ptr->next;
        temp->prev->next = temp;
        this->head = dump->next;
    } else {
        index = this->length - 1 - index;
        ptr->prev = this->tail;
        while (index--) {
            ptr = ptr->prev;
        }
        Node *temp = ptr->prev->prev;
        temp->next = ptr;
        delete ptr->prev;
        temp->next->prev = temp;
        this->tail = dump->prev;
    }
    this->length -= 1;
    delete dump;
    return this->head;
}

Node *DoublyLinkedList::updateNode(int index, int value) {
    if (index >= this->length || index < 0) {
        return this->head;
    }
    Node *ptr;
    if (index <= this->length / 2) {
        ptr = this->head;
        while (index--) {
            ptr = ptr->next;
        }
    } else {
        index = this->length - 1 - index;
        ptr = this->tail;
        while (index--) {
            ptr = ptr->prev;
        }
    }
    ptr->value = value;
    return ptr;
}

void DoublyLinkedList::printForward() {
    Node *ptr = this->head;
    int cnt = this->length;
    while (cnt--) {
        std::cout << ptr->value;
        if (cnt != 0) {
            std::cout << "->";
        }
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::printBackward() {
    Node *ptr = this->tail;
    int cnt = this->length;
    while (cnt--) {
        std::cout << ptr->value;
        if (cnt != 0) {
            std::cout << "->";
        }
        ptr = ptr->prev;
    }
    std::cout << std::endl;
}