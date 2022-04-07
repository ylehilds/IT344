/* Implements queue abstract data type. */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct queue_link_data_t *queue_link_t;

struct queue_link_data_t {
  queue_element_t e;
  queue_link_t next;
};

struct queue_data_t {
  queue_link_t head;
};

queue_t queue_create()
{
  queue_t q = (queue_t)malloc(sizeof(struct queue_data_t));
  q->head = NULL;
  return q;
}

/* Private */
static queue_link_t
queue_new_element(queue_element_t e)
{
  queue_link_t qlt = (queue_link_t)malloc(sizeof(struct queue_link_data_t));
  qlt->e  = e;
  qlt->next = NULL;
  return qlt;
}


void
queue_append(queue_t q, queue_element_t e) 
{
  queue_link_t cur = (queue_link_t)malloc(sizeof(struct queue_link_data_t));
	
  assert(q != NULL);

  
  //cur = q->head;
  if (cur != NULL)
  {
  //while (cur->next) {
   // cur = cur->next;
  //}
  cur->next = queue_new_element(e);
  q = cur;
  q++;
  }
}


boolean_t
queue_remove(queue_t q, queue_element_t *e) 
{
  queue_link_t oldHead;
	
  assert(q != NULL);
  if (queue_is_empty(q))
    return FALSE;

  *e = q->head->e;
  
  oldHead = q->head;
  q->head = q->head->next;
  return TRUE;
}


boolean_t
queue_is_empty(queue_t q)
{
  assert(q != NULL);
  return (q->head == NULL);
}


/* private */
static boolean_t
queue_count_one(queue_element_t e, queue_pfapply_closure_t cl)
{
  int *x = (int*)cl;
  *x = *x + 1;
  return TRUE;
}

int
queue_size(queue_t q)
{
  int sz = 0;
  queue_apply(q, queue_count_one, &sz);
  return sz;
}

boolean_t queue_apply(queue_t q, queue_pfapply_t pf, queue_pfapply_closure_t cl) 
{
  assert(q != NULL && pf != NULL);
  
  if (queue_is_empty(q))
    return FALSE;

  queue_link_t cur;
  if (q != NULL)
  {
  for (cur = q->head; cur; cur = cur->next) {
    if (!pf(cur->e, cl))
      break;
  }
  }
  return TRUE;
}


  

  
