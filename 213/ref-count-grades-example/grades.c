#include <stdlib.h>
#include <stdio.h>
#include "refcount.h"
#include "intlist.h"
#include "map.h"

void add_student (int sid, int* marks, int num_marks) {
  int* marks_list = intlist_create (marks, num_marks);    // create list for marks ... ref count is 1
  map_put    (sid, marks_list);                           // add to map            ... ref count is 2 (us and map)
  rc_free_ref (marks_list);                               // release our reference ... ref count is 1 (just map)
}

void add_mark (int sid, int mark) {
  int* old_marks = map_get (sid);                         // get student's marks   ... ref count is 2 (us and map)
  if (old_marks != NULL) {
    int* new_marks = intlist_append (old_marks, mark);    // create new marks      ... ref count is 1
    map_put (sid, new_marks);                             // update map            ... old_marks ref count is 1, new_marks ref count is 2
    int c, old_t=0, new_t=0;
    for (c=0; old_marks[c] != -1; c++)
      old_t += old_marks[c];
    for (c=0; new_marks[c] != -1; c++)
      new_t += new_marks[c];
    printf ("Average mark for student %d changed from %d to %d\n", sid, old_t/(c-1), new_t/c);
    rc_free_ref (old_marks);                              // release old_marks ref ... ref count is 0 and object is FREEd
    rc_free_ref (new_marks);                              // release new_marks ref ... ref count is 1 (map)
  }
}

int main (int argc, char** argv) {
  add_student (1000, (int[4]) {90, 80, 70, 60}, 4);
  add_student (2000, (int[4]) {70, 70, 80, 90}, 4);
  add_mark    (1000, 50);
  add_mark    (2000, 100);
  map_delete_all();                                       // delete map            ... every marks list ref count decremented
}                                                         //                       ... all were 1 and so all are now 0 and all are FREEd