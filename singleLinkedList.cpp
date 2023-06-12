#include <iostream>

using namespace std;

//Implement a Single Linked List with the following methods:
//o insertAtHead (elementType element) : void
//o insertAtTail (elementType element) : void
//o insertAt (elementType element, int index) : void
//o removeAtHead () : void
//o removeAtTail () : void
//o removeAt (int index) : void

//o retrieveAt (int index): elementType
//o replaceAt (elementType newElement, int index)
//o isExist (elementType element) : bool
//o isItemAtEqual (elementType element, int index) : bool

//o isEmpty () : bool
//o linkedListSize () : int
//o clear (): void
//o print () : void

template<class T>
class SingleLinkedList {
private:
    struct Node {
        T data;
        Node *next;
    };

    Node *firstNode;
    Node *lastNode;
    int currentsize;
public:
//    constructor
    SingleLinkedList() {
        firstNode = lastNode = NULL;
        currentsize = 0;
    }


//    insert at head which is the first node in the list
    void insertAtHead(T element) {

        Node *newNode = new Node;
        newNode->data = element;

//        check if the list is empty
        if (currentsize == 0) {
            newNode->next = NULL;
            firstNode = lastNode = newNode;
        } else {
            newNode->next = firstNode;
            firstNode = newNode;
        }
        currentsize++;
    }

//    insert at tail which is the last node in the list
    void insertAtTail(T element) {
        Node *newNode = new Node;
        newNode->data = element;

        newNode->next = NULL;
//        check if the list is empty
        if (currentsize == 0) {
            firstNode = lastNode = newNode;
        } else {
            lastNode->next = newNode;//link the last node to the new node
            lastNode = newNode;//make the new node the last node
        }
        currentsize++;
    }


//    insert an item at a specific index
    void insertAt(T element, int index) {

//        defensive programming:
//        check if the list is empty
//        check if the index is out of range
        if (currentsize == 0) {
            cout << "List is empty this element will be the first in the list then!!" << endl;
            insertAtHead(element);
        }

//        check if the index is out of range
        else if (index < 0 || index > currentsize) {
            cout << "Index out of range" << endl;
        }

// check if the index is at the head which is the first node
        else if (index == 0) {
            insertAtHead(element);
        }

// check if the index is at the tail which is the last node
        else if (index == currentsize) {
            insertAtTail(element);
        } else {

            Node *newNode = new Node;
            newNode->data = element;

            Node *temp = firstNode;

//            traverse the list to the node before the index
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }

// temp is the node before the index
            newNode->next = temp->next;//link the new node to the node after the index
            temp->next = newNode;//link the node before the index to the new node
            currentsize++;
        }
    }

//    remove at head which is the first node in the list
    void removeAtHead() {
//        check if the list is empty
        if (currentsize == 0) {
            cout << "List is empty" << endl;
        } else {
            Node *temp = firstNode;//store the first node in a temp node to delete it later
            firstNode = firstNode->next;//make the second node the first node
            delete temp;//delete the first node
            currentsize--;
        }
    }

//    remove at tail which is the last node in the list
    void removeAtTail() {
//        check if the list is empty
        if (currentsize == 0) {
            cout << "List is empty" << endl;
        } else {

            Node *temp = firstNode;
//            traverse the list to the node before the last node
            for (int i = 0; i < currentsize - 2; i++) {
                temp = temp->next;
            }
//            temp is the node before the last node
            delete lastNode;//delete the last node
            lastNode = temp;//make the node before the last node the last node
            lastNode->next = NULL;//make the last node point to null
            currentsize--;
        }
    }

//    remove an item at a specific index
    void removeAt(int index) {
//        defensive programming:
//        check if the list is empty
//        check if the index is out of range
        if (currentsize == 0) {
            cout << "List is empty" << endl;
        } else if (index < 0 || index > currentsize) {
            cout << "Index out of range" << endl;
        }

// check if the index is at the head which is the first node
        else if (index == 0) {
            removeAtHead();
        }

// check if the index is at the tail which is the last node
        else if (index == currentsize) {
            removeAtTail();
        } else {
            Node *temp = firstNode;

//            traverse the list to the node before the index
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
//            temp is the node before the index


            Node *temp2 = temp->next;//store the node at the index in a temp node to delete it later
            temp->next = temp->next->next;//link the node before the index to the node after the index
            delete temp2;//delete the node at the index
            currentsize--;
        }

    }

//    retrieve an item at a specific index
    T retrieveAt(int index) {
//        defensive programming:
//        check if the list is empty
//        check if the index is out of range
        if (currentsize == 0) {
            cout << "List is empty" << endl;
        } else if (index < 0 || index > currentsize) {
            cout << "Index out of range" << endl;
        } else {
            Node *temp = firstNode;

//            traverse the list to the node at the index
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
//            temp is the node at the index
            return temp->data;
        }

    }

//    replace an item at a specific index
    void replaceAt(T newElement, int index) {
//        defensive programming:
//        check if the list is empty
//        check if the index is out of range
        if (currentsize == 0) {
            cout << "List is empty" << endl;
        } else if (index < 0 || index >= currentsize) {
            cout << "Index out of range" << endl;
        } else {
            Node *temp = firstNode;

//            traverse the list to the node at the index
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
//            temp is the node at the index
            temp->data = newElement;
        }
    }

    void swap(int firstItemIdx, int secondItemIdx) {
//    defensive programming:
// check if the index is out of range
        if (firstItemIdx < 0 || firstItemIdx >= this->currentsize || secondItemIdx < 0 || secondItemIdx >= this->currentsize) {
            cout << "Index out of range" << endl;
            return;
        }

        Node *firstItem = this->firstNode ;
        Node *secondItem = this->firstNode;
//        traverse the list to the node at the first index
        for (int i = 0; i < firstItemIdx; i++) {
            firstItem = firstItem->next;
        }
//        traverse the list to the node at the second index
        for (int i = 0; i < secondItemIdx; i++) {
            secondItem = secondItem->next;
        }
//        swap the data
        T temp = firstItem->data;
        firstItem->data = secondItem->data;
        secondItem->data = temp;
    }
//    print the list
    void printList() {
//        check if the list is empty
        if (currentsize == 0) {
            cout << "List is empty" << endl;
        } else {
            Node *temp = firstNode;

//            traverse the list and print the data
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }

            cout << endl;
        }


    }


//  check if an element is in the list (search for an element)
    bool isExist(T element) {

        Node *temp = firstNode;
        while (temp != NULL) {
            if (temp->data == element) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

//    check if the item is equal to the element at an index in the list
    bool isItemAtEqual(T element, int index) {
        Node *temp = firstNode;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
//        temp is the node at the index

        if (temp->data == element) {
            return true;
        }
        return false;
    }


//    check if the list is empty
    bool isEmpty() {
        return currentsize == 0;
    }

//    get the size of the list
    int getSize() {
        return currentsize;
    }

//    clear the list
    void clearList() {
//        check if the list is empty
        if (currentsize == 0) {
            cout << "List is empty" << endl;
        } else {
            Node *temp = firstNode;
//            traverse the list and delete the nodes
            while (temp != NULL) {
                Node *temp2 = temp;
                temp = temp->next;
                delete temp2;
            }
            firstNode = NULL;
            lastNode = NULL;
            currentsize = 0;
        }
    }

//    destructor
    ~SingleLinkedList() {
        clearList();
    }


};




