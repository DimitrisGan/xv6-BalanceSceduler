/* heap data structure */
 // #include "proc.h"
// #include "param.h"
// #include "defs.h"

// struct data{
//     float priority;
//     struct proc *proc;
// };

struct heap
{
    struct proc* data[NPROC ];// struct data data[64] ;        // array to hold node value
    // int capacity;     // capacity of min heap =64
    int node_index;   // index of nodes <=64
};

 struct heap ds;

/*
void initminHeap ();
int getLeft (int index);
int getRight (int index);
int getParent (int index);
void heapyfy_push (int index);
void mHeap_push (struct proc * p);
void heapyfy_pop (int index);
struct proc* pop ();
void printHeap ();
int getHeapSize();
*/
