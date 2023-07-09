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
		lowercase_string(aux);
		arvore = TST_insert(arvore,aux,"stopwords");
		free_malloc_string(aux);
		aux = NULL;
	}
	free(line);
	fclose(input);
	return arvore;

}
int is_stepword(TST* stp,String* a){
		List* test = TST_search(stp,a);
		if(empty_list(test)){
				return 0;
		}
		else {
			return 1;
		}
}
TST* read_one_page(TST* arvore,TST* stp,char* directory,char* page){
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
			word = strtok(line," \t\n");
			while(word != NULL){
				aux = cria_string_with_malloc(word);
				lowercase_string(aux);
				//printf("%s\n", aux->c);
				if(!is_stepword(stp,aux)){	
					arvore = TST_insert(arvore,aux,page);
				}
				free_malloc_string(aux);
				aux = NULL;
				word = strtok(NULL," \t\n");
		}
	}
	free(line);
	fclose(input);
	return arvore;

}
TST* read_pages(char* directory,TST* stp){
	TST* arvore = NULL;
	char* page_name = NULL;
	char* line= NULL;
	size_t len = 0;
	ssize_t read = 0;
	FILE* input = NULL;
	char path[300] = "";
	char pages_path[306] = "";
	strcat(path,directory);
	strcat(path,"/index.txt");
	input = fopen(path,"r");
	if(input == NULL){
			printf("sem arquivo index\n");
			return NULL;
	}

	strcat(pages_path,directory);
	strcat(pages_path,"/pages");
	while((read = getline(&line,&len,input))!= -1){
		page_name = strtok(line, "\n");
		arvore = read_one_page(arvore,stp,pages_path,page_name);	
	}
	fclose(input);
	free(line);
	return arvore;
}
PTST* read_graph(char* directory){
	char path[300] = "";
	FILE* input;
	int count = 0;
	int i = 0;
	int link_count = 0;
	char** links = NULL;
	char* line = NULL;
	char* word = NULL;
	char* page_name = NULL;
	size_t len = 0;
	ssize_t read = 0;
	String* aux =  NULL;
	strcat(path,directory);
	strcat(path,"/graph.txt");
	input = fopen(path,"r");
	PTST* graph = NULL;
	if(input == NULL){
			printf("graph.txt nao encontrado");
			return NULL;
	}	
	while((read = getline(&line,&len,input)) != -1 ){
		word = strtok(line," \t\n");
		while(word!= NULL){
			if(count == 0){
				page_name = malloc((strlen(word)+1)*sizeof(char));
				strcpy(page_name,word);
				count++;
			}
			else if(count == 1){
				link_count = atoi(word);
				links = malloc(link_count*sizeof(char*));
				count++;	
			}
			else{
				int size = strlen(word) + 1;
				char* link_name = malloc(size*sizeof(char));
				strcpy(link_name,word);
				links[i] = link_name;
				i++;
				link_name = NULL;
			}
			
			
			word = strtok(NULL," \t\n");
		}
		printf("%d  ",link_count);
		printf("%s\n",page_name);
		Dat* data = create_dat(links,0, link_count);
		aux = cria_string_with_malloc(page_name);
		lowercase_string(aux);
		graph = PTST_insert(graph,aux,data);
		free(page_name);
		free_malloc_string(aux);
		aux = NULL;
		page_name = NULL;
		links = NULL;
		count = 0;
		i = 0;		
	}
	fclose(input);
	free(line);
	return graph;
}
void read_all(char* directory, TST** pages, TST** stopwords,PTST** ranks){
	*ranks  = read_graph(directory);
	*stopwords = read_stop_words(directory);
	*pages = read_pages(directory,*stopwords);
	return;
}

