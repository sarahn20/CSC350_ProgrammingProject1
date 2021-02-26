#ifndef LinkedList_hpp
#define LinkedList_hpp
#include "Node.hpp"

class LinkedList
{
private: 
    Node* head;
    int count;
    Node* runToEndOfList();

public: 
    LinkedList();
    void addFront(int payload);
    int getFront();
    int removeFront();
    void addEnd(int payload);
    int getEnd();
    int removeEnd();
    int getCount();
};
#endif /* LinkedList_hpp */