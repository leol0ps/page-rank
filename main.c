#define _POSIX_C_SOURCE 200810L
#include "search.h"
#include "file.h"
#include "list.h"
#include "tst.h"
#include "pagerank.h"
#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <stdatomic.h>
int main(int argc,char** argv){
	String* aux[10];
	char* line = NULL;
	size_t len = 0;
	ssize_t read = 0;
	TST* stopwords = NULL;
	TST* palavras = NULL;
	PTST* ranks = NULL ;
	String* str_pages = NULL;
	int inutil =0;
	int count_pages = 0;
	int count_stdin_lines = 0;
	read_all(argv[1],&palavras,&stopwords,&ranks,&count_pages,&str_pages);
	calculate_pagerank(ranks,str_pages,count_pages);
	char* teste = "euVouAPIZAARIA";
	String* teste_lowercase = cria_string_with_malloc(teste);
	lowercase_string(teste_lowercase);
	//printf("%s,%s \n",teste,teste_lowercase->c);
	aux[1] = cria_string_with_malloc("cachorro");
	aux[2] = cria_string_with_malloc("leao");
	aux[3] = cria_string_with_malloc("yours");
	aux[4] = cria_string_with_malloc("about");
	aux[5] = cria_string_with_malloc("above");
	aux[6] = cria_string_with_malloc("against");
	aux[7] = cria_string_with_malloc("againstmy");
	aux[8] = cria_string_with_malloc("thing");
	aux[9] = cria_string_with_malloc("naosei");
	aux[0] = cria_string_with_malloc("chapter");
	for(int i = 8; i < 10 ; i ++){

		List* result = TST_search(stopwords, aux[i]);
		//print_list(result);
	}
	List* search = TST_search(palavras,aux[0]);
	//print_list(search);
	free_malloc_string(teste_lowercase);
	for(int i = 0 ; i < 10 ; i++){

		free_malloc_string(aux[i]);
	}
	while((read = getline(&line,&len,stdin))!= -1){
		char* print_search = malloc((len+1)*sizeof(char));
		strcpy(print_search,line);
		List* result_search = search_eng(palavras,stopwords,line);
		//print_list(result_search);
		List* ca = result_search;
		/*while(ca!=NULL){
			printf("%lf\n",get_pagerank(ranks,&ca->name,&inutil));
			ca = ca->next;
		}*/
		printf("search:%s",print_search);
		print_output( ca,ranks);
		int words_line = count_words(line);
		count_stdin_lines++;
		free_list(result_search);
		free(print_search);
		print_search = NULL;
		//printf("%d words in line %d\n",words_line,count_stdin_lines);
	}
	free(line);
	free_PTST(ranks);
	free_tst(palavras);
	free_tst(stopwords);
	for(int i = 0; i < count_pages;i++){
			free_string(&str_pages[i]);
	}
	free(str_pages);

	return 0;
}
