#define _POSIX_C_SOURCE 200810L
#include "file.h"




TST* read_stop_words(char* directory){
	
	FILE* input = NULL;
	char path[300] = "\n";
	strcat(path,directory);
	strcat(path,"stopwords.txt");

	

	input = fopen(path,"r");
	if(input == NULL){
		printf("arquivo nao encontrado\n");
		return NULL;
	}


}

void read_all(char* directory, TST* pages, TST* stopwords){

	stopwords = read_stop_words(directory);
	return;
}

