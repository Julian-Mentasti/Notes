#include <stdlib.h>
#include "refcount.h"
#include "intlist.h"


//////////////
/// Public Interface (see intlist.h)

int* intlist_create (int* v, int n) {
  int* l = rc_malloc ((n+1) * sizeof (*v));
  for (int i=0; i<n; i++)
    l[i] = v[i];
  l[n] = -1;
  return l;
}

int* intlist_append (int* l, int v) {
  int n = 0;
  while (l[n] != -1)
    n++;
  int *nl = rc_malloc ((n+2) * sizeof (*l));   // allocate with ref count ... ref count is 1
  for (int i=0; i<n; i++)
    nl[i] = l[i];
  nl[n]   = v;
  nl[n+1] = -1;
  return nl;
}


