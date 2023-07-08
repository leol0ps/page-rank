#include "search.h"
#include "tst.h"

int is_stepword(TST* stp,String* a){
	List* test = TST_search(stp,a);
	if(empty_list(test)){
			return 0;
	}
	else {
			return 1;
	}
}

List* search_eng(TST* palavras, TST* stp, char* search_words){
	List* result;
	String* aux;
	char* word = NULL;
	word = strtok(search_words," \t\n");
	while(word!=NULL){
			aux = cria_string_with_malloc(word);
			lowercase_string(aux);
			int is_stepword(TST* stp,String* a){
			List* test = TST_search(stp,a);
			if(empty_list(test)){
				return 0;
			}
			else {
				return 1;
																		}
			}
			TST_search(palavras,aux);
	}
	return result;
}
