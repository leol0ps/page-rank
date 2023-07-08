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
		//printf("%s\n", aux->c);
		arvore = TST_insert(arvore,aux,"stopwords");
		free_malloc_string(aux);
		aux = NULL;
	}
	free(line);
	fclose(input);
	return arvore;

}
TST* read_one_page(TST* arvore,char* directory,char* page){
	char path[300] = "";
	FILE* input;
	char* line = NULL;
	char* word = NULL;
	size_t len = 0;
	ssize_t read = 0;
	String* aux =  NULL;
	strcat(path,directory);
	strcat(path,"/");
	strcat(path,page);
	input = fopen(path,"r");
	if(input == NULL){
			printf("erro lendo page %s\n",page);
			return arvore; 
	}

	while((read = getline(&line,&len,input))!= -1){
		word = strtok(line,"\n");
		aux = cria_string_with_malloc(word);
		lowercase_string(aux);
		//printf("%s\n", aux->c);
		arvore = TST_insert(arvore,aux,page);
		free_malloc_string(aux);
		aux = NULL;
	}
	free(line);
	fclose(input);
	return arvore;

}
TST* read_pages(char* directory){
	TST* arvore;
	char* page_name = NULL;
	char* line= NULL;
	size_t len = 0;
	ssize_t read = 0;
	FILE* input = NULL;
	FILE* page = NULL;
	char path[300] = "";
	strcat(path,directory);
	strcat(path,"/index.txt");
	input = fopen(path,"r");
	if(input == NULL){
			printf("sem arquivo index\n");
			return NULL;
	}
	while((read = getline(&line,&len,input))!= -1){
		page_name = strtok(line, "\n");
		arvore = read_one_page(arvore,directory,page_name);	
	}
	return arvore;
}

void read_all(char* directory, TST* pages, TST** stopwords){

	*stopwords = read_stop_words(directory);
	return;
}

