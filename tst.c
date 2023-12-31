#include "tst.h"
TST* create_node(){
	TST* a = malloc(sizeof(TST));
	a->val = NULL;
	a->c = 'l';
	a->frequency= 0;
	a->m = NULL;
	a->l = NULL;
	a->r = NULL;
	return a;
}
TST* rec_insert(TST* t, String* key, char* val, int d) {
		unsigned char c = key->c[d];
		if (t == NULL) { t = create_node(); t->c = c;}
		if (c < t->c) { t->l = rec_insert(t->l, key, val, d); }
		else if (c > t->c) { t->r = rec_insert(t->r, key, val, d); }
		else if (d < key->len - 1) {
				t->m = rec_insert(t->m, key, val, d+1);
		} else {
			if(t->val!=NULL)   
				insert(t->val,val);
			else
				t->val =  create_list(val);
		}
		t->frequency++;
		return t;
}
TST* TST_insert(TST* t, String* key , char* val) {
		if(t==NULL)
				t = create_node();
		return rec_insert(t, key, val, 0);
}

TST* rec_search(TST* t, String* key, int d) {
		if (t == NULL) { return NULL; }
		unsigned char c = key->c[d];
		if (c < t->c) { return rec_search(t->l, key, d); }
		else if (c > t->c) { return rec_search(t->r, key, d); }
		else if (d < key->len - 1) {
				return rec_search(t->m, key, d+1);
		} else { return t; }
}

List* TST_search(TST* t, String* key) {

		t = rec_search(t, key, 0);
		if (t == NULL) { return NULL; }
		else { return t->val; }
}

void free_tst(TST* a){
	if(a == NULL)
			return;
	else{
	free_list(a->val);	
	free_tst(a->l);
	free_tst(a->m);
	free_tst(a->r);
	free(a);
	}	
}
TST* TST_insert_full_list(TST* a, List* list){
	List* p = list;
	while(!empty_list(p)){
		//printf("%s\n",p->name.c);
		a = TST_insert(a,&p->name," ");	
		p = p->next;
	}
	return a;
}

TST* rec_freq_search(TST* t, String* key, int d) {
		if (t == NULL) { return NULL; }
		unsigned char c = key->c[d];
		if (c < t->c) { return rec_search(t->l, key, d); }
		else if (c > t->c) { return rec_search(t->r, key, d); }
		else if (d < key->len - 1) {
				return rec_search(t->m, key, d+1);
		} else { return t; }
}
int frequency_return(TST* t, String* key){ // insert in the  list keys with exact n inserts
	if(t==NULL)
			return 0;	
	t = rec_freq_search(t, key, 0);
	if (t == NULL) { return 0; }
	else { return t->frequency; }
}

