#ifndef TST_H
#define TST_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
void free_string(String* a);
void cria_string(String* a, char* name);
typedef struct node TST;
struct node {
		List* val;
		unsigned char c;
		TST *l, *m, *r;
		int frequency;
};
List* TST_search(TST* t, String* key);
int frequency_return(TST* t, String* key);
TST* TST_insert(TST* t, String* key , char* val);
void free_tst(TST* a);
TST* TST_insert_full_list(TST* a, List* list);
#endif
