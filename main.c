#include "file.h"
#include "list.h"
#include "tst.h"
#include <stdatomic.h>
int main(int argc,char** argv){
	String* aux[10];
	TST* stopwords = NULL;
	TST* palavras = NULL;
	read_all(argv[1],&palavras,&stopwords);
	char* teste = "euVouAPIZAARIA";
	String* teste_lowercase = cria_string_with_malloc(teste);
	lowercase_string(teste_lowercase);
	printf("%s,%s \n",teste,teste_lowercase->c);
	aux[1] = cria_string_with_malloc("cachorro");
	aux[2] = cria_string_with_malloc("leao");
	aux[3] = cria_string_with_malloc("yours");
	aux[4] = cria_string_with_malloc("about");
	aux[5] = cria_string_with_malloc("above");
	aux[6] = cria_string_with_malloc("against");
	aux[7] = cria_string_with_malloc("againstmy");
	aux[8] = cria_string_with_malloc("aboutfk");
	aux[9] = cria_string_with_malloc("naosei");
	aux[0] = cria_string_with_malloc("chapter");
	for(int i = 0; i < 10 ; i ++){

		List* result = TST_search(stopwords, aux[i]);
		print_list(result);
	}
	List* search = TST_search(palavras,aux[0]);
	print_list(search);
	free_malloc_string(teste_lowercase);
	for(int i = 0 ; i < 10 ; i++){

		free_malloc_string(aux[i]);
	}
	free_tst(palavras);
	free_tst(stopwords);

	return 0;
}
