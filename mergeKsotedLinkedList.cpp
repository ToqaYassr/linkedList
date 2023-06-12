#include <iostream>
using namespace std;

// merge k sorted linked lists
//using an array of pointers to nodes
class Node {
public:
    int data;
    Node *next;
};

class LinkedList {
private:
    Node *head;
    Node *tail;
public:

    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtTail(int element) {
        Node *newNode = new Node;
        newNode->data = element;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    Node *getHead() {
        return head;
    }
};

LinkedList mergeTwoLists(Node *l1, Node *l2) {

    LinkedList mergedList;
    Node *left = l1;
    Node *right = l2;

//    to add the smaller element in the merged list
    while (left != NULL && right != NULL) {

//check if the left element is smaller than the right element
        if (left->data < right->data) {
            mergedList.insertAtTail(left->data);
            left = left->next;
        }
//if the right element is smaller than the left element
        else {
            mergedList.insertAtTail(right->data);
            right = right->next;
        }
    }

    // to add the remaining elements in the left list
    while (left != NULL) {
        mergedList.insertAtTail(left->data);
        left = left->next;
    }

//    to add the remaining elements in the right list
    while (right != NULL) {
        mergedList.insertAtTail(right->data);
        right = right->next;
    }

    return mergedList;
}


LinkedList mergeKSortedLists(Node *arr[], int k) {
    LinkedList mergedList;
// the array of has only one list
    if (k == 1) {
        while (arr[0] != NULL) {
            mergedList.insertAtTail(arr[0]->data);
            arr[0] = arr[0]->next;
        }
        return mergedList;
    }

// if the array of has only two lists
    mergedList = mergeTwoLists(arr[0], arr[1]);

    // if the array of has more than two lists
    if (k > 2) {
        for (int i = 2; i < k; i++) {
            mergedList = mergeTwoLists(mergedList.getHead(), arr[i]);
        }
    }

    return mergedList;
}


int main() {
// [1, 4, 5], [1, 3, 4], [2, 6] [0, 9, 10]. output: [0, 1, 1, 2, 3, 4, 4, 5, 6, 9, 10]
    LinkedList list1, list2, list3, list4, list5;
//111233445567
    list1.insertAtTail(1);
    list1.insertAtTail(4);
    list1.insertAtTail(5);

    list2.insertAtTail(1);
    list2.insertAtTail(3);
    list2.insertAtTail(4);

    list3.insertAtTail(2);
    list3.insertAtTail(6);

    list4.insertAtTail(1);
    list4.insertAtTail(3);
    list4.insertAtTail(5);
    list4.insertAtTail(7);

    list5.insertAtTail(0);
    list5.insertAtTail(9);
    list5.insertAtTail(10);


    Node *arr[5];
    arr[0] = list1.getHead();
    arr[1] = list2.getHead();
    arr[2] = list3.getHead();
    arr[3] = list4.getHead();
    arr[4] = list5.getHead();

    int k = 5;
    mergeKSortedLists(arr, k).print();

    return 0;

}


