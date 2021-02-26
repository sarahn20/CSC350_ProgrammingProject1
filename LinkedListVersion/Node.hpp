#ifndef Node_hpp
#define Node_hpp

//needs a semicolon because read in as a statement by the compiler

class Node
{
private: 
    int payload;
    Node* nextNode;

public: 
    Node(int payload);
    void setNextNode(Node* n);
    int getPayload();
    Node* getNextNode();
};
#endif /* Node_hpp */