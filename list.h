#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
#include <stdio.h>
#include "tst.h"
typedef struct list{
			String name;
		   	struct list* next;
}List;
List* remove_first(List* list);
List* create_list(char* name);
void insert(List* list, char* name);
void free_list(List* a);
void print_list(List* a);
#endif
