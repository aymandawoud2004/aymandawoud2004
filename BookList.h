#include <iostream>
#include "BookNode.h"

class BookList {
public:
    BookList() {
        head = tail = nullptr;
    }

    ~BookList() {
        while(!isEmpty()){
            deleteFromHead();
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void addToTail(int id2, string name2, string type2) {
        
        BookNode *newNode = new BookNode;
    
        if (isEmpty()) {
            head=newNode;
            head->id=id2;
            head->name=name2;
            head->type=type2;
            head->next=nullptr;
            tail=head;
        } else {
            
            tail->next = newNode;
            newNode->id=id2;
            newNode->name=name2;
            newNode->type=type2;
            newNode->next=nullptr;
            tail = newNode;
        }
    }

    BookNode deleteFromHead() {
        if ( isEmpty() ) {
             cout << "Error : pop empty list" << endl;  } 
        BookNode* oldhead = head;
        head = head->next;
        return *oldhead;
        delete oldhead; 
        
    }

    BookNode deleteNode(string name3) {
    
    if (isEmpty()) {
        
         cout << "Error : pop empty list" << endl;
        return BookNode();
    }

    
    if (head->name == name3) {
        return deleteFromHead();
    }

    
    BookNode *current = head;
    BookNode *previous = nullptr;

    while (current != nullptr && current->name != name3) {
        previous = current;
        current = current->next;
    }

    
    if (current == nullptr) {
        cout<<"the node with the given name is not found"<<endl;
        return BookNode();
        
    }

    
    previous->next = current->next;

    
    if (current == tail) {
        tail = previous;
    }

    
    return *current;
}

BookNode deleteIndexNode(int id3) {
    
    if (isEmpty()) {
        
        cout << "Error : pop empty list" << endl;
        return BookNode();
    }

    
    if (head->id == id3) {
        return deleteFromHead();
    }

    
    BookNode *current = head;
    BookNode *previous = nullptr;

    while (current != nullptr && current->id != id3) {
        previous = current;
        current = current->next;
    }

    
    if (current == nullptr) {
        cout<<"the node with the given name is not found"<<endl;
        return BookNode();
    }

    
    previous->next = current->next;

   
    if (current == tail) {
        tail = previous;
    }

    
    return *current;
}

bool isInList(string name) const {
    
    BookNode *current = head;

    while (current != nullptr) {
        if (current->name == name) {
            return true;
        }
        current = current->next;
    }

    return false; 
}

void printAll() const {
    
    BookNode *current = head;

    while (current != nullptr) {
        cout << "ID: " << current->id << ", Name: " << current->name << ", Type: " << current->type << endl;
        current = current->next;
    }
}

int listLength() const {
    
    int length = 0;
    BookNode *current = head;

    while (current != nullptr) {
        length++;
        current = current->next;
    }

    return length;
}
private:
BookNode *head, *tail;
};
