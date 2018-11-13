#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "list.h"
#include <string.h>

void stringNum(element_t* output_elem, element_t input_elem) {
	char* input = (char*) input_elem;
	intptr_t* output = (intptr_t*) output_elem;
	char** input_ptr = &input;
	*output = strtol(input, input_ptr, 10);
	if (*input_ptr != NULL && *output == 0)
		*output = -1;
}

void reset(element_t* rElem, element_t pElem, element_t sElem) {
	char* cElm = pElem;
	intptr_t bElm = (intptr_t) sElem;
	char** tElem = (char**) rElem;
	if (bElm < 0)
		*tElem = cElm;
	else
		*tElem = 0;
}

int positive(element_t pElem) {
	intptr_t temp = (intptr_t) pElem;
	if (temp != -1)
		return 1;
	else 
		return 0;
}

int checkNull (element_t pElem) {
	char* temp = pElem;
	if (temp != NULL)
		return 1;
	else
		return 0;
}

void truncString(element_t* rElem, element_t pElem, element_t sElem) {
	char* charA = pElem;
	intptr_t temp = (intptr_t) sElem;
	char** tElem = (char**) rElem;
	*tElem = strdup(charA);
	if (strlen(*tElem) > temp) {
		for (int i = 0; i < strlen(*tElem); i++) {
			if (i == temp) {
				(*tElem)[i] = '\0';
				return;
			}
		}
	}
}

int maxVal(struct list *l) {
	intptr_t max = (intptr_t)list_get(l, 0);
	for (int i = 0; i < list_len(l); i++) {
		intptr_t temp = (intptr_t)list_get(l, i);
		if (temp > max) {
			max = temp;
		}
	}
	return max;
}

void printString (element_t element) {
  char* element_pointer = element;
  printf ("%s\n", element_pointer);
}

void printNum (element_t element) {
  intptr_t element_pointer = (intptr_t) element;
  printf ("%ld\n", element_pointer);
}

int main(int argc, char** argv) {
	
	struct list* l0 = list_create();
	for (int i = 1; i < argc; i++)
		list_append(l0, argv[i]);
	
	struct list* l1 = list_create();
	list_map1(stringNum, l1, l0);
	
	struct list* l2 = list_create();
	list_map2(reset, l2, l0, l1);
	
	struct list* l3 = list_create();
	list_filter(positive, l3, l1);

	struct list* l4 = list_create();
	list_filter(checkNull, l4, l2);
	
	struct list* l5 = list_create();
	list_map2(truncString, l5, l4, l3);
	list_foreach(printString, l5);
	list_foreach(free, l5);
	
	int max = maxVal(l1);
	printf("%ld\n", max);
	
	list_destroy(l0);
	list_destroy(l1);
	list_destroy(l2);
	list_destroy(l3);
	list_destroy(l4);
	list_destroy(l5);
}