#define _POSIX_C_SOURCE 200810L
#include "file.h"




TST* read_stop_words(char* directory){
	char* line = NULL;
	String* aux = NULL;
	size_t len = 0;
	ssize_t read = 0;
	TST* arvore = NULL;
	FILE* input = NULL;
	char path[300] = "";
	char* word = NULL;
	strcat(path,directory);
	strcat(path,"/stopwords.txt");

	
	printf("%s\n", path);
	input = fopen(path,"r");
	if(input == NULL){
		printf("arquivo nao encontrado\n");
		return NULL;
	}
	while((read = getline(&line,&len,input))!= -1){
		word = strtok(line,"\n");
		aux = cria_string_with_malloc(word);
		printf("%s\n", aux->c);
		arvore = TST_insert(arvore,aux,"stopwords");
		free_malloc_string(aux);
		aux = NULL;
	}
	free(line);
	fclose(input);
	return arvore;

}

void read_all(char* directory, TST* pages, TST** stopwords){

	*stopwords = read_stop_words(directory);
	return;
}

