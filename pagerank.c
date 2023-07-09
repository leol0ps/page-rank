#include "pagerank.h"

struct nodep{
	Dat* content;
	unsigned char c;
	PTST *l, *m , *r;
};
PTST* create_nodep(){
	PTST* a = malloc(sizeof(PTST));
	a->content = NULL;
	a->c = 'l';
	a->l = NULL;
	a->m = NULL;
	a->r = NULL;
	return a;
}
Dat* create_dat(char** links, double init_val, int link_count){
		Dat* newdat = malloc(sizeof(Dat));
		newdat->links = links;
		newdat->link_count = link_count;
		newdat->rank = init_val;
		return newdat;
}
void modify_rank(Dat* a, double val){
		a->rank = val;
}
double get_dat_rank(Dat* a){
	return a->rank;
}
void free_dat(Dat* a){
		if(a == NULL)
				return;
		for(int i = 0; i < a->link_count; i++){
				free(a->links[i]);
		}
		free(a->links);
		free(a);
}

PTST* page_rec_insert(PTST* t, String* key, Dat* val, int d) {
		unsigned char c = key->c[d];
		if (t == NULL) { t = create_nodep(); t->c = c;}
		if (c < t->c) { t->l = page_rec_insert(t->l, key, val, d); }
		else if (c > t->c) { t->r = page_rec_insert(t->r, key, val, d); }
		else if (d < key->len - 1) {
				t->m = page_rec_insert(t->m, key, val, d+1);
		} else {
			t->content =  val;
		}
		return t;
}
PTST* PTST_insert(PTST *t, String* key, Dat* val){
	if(t == NULL)
			t = create_nodep();
	return page_rec_insert(t,key,val,0);
}
PTST* page_rec_search(PTST* t, String* key, int d){
  if (t == NULL) {
    return NULL;
  }
  unsigned char c = key -> c[d];
  if (c < t -> c) {
    return page_rec_search(t -> l, key, d);
  } else if (c > t -> c) {
    return page_rec_search(t -> r, key, d);
  } else if (d < key -> len - 1) {
    return page_rec_search(t -> m, key, d + 1);
  } else {
    return t;
  }
}

Dat* search_ptst(PTST *t, String* key){
	t = page_rec_search(t,key,0);
	if(t == NULL){ return NULL;}
	else {return t->content;}

}

void free_PTST(PTST *a){
	if( a == NULL)
			return;
	free_dat(a->content);
	free_PTST(a->l);
	free_PTST(a->m);
	free_PTST(a->r);
	free(a);
}

double get_pagerank(PTST* t, String* key){
	Dat* d = search_ptst(t,key);
	return get_dat_rank(d);
}

