#include <iostream>
#include <string>
#include "linkedList.hpp"
//#define NMAX 100

template <typename T>
linkedList::linkedList<T>::linkedList(){
    head = nullptr;
    length = 0;
}

template <typename T>
void linkedList::linkedList<T>::push(T new_data){
    // Create the node that contains the new information
    node<T> * temp = new node<T>();
    temp->data = new_data;

    // Create a temporary copy of the node of the head
    node<T> * temp_head = new node<T>();
    temp_head = this->head;

    // The head stores the node of the data pointer and takes as next element the copy of the pointer of the previous head
    this->head = temp;
    head->next = temp_head;
    
    // Increase the length
    this->length++;
}

template <typename T>
void linkedList::linkedList<T>::push(node<T> * new_node){
    // Create a temporary copy of the node of the head
    node<T> * temp_head = new node<T>();
    temp_head = this->head;

    // The head stores the node of the data pointer and takes as next element the copy of the pointer of the previous head
    this->head = new_node;
    head->next = temp_head;
    
    // Increase the length
    this->length++;
}

template <typename T>
linkedList::node<T> * linkedList::linkedList<T>::pop(){
    node<T> * temp = this->head;
    temp = this->head;
    this->head = this->head->next;
    length --;
    return temp;
}

template <typename T>
linkedList::node<T> * linkedList::linkedList<T>::popByValue(T check){
    // Initialize the variables to be used for the check
    node<T> * to_check = this->head;
    node<T> * previous = nullptr;

    // In case the first value of the list is adequate, it is the same as popping
    if (to_check->data == check){
        this->length--;
        return this->pop();
    }
    previous = to_check;
    to_check = to_check->next;

    // Iterate through the list until a value that applies the condition is found
    while (to_check != nullptr){
        if (to_check->data == check){
            previous -> next = to_check->next;
            this->length--;
            return to_check;
        }

        previous = to_check;
        to_check = to_check->next;
    }

    // No object is found to contain that data
    return to_check;
};

template <typename T>
int linkedList::linkedList<T>::checkLength(){
    return this->length;
}

//int main(){
//    linkedList::linkedList<int> list = linkedList::linkedList<int>();
//
//    std::cout << "[INFO]Length at beginning: " + std::to_string(list.checkLength())<< std::endl;
//    for (int i = 0; i < NMAX; i++){
//        list.push(i);
//    }
//    std::cout << "[INFO]Length after adding values: " + std::to_string(list.checkLength())<< std::endl;
//    for (int i = 0; i < NMAX; i++){
//        linkedList::node<int> * popped = list.pop();
//        std::cout << "[INFO] Popping value " + std::to_string(popped->data) + " from list..." << std::endl;
//        delete popped;
//    }
//    std::cout << "[INFO]Length after deleting values: " + std::to_string(list.checkLength())<< std::endl;
//
//    return 0;
//}

/* int main(){
    linkedList::linkedList<int> list = linkedList::linkedList<int>();

    std::cout << "[INFO]Length at beginning: " + std::to_string(list.checkLength())<< std::endl;
    for (int i = 0; i < NMAX; i++){
        list.push(i);
    }
    std::cout << "[INFO]Length after adding values: " + std::to_string(list.checkLength())<< std::endl;

    linkedList::node<int> * check1 = list.popByValue(101);
    std::cout << "[INFO]Pointer of the first check and value: ( " << check1 << ")" << std::endl;
    linkedList::node<int> * check2 = list.popByValue(90);
    std::cout << "[INFO]Pointer of the second check and value: ( " << check2 << ")" << std::endl;
    std::cout << "[INFO] Length of the list is now: " << list.checkLength() << std::endl;

    int length = list.checkLength();
    for (int i = 0; i < length; i++){
        linkedList::node<int> * popped = list.pop();
        std::cout << "[INFO] Popping value " + std::to_string(popped->data) + " from list..." << std::endl;
        delete popped;
    }

    std::cout << "[INFO]Length after deleting values: " + std::to_string(list.checkLength())<< std::endl;

    return 0;
} */