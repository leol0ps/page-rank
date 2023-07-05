#ifndef FILE_H
#define FILE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arb.h"
void read_all(char* directory, Arb* pages, Arb* stopwords);
Arb* read_stop_words(char* directory);




#endif
