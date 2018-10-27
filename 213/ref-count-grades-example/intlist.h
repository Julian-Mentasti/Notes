#ifndef __intlist_h__
#define __intlist_h__

/**
 * create new reference-counted list containing specified integer values
 *
 * parameters:
 *    v   array of integers
 *    n   length of array
 * returns:
 *    pointer to list of integers terminated by the value -1 (referenced counted; caller must call rc_free_ref())
 *    for example intlist_create ((int[2]) {1,2,3}, 3) returns a new array of four integers: {1,2,3,-1}
 */
int* intlist_create (int* v, int n);

/**
 * create new list that contains all elements of given list plus an additional value
 *
 * parameters:
 *    l   original list
 *    v   value to append
 *
 * returns:
 *    new list (reference counted; caller must call rec_free_ref())
 */
int* intlist_append (int* l, int v);

#endif /*__intlist_h__*/