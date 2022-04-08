#ifndef _QUEUE_H
#define _QUEUE_H

/* Definitions for abstract queue. */

typedef struct queue_data_t *queue_t;

typedef void *queue_element_t;
typedef int boolean_t;

#ifndef FALSE
#define FALSE 0
#define TRUE (!FALSE)
#endif // FALSE

/*
 * Creates and returns a new queue.
 * Returns null on failure, else a valid queue.
 */
extern queue_t queue_create();

/*
 * Appends an element to the end of the queue.
 */
extern void queue_append(queue_t q, queue_element_t e);

/* Remove the first element from the queue and leaves result in e.
 *   Returns false if isEmpty() prior to remove.
 */
extern boolean_t queue_remove(queue_t q, queue_element_t *e);

/*
 * Returns TRUE if queue is empty. FALSE otherwise.
 */
extern boolean_t queue_is_empty(queue_t q);

/*
 * Returns number of elements in the queue.
 */
extern int queue_size(queue_t q);


/*
 * Function Application.
 *
 * Applies the given function to each element of the queue. Given closure
 * is also provided to the function. Given function should
 * return TRUE if iteration should continue.
 * 
 * Returns isEmpty().
 *
 * Behaviour is undefined if the state of the queue changes during the application.
 *
 * Sample client use:
 *

	int count_elements(queue_element_t e, queue_pfapply_closure_t c)
	{
	     int *x = (int*)c;
	     *x = *x + 1;
	     return TRUE;
        }

	void bar()
	{
	    int x = 0;
	    queue_t q = queue_new();
	    if (!q) error();
	    for (int i = 0; i < 10; i++) {   
	        queue_append(q, q);
            }
	    queue_apply(q, count_elements, &x);
	    printf("Queue size is %d\n", x);
	}
*/
	    


typedef void *queue_pfapply_closure_t;
typedef boolean_t (queue_pfapply_t)(queue_element_t, queue_pfapply_closure_t);

extern boolean_t queue_apply(queue_t q, queue_pfapply_t pf, queue_pfapply_closure_t cl);


/* THESE FUNCTIONS ARE NOT IMPLEMENTED */

/*
 * Reverses the elements on the queue in place.
 */

extern void queue_reverse(queue_t q);


/*
 * Sorts the elements in the queue in place.
 * Relies on provided compare function, which returns:
 *	-1:   e1 < e2
 *	 0:   e1 == e2
 *	 1:   e1 > e2
 */
typedef int (queue_pfcompare_t)(queue_element_t, queue_element_t);

extern void queue_sort(queue_t q, queue_pfcompare_t pf);


#endif //_QUEUE_H


