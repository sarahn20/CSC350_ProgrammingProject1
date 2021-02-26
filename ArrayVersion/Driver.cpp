#include "PCB.hpp"
#include <iostream>
int main()
{
    PCB* parent = new PCB(0);
    for (int i = 0; i < 30; i++) {
        PCB* first = parent->create();
        PCB* second = parent->create();
        PCB* third = second->create();
        PCB* fourth = parent->create();
        parent->destroy();
    }
}
