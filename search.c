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

List* search_eng(TST* palavras, TST* stp, char* search_words){
	List* result = NULL;
	String* aux;
	char* word = NULL;
	word = strtok(search_words," \t\n");
	while(word!=NULL){
			aux = cria_string_with_malloc(word);
			lowercase_string(aux);
			if(!is_stepword_s(stp,aux)){
				List* a = TST_search(palavras,aux);
			}
				 
	}
	return result;
}
