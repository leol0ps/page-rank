#Creditos: https://www.embarcados.com.br/introducao-ao-makefile/
# $< => o arquivo de prerequisito (.c)
# $@ => o arquivo otimizado/arquivo objeto (.o)
# $^ => os nomes de todos os prerequisitos separados por espacos
#
#
PROJ_NAME=trab2
C_SOURCE=$(wildcard *.c)
H_SOURCE=$(wildcard *.h)
OBJ=$(C_SOURCE:.c=.o)
CC=gcc
CC_FLAGS=-c         \
         -W         \
         -Wall      \
         -std=c11      \
         -pedantic    \
	 -lm         \
	 -O2

all: $(PROJ_NAME)
 
$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^ -lm
 
%.o: %.c %.h
	$(CC) -o $@ $< $(CC_FLAGS)
 
main.o: main.c $(H_SOURCE)
	$(CC) -o $@ $< $(CC_FLAGS)
 
clean:
	rm -rf *.o $(PROJ_NAME) *~
