#ifndef TST_H
#define TST_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
typedef struct str{
	char* c;
	int len;
		
}String;
void free_string(String* a);
void cria_string(String* a, char* name);
typedef struct node TST;
struct node {
		List* val;
		unsigned char c;
		TST *l, *m, *r;
};
List* TST_search(TST* t, String* key);

TST* TST_insert(TST* t, String* key , List* val);
void free_tst(TST* a);

#endif
