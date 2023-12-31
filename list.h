#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct str{
		char* c;
		int len;
						
}String;
void lowercase_string(String* a);
void free_string(String* a);
void free_malloc_string(String* a);
String* cria_string_with_malloc(char* name);
void cria_string(String* a, char* name);
typedef struct list{
			String name;
		   	struct list* next;
}List;
List* remove_first(List* list);
List* create_list(char* name);
void insert(List* list, char* name);
void free_list(List* a);
void print_list(List* a);
int empty_list(List* a);
#endif
