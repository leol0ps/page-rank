#ifndef ARB_H
#define ARB_H

typedef struct arb Arb;
Arb* new_arb(char* data);
void insert_arb(char* data, Arb* root);
char*  get_data(Arb* a);



#endif
