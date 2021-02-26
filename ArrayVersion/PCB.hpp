#ifndef PCB_hpp
#define PCB_hpp

class PCB
{
private:
    int index;
    int parent;
    int first_child;
    int younger_sibling;
    int older_sibling;

public:
    PCB(int parent);
    PCB* create();
    void destroy();
    int getLastSibling();
};
#endif /* PCB_hpp */