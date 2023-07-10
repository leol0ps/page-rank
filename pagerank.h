#ifndef PAGERANK_H
#define PAGERANK_H
#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "list.h"


typedef struct data{
		List* lin;
		int in_count;
		int out_count;
		double rank;
		double old_rank;
}Dat;

typedef struct nodep PTST;
double get_pagerank(PTST* t,String* key, int* out_j);
double get_dat_rank(Dat *a);
void modify_rank(Dat* a, double val);
void create_dat(Dat* newdata, double init_val, int link_count);
void free_dat(Dat* a);
PTST* PTST_insert(PTST* t, String* key , char* val);
PTST* out_count_insert(PTST* t, String* key, int val);
Dat* search_ptst(PTST* t, String* key);
void free_PTST(PTST* a);
void calculate_pagerank(PTST* a, String* pages, int size);
#endif
