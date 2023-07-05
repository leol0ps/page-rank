#include "list.h"
List* create_list(char* name){
		    List* b = malloc(sizeof(List));
			cria_string(&(b->name),name);
			b->next = NULL;
			return b;
}

void insert(List* list, char* name ){
			if(list->next!=NULL){
					insert(list->next,name);
			}
			else{
				list->next = malloc(sizeof(List));
				list->next->next = NULL;
				cria_string(&list->next->name,name);
			}
}

void free_list(List* a){
	 if(a == NULL)
			 return;
	 free_list(a->next);
	 free_string(&a->name);
	 free(a);
}

void print_list(List* a){
	if(a == NULL)
		return;
	printf("%s\n",a->name.c);
	print_list(a->next);

}

void cria_string(String* a, char* name){
			a->c = malloc(sizeof(strlen(name)+1));
				a->len = strlen(name);
}
void free_string(String* a){
			if(a == NULL)
								return;
				free(a->c);
}
