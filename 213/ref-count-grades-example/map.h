#ifndef __map_h__
#define __map_h__

/**
 * put (key, value) pair in hash map
 *
 * parameters:
 *    key     key (a number)
 *    value   value associated with key (reference-counted object)
 */
void map_put (int key, void* value);

/**
 * get value assoicated with specified key
 *
 * parameters:
 *    key   key to get
 *
 * return:
 *    value assoicated with key or NULL (reference counted; caller must call rc_free_ref())
 */
void* map_get (int key);

/**
 * delete all entries in map
 */
void map_delete_all();

#endif /*__map_h__*/