#include <stdio.h>
#include "queue.h"

int x = 0;
int y = 1;
int z = 2;

boolean_t
show_one(queue_element_t e, queue_pfapply_closure_t cl) 
{
  printf("Item %d == %d\n", *(int*)cl, *(int*)e);
  *(int*)cl = *(int*)cl + 1;
  return TRUE;
}

  
int main(int argc, char* argv[])
{
  queue_t q = queue_create();
  queue_append(q, &x);
  queue_append(q, &y);
  queue_append(q, &z);
  queue_append(q, &x);  
  printf("Queue size is %d\n", queue_size(q));

  int x = 0;
  queue_apply(q, show_one, &x);

  return 0;
}
