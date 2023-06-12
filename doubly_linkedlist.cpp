#include "iostream"

using namespace std;

template<class t>
class doublyLinkedlist {
    /*

o insertAfter (* prev_node, int data) : void

o reverse () : void //reverse the data in the double linked list
*/
private:
    struct node {
        t item;
        node *prev;
        node *next;
    };
    node *first;
    node *last;
    int count;

public :

    doublyLinkedlist() {
        first = last = NULL;
        count = 0;
    }


    bool isempty() {

        return first == NULL;
    }


    void insertAtHead(t element) {
        node *newNode = new node;
        newNode->item = element;
        if (isempty()) {

            first = last = newNode;
            newNode->next = newNode->prev = NULL;

        } else {
            newNode->next = first;
            newNode->prev = NULL;
            first->prev = newNode;

            first = newNode;

        }
        count++;

    }


    void insertAtTail(t element) {
        node *newNode = new node;
        newNode->item = element;
        if (isempty()) {

            first = last = newNode;
            newNode->next = newNode->prev = NULL;

        } else {
            newNode->prev = last;
            newNode->next = NULL;
            last->next = newNode;
            last = newNode;

        }
        count++;
    }


    void insertAt(t element, int index) {


        if (isempty()) {
            cout << "List is empty this element will be the first in the list then!!" << endl;
            insertAtHead(element);

        } else if (index == 0) {
            insertAtHead(element);
        }
            //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            //edit in linked list <=
        else if (index < 0 || index > count) {
            cout << "Index out of range" << endl;
        } else if (index == count) {
            insertAtTail(element);
        } else {
            node *newNode = new node;
            newNode->item = element;
            node *current = first;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            current->prev->next = newNode;
            newNode->prev = current->prev;
            newNode->next = current;
            current->prev = newNode;


            count++;
        }

    }

    void insertAfter(node *b, t data) {
//    defensive programming
// check if the list is empty
        if (isempty()) {
            cout << "List is empty this element will be the first in the list then!!" << endl;
            insertAtHead(data);

        }
//    if the list is not empty
        else if (b == NULL) {
            cout << "Invalid node" << endl;
        }
//        if the node that we want to insert after is the first node
        else if (b == first) {
            node *newNode = new node;
            newNode->item = data;
            newNode->next = first->next;
            newNode->prev = first;
            first->next->prev = newNode;
            first->next = newNode;
            count++;
        } else if (b == last) {
            insertAtTail(data);
        } else {
            node *newNode = new node;
            newNode->item = data;

            newNode->next = b->next;//make the new node point to the next node of the node that we want to insert after
            newNode->prev = b;//make the new node point to the node that we want to insert after
            b->next->prev = newNode;//make the node that after the node that we want to insert after point to the new node
            b->next = newNode;
            count++;
        }


    }

    void funToTest_insertafter_function(int nodeNumber, t data) {
        node *current = first;
        for (int i = 1; i < nodeNumber; i++) {
            current = current->next;
        }
        cout << current->item << endl;

        insertAfter(current, data);
    }

    void removeAtHead() {
        if (isempty()) {
            cout << "List is empty !" << endl;
        } else if (count == 1) {
            delete first;
            first = last = NULL;
            count = 0;
        } else {
            node *temp = first;
            first = first->next;
            first->prev = NULL;
            delete temp;
            count--;
        }
    }


    void removeAtTail() {
        if (isempty()) {
            cout << "List is empty !" << endl;
        } else if (count == 1) {
            delete first;
            first = last = NULL;
            count = 0;
        } else {
            node *temp = last;
            last = last->prev;
            last->next = NULL;
            delete temp;
            count--;
        }
    }

    void removeAt(int index) {
        if (isempty()) {
            cout << "List is empty !" << endl;


        } else if (index == 0) {
            removeAtHead();
        }
            //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            //edit in linked list <=
        else if (index < 0 || index > count) {
            cout << "Index out of range" << endl;
        } else if (index == count - 1) {
            removeAtTail();
        } else {
            node *temp = first;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            count--;
        }

    }


    t retrieveAt(int index) {
        if (isempty()) {
            cout << "List is empty !" << endl;
        } else if (index < 0 || index >= count) {
            cout << "Index out of range";
        } else if (index == 0) {
            return first->item;
        } else if (index == count - 1) {
            return last->item;
        } else {
            node *temp = first;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp->item;
        }
    }


    void replaceAt(t newElement, int index) {
        node *newnode = new node;
        newnode->item = newElement;
        if (isempty()) {
            cout << "List is empty !" << endl;
        } else if (index < 0 || index > count) {
            cout << "Index out of range" << endl;
        } else if (index == count - 1) {
            node *curr = last;
            newnode->prev = last->prev;
            last->prev->next = newnode;
            newnode->next = NULL;
            last = newnode;
            delete curr;
        } else if (index == 0) {
            node *curr = first;
            first->next->prev = newnode;
            newnode->next = first->next;
            newnode->prev = NULL;
            first = newnode;
            delete curr;
        } else {
            node *curr = first;
            for (int i = 0; i < index; i++) {
                curr = curr->next;
            }
            newnode->next = curr->next;
            newnode->prev = curr->prev;
            curr->next->prev = newnode;
            curr->prev->next = newnode;
            delete curr;

        }

    }

    bool isExist(t element) {
        node *curr = first;
        for (int i = 0; i < count; i++) {
            if (curr->item == element) {
                return 1;
            } else {
                curr = curr->next;
            }
        }
        return 0;

    }


    bool isItemAtEqual(t element, int index) {
        if (isempty()) {

            return 0;

        } else if (index < 0 || index >= count) {
            return 0;
        } else {
            node *curr = first;
            for (int i = 0; i < index; i++) {
                curr = curr->next;

            }

            if (curr->item == element) {
                return 1;
            } else {
                return 0;
            }

        }
    }


    void swap(int firstItemIdx, int secondItemIdx) {
        if (isempty()) {
            cout << "List is empty !" << endl;
        } else if (firstItemIdx < 0 || firstItemIdx >= count || secondItemIdx < 0 || secondItemIdx >= count) {
            cout << "Index out of range" << endl;
        } else {
            node *firstnode = first;
            node *secondnode = first;
            for (int i = 0; i < firstItemIdx; i++) {
                firstnode = firstnode->next;
            }
            for (int i = 0; i < secondItemIdx; i++) {
                secondnode = secondnode->next;
            }

            t data = secondnode->item;
            t jj = first->item;
            secondnode->item = jj;
            firstnode->item = data;
        }
    }

    void reverse() {
        if (isempty()) {
            cout << "List is empty !" << endl;
        } else {
            node *curr = first;
            node *temp;
//            traverse the list and swap the prev and next pointers of each node
            while (curr != NULL) {
                temp = curr->prev;
                curr->prev = curr->next;
                curr->next = temp;
                curr = curr->prev;
            }
            temp = first;
            first = last;
            last = temp;
        }

    }

    int doubleLinkedListSize() {
        return count;
    }


    void clear() {

        if (isempty()) {
            cout << "List is empty !" << endl;
        } else {
            node *temp;
            while (first != NULL) {
                temp = first;
                first = first->next;
                delete temp;
            }
            last = NULL;
            count = 0;
        }
    }


    void forwardTraversal() {
        if (isempty()) {
            cout << "List is empty !" << endl;


        } else {
            node *current = first;
            while (current != NULL) {
                cout << current->item << " ";
                current = current->next;

            }
            cout << endl;
        }
    }


    void backwardTraversal() {
        if (isempty()) {
            cout << "List is empty !" << endl;


        } else {
            node *current = last;
            while (current != NULL) {
                cout << current->item << " ";
                current = current->prev;
            }
            cout << endl;
        }

    }


};

int main() {
    doublyLinkedlist<int> d;
//    cout<< "insert test"<<endl;
//    d.insertAtHead(6);
//    d.insertAtTail(8);
//    d.insertAt(10,2);
//    d.insertAt(15,3);
//    cout<<d.doubleLinkedListSize()<<endl;
//    d.backwardTraversal();
//
//    cout<< "retrieve test"<<endl;
//    cout<< d.retrieveAt(1)<<endl;
//    cout <<d.retrieveAt(0)<<endl;
//    cout <<d.retrieveAt(3)<<endl;
//    cout <<d.retrieveAt(6)<<endl;
//    d.backwardTraversal();
//
//    cout <<"replace test "<<endl;
//    d.replaceAt(5,0);
//    d.forwardTraversal();
//    d.replaceAt(50,2);
//    d.forwardTraversal();
//    d.replaceAt(5,8);
//    d.forwardTraversal();
//    d.replaceAt(21,3);
//    d.forwardTraversal();
//    d.backwardTraversal();
//    cout<< "exit test"<<endl;
//    cout<< d.isExist(21)<<endl;
//    cout<<d.isExist(66)<<endl;
//    cout<<d.isExist(5)<<endl;
//    d.backwardTraversal();
//
//    cout<< "is at test"<<endl;
//    cout<<d.isItemAtEqual(21,6);
//    cout<<d.isItemAtEqual(21,3);
//    cout<<d.isItemAtEqual(21,1);
//    cout<<d.isItemAtEqual(5,0)<<endl;
//    d.backwardTraversal();
//
//    cout<< "swap test"<<endl;
//    d.swap(0,1);
//    d.backwardTraversal();
//    d.clear();
//    d.forwardTraversal();
//
//    d.backwardTraversal();
//
//    cout<< "reverse test"<<endl;
//    d.insertAtHead(6);
//    d.insertAtTail(8);
//    d.insertAt(10,2);
//    d.insertAt(15,3);
//    d.backwardTraversal();
//    cout<<"insert after node 2"<<endl;
//    d.backwardTraversal();
//    d.funToTest_insertafter_function(1);
//    d.backwardTraversal();
//    d.reverse();
//    d.backwardTraversal();

    d.insertAtTail(1);
    d.insertAtTail(2);
    d.insertAtTail(3);
    d.insertAtTail(4);
    d.forwardTraversal();
    d.funToTest_insertafter_function(3, 2);
    d.forwardTraversal();
    d.forwardTraversal();
    d.reverse();
    d.forwardTraversal();
    return 0;


}
