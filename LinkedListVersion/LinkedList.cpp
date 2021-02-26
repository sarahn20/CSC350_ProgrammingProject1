#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList()
{
    this->count = 0;
}

int LinkedList::getCount()
{
    return this->count;
}

void LinkedList::addFront(int payload)
{
    Node* n = new Node(payload);


    if(!this->head)
    {
        this->head = n;
    }
    else
    {
        n->setNextNode(this->head);
        this->head = n;
    }
    this->count++;
}

int LinkedList::getFront()
{
    return this->head->getPayload();
}

int LinkedList::removeFront()
{
    Node* nodeToReturn = this->head;
    this->head = this->head->getNextNode();
    int val = nodeToReturn->getPayload();
    delete nodeToReturn;
    this->count--;
    return val;
}

Node* LinkedList::runToEndOfList()
{
    Node* currNode = this->head;
    while(currNode->getNextNode()) //returns true when currNode has a next node
    {
        currNode = currNode->getNextNode(); // (*currNode).getNextNode()
    }
    return currNode;
}

void LinkedList::addEnd(int payload)
{
   if(!this->head)
   {
       this->addFront(payload);
   }
   else
   {
       //we have at least one thing in our list
       //traverse to end of list and connect new node

       Node* n = new Node(payload);
       Node* currNode = this->runToEndOfList();
       //currNode now points to the end of our list (ie the last Node)
       currNode->setNextNode(n);
       this->count++;
   }
}

int LinkedList::getEnd()
{
    Node* currNode = this->runToEndOfList();
    //currNode points to the end of the list
    return currNode->getPayload();
}

int LinkedList::removeEnd()
{
    //we are assuming the list has at least one element in it for now
    //is this a list with a single element in it?
    if(!this->head->getNextNode())
    {
        return this->removeFront();
    }
    else
    {
        //we have at least two elements in our list
        Node* theLastGuy = this->runToEndOfList();
        Node* theGuyBeforeTheLastGuy = this->head;
        while(theGuyBeforeTheLastGuy->getNextNode() != theLastGuy)
        {
            theGuyBeforeTheLastGuy = theGuyBeforeTheLastGuy->getNextNode();
        }
        //theGuyBeforeTheLastGuy now points to the Node right before theLastGuy
        theGuyBeforeTheLastGuy->setNextNode(0);
        int valueToReturn = theLastGuy->getPayload();
        delete theLastGuy;
        this->count--;
        return valueToReturn;
    }
    
}

void LinkedList::display()
{
    Node* currNode = this->head;
    if(this->count == 0)
    {
         std::cout << "NO CHILDREN";
    }
    else
    {
        for(int i = 0; i < this->count; i++)
        {
            std::cout << currNode->getPayload()<<"";
            currNode = currNode->getNextNode();
        }
    }
    std::cout << "\n";
}
