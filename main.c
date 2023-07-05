#include "file.h"
#include "TST.h"
int main(int argc,char** argv){
	TST* stopwords = NULL;
	TST* palavras = NULL;
	read_all(argv[1],palavras,stopwords);


	return 0;
}
