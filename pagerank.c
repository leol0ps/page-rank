#include "pagerank.h"
#include "list.h"
#define ALPHA 0.85
#define E 10e-9
struct nodep{
	Dat content;
	unsigned char c;
	PTST *l, *m , *r;
};
PTST* create_nodep(){
	PTST* a = malloc(sizeof(PTST));
	create_dat(&a->content,0,0);
	a->c = 'l';
	a->l = NULL;
	a->m = NULL;
	a->r = NULL;
	return a;
}
void create_dat( Dat* newdat,double init_val, int link_count){
		newdat->lin = NULL;
		newdat->out_count = link_count;
		newdat->rank = init_val;
		newdat->old_rank = 0;
		newdat->in_count = 0;
}
void modify_rank(Dat* a, double val){
		a->rank = val;
		a->old_rank = val;
}
double get_dat_rank(Dat* a){
	return a->rank;
}
void free_dat(Dat* a){
		if(a == NULL)
				return;
		free_list(a->lin);
		free(a);
}

PTST* page_rec_insert(PTST* t, String* key, char* val, int d) {
		unsigned char c = key->c[d];
		if (t == NULL) { t = create_nodep(); t->c = c;}
		if (c < t->c) { t->l = page_rec_insert(t->l, key, val, d); }
		else if (c > t->c) { t->r = page_rec_insert(t->r, key, val, d); }
		else if (d < key->len - 1) {
				t->m = page_rec_insert(t->m, key, val, d+1);
		} else {
			if(t->content.lin == NULL){
					t->content.lin = create_list(val);
			}
			else{
				insert(t->content.lin,val);

			}
			t->content.in_count++;
		}
		return t;
}

PTST*  out_count_page_rec_insert(PTST* t, String* key, int val, int d) {
		unsigned char c = key->c[d];
		if (t == NULL) { t = create_nodep(); t->c = c;}
		if (c < t->c) { t->l = out_count_page_rec_insert(t->l, key, val, d); }
		else if (c > t->c) { t->r = out_count_page_rec_insert(t->r, key, val, d); }
		else if (d < key->len - 1) {
				t->m = out_count_page_rec_insert(t->m, key, val, d+1);
		} else {
			t->content.out_count = val;
		}
		return t;
}
PTST* PTST_insert(PTST *t, String* key, char* val){
	if(t == NULL)
			t = create_nodep();
	return page_rec_insert(t,key,val,0);
}
PTST* out_count_insert(PTST* t, String* key, int val){
	if(t == NULL)
		t = create_nodep();
	return out_count_page_rec_insert(t,key,val,0);
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
	else {return &t->content;}

}

void free_PTST(PTST *a){
	if( a == NULL)
			return;
	free_list(a->content.lin);
	free_PTST(a->l);
	free_PTST(a->m);
	free_PTST(a->r);
	free(a);
}

double get_pagerank(PTST* t, String* key, int* out_j){
	Dat* d = search_ptst(t,key);
	*out_j = d->out_count;
	return get_dat_rank(d);
}
void init_rank(PTST* a, String* key, double val){

	Dat* b = search_ptst(a,key);
	modify_rank(b,val);
}
void inicializa_ranks(PTST* a, String* pages, int size){
		double init = (1.0-ALPHA)/(double)size;
		for(int i = 0; i < size; i++){
			init_rank(a,&pages[i],init);
		}
}
void pr_update(PTST* a, String* key,int size){
		Dat* b = search_ptst(a,key);
		double aux = 0;
		Dat* s = NULL;
		double somatorio = 0;
		List* p = b->lin;
		while(p != NULL){
			s = search_ptst(a,&p->name);
			somatorio += s->old_rank/(double)s->out_count;	
			p = p->next;
		}

		aux = b->rank;
		if(b->out_count != 0){
			b->rank = (1.0-ALPHA)/(double)size + ALPHA*somatorio;	
		}
		else{
			b->rank = (1.0-ALPHA)/(double)size + ALPHA*b->old_rank + ALPHA*somatorio;
		}
		b->old_rank = aux;
}
void update_ranks(PTST* a, String* pages, int size){
	for(int i = 0; i < size; i++){
			pr_update(a,&pages[i],size);
	}	
}
double sum_pr(PTST* a, String* pages,int size){
	double sum = 0;
	for(int i = 0 ; i < size; i++ ){
			Dat* x = search_ptst(a,&pages[i]);
		   	sum += x->rank - x->old_rank;
			//printf("sum %lf\n ",sum);	
	}
	return sum;
}
void calculate_pagerank(PTST* a, String* pages, int size){
	inicializa_ranks(a,pages,size);
	//printf("%lf\n", E);
	double constant = 1.0/(double)size;
	double erro = 1000;
	double novo = INFINITY;
	while(erro > E){
		update_ranks(a,pages,size);
		novo = sum_pr(a,pages,size);
		erro = constant*fabs(novo);
	//	printf("%lf\n", erro);
	}	
	
}
