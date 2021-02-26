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
    this->first_child = -1;
    this->older_sibling = -1;
    this->younger_sibling = -1;
}

int PCB::getLastSibling()
{
    if(this->first_child != -1)
    {
        if(pcbs[this->first_child]->younger_sibling != -1)
        {
            int youngest_sibling = pcbs[this->first_child]->younger_sibling;
            while(pcbs[youngest_sibling]->younger_sibling != -1)
            {
                youngest_sibling = pcbs[youngest_sibling]->younger_sibling;
            }
            return youngest_sibling;
        }
        else
        {
            return this->first_child;
        }
    }
    else
    {
        return 0;
    }
    
}

void PCB::display()
{
    std::cout<<"parent: "<<this->index<<" children: ";
    if(this->first_child == -1)
    {
        std::cout<<"NO CHILDREN\n";
    }
    else if(this->first_child != -1)
    {
        std::cout<<first_child;
        if(pcbs[this->first_child]->younger_sibling != -1)
        {
            int youngest_sibling = pcbs[this->first_child]->younger_sibling;
            std::cout<<youngest_sibling;
            while(pcbs[youngest_sibling]->younger_sibling != -1)
            {
                youngest_sibling = pcbs[youngest_sibling]->younger_sibling;
                std::cout<<youngest_sibling;
            }
            
        }
        std::cout<<"\n";
    }
}

PCB* PCB::create()
{
    PCB* q = new PCB(this->index);
    if(this->first_child == -1)
    {
        this->first_child = q->index;
    }
    else if(pcbs[this->first_child]->younger_sibling == -1)
    {
        pcbs[first_child]->younger_sibling = q->index;
        q->older_sibling = first_child;
    }
    else if(pcbs[this->first_child]->younger_sibling != -1)
    {
        int youngest_sibling = this->getLastSibling();
        q->older_sibling = youngest_sibling;
        pcbs[youngest_sibling]->younger_sibling = q->index;
    }
    this->display();
    return q;
}

void PCB::destroy()
{
    while(this->first_child != -1)
    {
        if(pcbs[this->getLastSibling()]->first_child != -1)
        {
            pcbs[this->getLastSibling()]->destroy();
        }
        else
        {
            int holder = this->getLastSibling();
            if(pcbs[this->getLastSibling()]->older_sibling != -1)
            {
                pcbs[pcbs[this->getLastSibling()]->older_sibling]->younger_sibling = -1;
            }
            else
            {
                this->first_child = -1;
            }
            pcbs[holder] = 0;
        } 
    } 
    this->display();
}
