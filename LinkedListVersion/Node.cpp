#include "Node.hpp"

//implementing the things defined in the header file

Node::Node(int payload)
{
    this->payload = payload;
}
void Node::setNextNode(Node* n)
{
    this->nextNode = n;
}
int Node::getPayload()
{
    return this->payload;
}
Node* Node::getNextNode()
{
    return this->nextNode;
}