#include <stdlib.h>
#include "refcount.h"
#include "map.h"

#define MAP_SIZE 997

struct map_entry {
  int   key;
  void* value;   // ... reference counted
};

struct map_entry map[MAP_SIZE];

int hash (int key) {
  return key % MAP_SIZE;
}

///////////////////
/// Public Interface (see map.h)

void map_put (int key, void* value) {
  int h = hash (key);
  for (int i=0; i < MAP_SIZE; i++) {
    struct map_entry* e = map + ((h+i) % MAP_SIZE);
    if (e->key == key) {
      // update existing entry
      rc_free_ref (e->value);        // ... release map's reference on old value
      rc_keep_ref (value);           // ... map holds reference to new value
      e->value = value;
      break;
    } else if (e->key == 0) {
      // add new entry
      rc_keep_ref (value);           // .. map holds reference to new value
      e->key   = key;
      e->value = value;
      break;
    }
  }
}

void* map_get (int key) {
  int h = hash (key);
  for (int i=0; i < MAP_SIZE; i++) {
    struct map_entry* e = map + ((h+i) % MAP_SIZE);
    if (e->key == key) {
      rc_keep_ref (e->value);        // ... caller will also hold reference to value
      return e->value;
    } else if (e->key == 0)
      return NULL;
  }
  return NULL;
}

void map_delete_all() {
  for (int i=0; i < MAP_SIZE; i++)
    if (map[i].key) {
      rc_free_ref (map[i].value);    // ... release map's reference to value
      map[i].key   = 0;
      map[i].value = NULL;
    }
}
