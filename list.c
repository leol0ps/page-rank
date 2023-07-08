#include "list.h"
List* create_list(char* name){
		    List* b = malloc(sizeof(List));
			cria_string(&(b->name),name);
			b->next = NULL;
			return b;
}

void insert(List* list, char* name ){
			if(!strcmp(list->name.c,name)){
					return;
			}
			if(list->next!=NULL){
					insert(list->next,name);
			}
			else{
				list->next = malloc(sizeof(List));
				list->next->next = NULL;
				cria_string(&list->next->name,name);
			}
}
void lowercase_string(String* a){
		if(a == NULL)
				return;
		for(char *p=a->c; *p; p++) *p=tolower(*p);
}
int empty_list(List* a){
		if(a == NULL)
				return 1;
		else
				return 0;
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
String* cria_string_with_malloc(char* name){
		String* a = malloc(sizeof(String));
		a->len = strlen(name);
		a->c = malloc((a->len+1)*sizeof(char));
		strcpy(a->c,name);
		return a;
}
void free_malloc_string(String* a){
		if(a == NULL)
				return;
		free(a->c);
		free(a);
}
void cria_string(String* a, char* name){
			a->len = strlen(name);

			a->c = malloc((a->len+1)*sizeof(char));
			//printf("len = %d, car = %s\n",a->len,name);
			strcpy(a->c,name);
			//strncpy(a->c,name,a->len);
			//a->c[a->len] = '\0';
}
void free_string(String* a){
			if(a == NULL)
								return;
				free(a->c);
}
