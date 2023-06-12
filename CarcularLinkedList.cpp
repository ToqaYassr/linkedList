#include <iostream>

using namespace std;

//Implementation of a Circular Linked List with the following methods:
//o insertAtHead (elementType element) : void
//o insertAtEnd (elementType element) : void
//o insertAt (elementType element, int index) : void
//o removeAtHead () : void
//o removeAtEnd () : void
//o removeAt (int index) : void
//o retrieveAt (int index): elementType
//o replaceAt (elementType newElement, int index)
//o isExist (elementType element) : bool
//o isItemAtEqual (elementType element, int index) : bool
//o swap (int firstItemIdx, int secondItemIdx) : void // swap two nodes without
//swapping data.
//o isEmpty () : bool
//o circularLinkedListSize () : int
//o clear (): void
//o print () : void

template<class T>
class CircularLinkedList {
private:
    struct node {
        T item;
        node *next;
    };
    node *first;
    int size;

public:
    CircularLinkedList() {
        first = NULL;
        size = 0;
    }
    void insertAtHead(T element) {
        node *newNode = new node;
        newNode->item = element;

//        defensive programming
// check if the list is empty
        if (size == 0) {
            first = newNode;
            newNode->next = first;
        }
//        if the list is not empty
        else {
            newNode->next = first;
            first = newNode;
        }
        size++;
    }


    void insertAtEnd(T element) {
        node *newNode = new node;
        newNode->item = element;

//       defensive programming
// check if the list is empty
        if (size == 0) {
            first = newNode;
            newNode->next = first;
        }
//        if the list is not empty
        else {
//          traverse the list to reach the last node
            node *current = first;
            while (current->next != first) {
                current = current->next;
            }

            current->next = newNode;
            newNode->next = first;
        }
        size++;
    }

    void insertAt(T element, int index) {
        node *newNode = new node;
        newNode->item = element;

//        defensive programming
// check if the list is empty
        if (size == 0) {
            cout << "List is empty this element will be the first in the list then!!" << endl;
            insertAtHead(element);
        }

// check if the index is out of range
        else if (index < 0 || index >= size) {
            cout << "Index out of range!!" << endl;
        }

// check if the index is the first node
        else if (index == 0) {
            insertAtHead(element);
        }

// check if the index is the last node
        else if (index == size-1) {
            insertAtEnd(element);
        }

// if the index is in the middle of the list
        else {
            node *current = first;
//         traverse the list to reach the node before the index
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            size++;
        }

    }

    void removeAtHead() {
//        defensive programming
// check if the list is empty
        if (size == 0) {
            cout << "List is empty!!" << endl;
        }
// check if the list has only one node
        else if (size == 1) {
            delete first;
            first = NULL;
            size--;
        }
// if the list has more than one node
        else {
            node *current = first;
//         traverse the list to reach the last node
            while (current->next != first) {
                current = current->next;
            }

            current->next = first->next;//make the last node point to the second node
            node *temp = first;//store the first node in a temp variable
            first = first->next;//make the first node point to the second node
            delete temp;//delete the first node
            size--;
        }
    }

    void removeAtEnd() {
//        defensive programming
// check if the list is empty
        if (size == 0) {
            cout << "List is empty!!" << endl;
        }

// check if the list has only one node
        else if (size == 1) {
            delete first;
            first = NULL;
            size--;
        }
//        if the list has more than one node
        else {
            node *current = first;
//         traverse the list to reach the node before the last node
            while (current->next->next != first) {
                current = current->next;
            }
            node *temp = current->next;//store the last node in a temp variable
            current->next = first;//make the node before the last node point to the first node
            delete temp;//delete the last node
            size--;
        }
    }

    void removeAt(int index) {
//        defensive programming
// check if the list is empty
        if (size == 0) {
            cout << "List is empty!!" << endl;
        }

//        check if the index is out of range
        else if (index < 0 || index >= size) {
            cout << "Index out of range!!" << endl;
        }
//        check if the index is the first node
        else if (index == 0) {
            removeAtHead();
        }
//        check if the index is the last node
        else if (index == size - 1) {
            removeAtEnd();
        }
//        if the index is in the middle of the list
        else {
            node *current = first;
//         traverse the list to reach the node before the index
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            node *temp = current->next;//store the node at the index in a temp variable
            current->next = current->next->next;//make the node before the index point to the node after the index
            delete temp;//delete the node at the index
            size--;
        }

    }


    T retrieveAt(int index) {
//        defensive programming
// check if the list is empty
        if (size == 0) {
            cout << "List is empty!!" << endl;
        }
//        check if the index is out of range
        else if (index < 0 || index >= size) {
            cout << "Index out of range!!" << endl;
        }
//        check if the index is the first node
        else if (index == 0) {
            return first->item;
        }
//        if the index is in the middle of the list
        else {
            node *current = first;
//         traverse the list to reach the node before the index
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            return current->next->item;
        }
    }

    int circularLinkedListSize() {
        return size;
    }

    void print() {
        node *current = first;
        while (current->next != first) {
            cout << current->item << " ";
            current = current->next;
        }
        cout << current->item << endl;
    }

    bool isEmpty() {
        return size == 0;
    }

    void clear() {
        while (!isEmpty()) {
            removeAtEnd();
        }
    }

    void replaceAt(T element, int index) {
//        defensive programming
// check if the list is empty
        if (size == 0) {
            cout << "List is empty!!" << endl;
        }
//        check if the index is out of range
        else if (index < 0 || index > size) {
            cout << "Index out of range!!" << endl;
        }
//        if the index is in the middle of the list
        else {
            node *current = first;
//         traverse the list to reach the node before the index
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            current->next->item = element;
        }
    }

    bool isExist(T element) {
        node *current = first;
//        traverse the list to reach the last node
        for(int i = 0; i < size ; i++) {
            if (current->item == element) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool isItemAtEqual(T element ,int index){

        //        defensive programming
// check if the list is empty
        if (size == 0) {
            cout << "List is empty!!" << endl;
        }
//        check if the index is out of range
        else if (index < 0 || index > size) {
            cout << "Index out of range!!" << endl;
        }

        node *current =  first;
//        traverse the list to reach the last node
        for(int i = 0; i < index-1 ; i++) {
            current = current->next;
        }

        if (current->item == element){
            return true;
        }
        return false;

    }
    void swap(int firstItemIdx, int secondItemIdx) {
//        defensive programming
// check if the index is out of range
        if (firstItemIdx < 0 || firstItemIdx >= size || secondItemIdx < 0 || secondItemIdx >= size) {
            cout << "Index out of range" << endl;
            return;
        }
        node *firstItem = first;
        node *secondItem = first;
//        traverse the list to reach the node at first index
        for (int i = 0; i < firstItemIdx; i++) {
            firstItem = firstItem->next;
        }
//        traverse the list to reach the node at the second index
        for (int i = 0; i < secondItemIdx; i++) {
            secondItem = secondItem->next;
        }
        T temp = firstItem->item;
        firstItem->item = secondItem->item;
        secondItem->item = temp;
    }

};

