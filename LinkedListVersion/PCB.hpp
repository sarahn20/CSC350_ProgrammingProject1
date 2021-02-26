#ifndef PCB_hpp
#define PCB_hpp
#include "LinkedList.hpp"

class PCB
{
private:
    int index;
    int parent;
    LinkedList* children;
    
public:
    PCB(int parent);
    PCB* create();
    void destroy();
};
#endif /* PCB_hpp */
