#include "search.h"

int is_stepword_s(TST* stp,String* a){
	List* test = TST_search(stp,a);
	if(empty_list(test)){
			return 0;
	}
	else {
			return 1;
	}
}
List* list_intersection(List** a, int n){
	TST* result_tree = NULL;
	List* complete  = NULL;
	for(int i = 0; i < n; i++){
			result_tree = TST_insert_full_list(result_tree,a[i]);
	}
	for(int i = 0; i < n; i++){
		List* p = a[i];
		while(p!=NULL){
			if(frequency_return(result_tree,&p->name) == n){
				if(complete == NULL){
						complete = create_list(p->name.c);
				}
				else{
					insert(complete,p->name.c);
				}
			}
		}
	}
	free_tst(result_tree);
	return complete;
}
List* search_eng(TST* palavras, TST* stp, char* search_words){
	List* result = NULL;
	String* aux;
	char* word = NULL;
	int number_of_stepwords = 0;
	int number_of_searches = count_words(search_words);
	int word_count = 0;
	List** search_results = malloc(number_of_searches*sizeof(List*));
	word = strtok(search_words," \t\n");
	while(word!=NULL){
			aux = cria_string_with_malloc(word);
			lowercase_string(aux);
			if(!is_stepword_s(stp,aux)){
				search_results[word_count] = TST_search(palavras,aux);
				word_count++; 
			}
			else{
				number_of_stepwords++;	
			}
				 
	}
	result = list_intersection(search_results,word_count);
	return result;
}
int count_words(char* line){
		int count = 0;
		char* aux = strtok(line, " \t\n");
		while(aux!=NULL){
			count++;
			aux = strtok(NULL," \t\n");
		}
	return count;
}
