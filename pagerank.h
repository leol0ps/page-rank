#ifndef PAGERANK_H
#define PAGERANK_H
#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct data{
		char** links;
		int link_count;
		double rank;
}Dat;

typedef struct nodep PTST;
double get_pagerank(PTST* t,String* key);
double get_dat_rank(Dat *a);
void modify_rank(Dat* a, double val);
Dat* create_dat(char** links, double init_val, int link_count);
void free_dat(Dat* a);
PTST* PTST_insert(PTST* t, String* key , Dat* val);
Dat* search_ptst(PTST* t, String* key);
void free_PTST(PTST* a);
#endif
