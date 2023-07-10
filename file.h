#ifndef FILE_H
#define FILE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tst.h"
#include "arb.h"
#include "list.h"
#include "pagerank.h"
void read_all(char* directory, TST** pages, TST** stopwords,PTST** ranks,int* count_pages, String** str_pages);
TST* read_stop_words(char* directory);




#endif
