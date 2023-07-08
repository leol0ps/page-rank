#ifndef FILE_H
#define FILE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tst.h"
#include "arb.h"
#include "list.h"
void read_all(char* directory, TST** pages, TST** stopwords);
TST* read_stop_words(char* directory);




#endif
