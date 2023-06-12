#include "SingleLinkedList.cpp"
void combine_between_zeros(SingleLinkedList<int> linkedList) {

    SingleLinkedList<int> resultList;
    int result =0;
//    traverse the list starting form the second node because the first node is zero
    for (int i = 1; i < linkedList.getSize() ; i++) {

//        if the node is not zero add it to the result
        if(linkedList.retrieveAt(i) != 0) {
            result += linkedList.retrieveAt(i);
        }
//        if the node is zero add the result to the result list and reset the result
        else{
            resultList.insertAtTail(result);
            result = 0;
        }
    }
    resultList.printList();
}
