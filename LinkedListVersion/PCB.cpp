#include "PCB.hpp"
#include <iostream>

PCB* pcbs[5] = {0};

PCB::PCB(int parent)
{
    int currIndex = 0;
    while((pcbs[currIndex] != 0) && currIndex < 6)
    {
        currIndex++;
    }
    if(pcbs[currIndex] == 0){
        pcbs[currIndex] = this;
        this->index = currIndex;
    }
    this->parent = parent;
    this->children = new LinkedList();
}

PCB* PCB::create()
{
    PCB* q = new PCB(this->index);
    this->children->addEnd(q->index);
    return q;
}

void PCB::destroy()
{
    while(this->children->getCount() > 0)
    {
        if(pcbs[this->children->getEnd()]->children->getCount() > 0)
        {
            pcbs[this->children->getEnd()]->destroy();
        }
        else
        {
            pcbs[this->children->getEnd()]= 0;
            this->children->removeEnd();
        }
        
    }
    
}
