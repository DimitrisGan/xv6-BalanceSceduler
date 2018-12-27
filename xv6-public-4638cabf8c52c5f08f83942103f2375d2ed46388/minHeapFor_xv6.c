#include "types.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "x86.h"
#include "syscall.h"
#include "spinlock.h"

#include "minHeapFor_xv6.h"

int flag=0;
// http://wikistack.com/c-program-for-min-heap/
// http://wikistack.com/max-heap-and-min-heap/
// https://stackoverflow.com/questions/6531543/efficient-implementation-of-binary-heaps

// struct heap ds;

void initminHeap () //t size tha nai panta 64 opote de xreiazetai to orisma
{
    cprintf("initminHeap\n");

  ds.node_index = 0;

}
/* get left child index */
int getLeft (int index)
{
  return 2 * index +1;
}

/* get right child index */
int getRight (int index)
{
  return 2 * index + 2;
}

/* get parent index */
int getParent (int index)
{
  return ((index-1 )/ 2);
}

void heapyfy_push (int index)
{

  if (index >= NPROC)
    return;
  int parentNodeIndex = getParent (index);

  struct proc* tmp;
  if (index != 0)
    {

      if (ds.data[parentNodeIndex]->priority > ds.data[index]->priority) //ean o pateras einai megaluteros ap'to paidi -->kane allagh
        {
          tmp = ds.data[parentNodeIndex];
          ds.data[parentNodeIndex] = ds.data[index];
          ds.data[index] = tmp;
          heapyfy_push (parentNodeIndex);
        }
    }
}

void mHeap_push (struct proc * p)
{

    double denominator = ticks - p->creation_time;
    if (denominator!=0 ){
      p->priority = (p->running_time/denominator);

    }



  // check if heap is full or not full
  if (ds.node_index  < NPROC)
    {
      ds.data[ds.node_index] = p;

      if (ds.data[ds.node_index]->state == RUNNABLE)

      heapyfy_push (ds.node_index);
      ds.node_index++;
    }

}


void heapyfy_pop (int index)
{
  struct proc* tmp;
  int left = getLeft (index);
  int right = getRight (index);
  int min_index;
  if (right >= ds.node_index)
    {
      if (left >= ds.node_index)
        return;
      else
        min_index = left;
    }
  else
    {
      if (ds.data[left]->priority <= ds.data[right]->priority)
        min_index = left;
      else
        min_index = right;
    }
  if (ds.data[index]->priority > ds.data[min_index]->priority)
    {
      tmp = ds.data[min_index];
      ds.data[min_index] = ds.data[index];
      ds.data[index] = tmp;
      heapyfy_pop (min_index);
    }
}

int isEmpty ()
{
  if (ds.node_index == 0)
    return 1;
  else
    return 0;
}


struct proc* pop ()
{

  struct proc* minproc;
  if (!isEmpty ())
    {
      minproc = ds.data[0];

      ds.node_index--;
      ds.data[0] = ds.data[ds.node_index];

      if (ds.node_index > 0)
        heapyfy_pop (0);

      return minproc;
    }

    else{ //empty minheap
        return 0;
    }
}



int getHeapSize(){
  return ds.node_index;
}
