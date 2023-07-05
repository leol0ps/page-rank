#include "tst.h"

TST* rec_insert(TST* t, String* key, Value val, int d) {
		unsigned char c = key->c[d];
		if (t == NULL) { t = create_node(); t->c = c;}
		if (c < t->c) { t->l = rec_insert(t->l, key, val, d); }
		else if (c > t->c) { t->r = rec_insert(t->r, key, val, d); }
		else if (d < key->len - 1) {
				t->m = rec_insert(t->m, key, val, d+1);
		} else { t->val = val; }
		return t;
}
TST* TST_insert(TST* t, String* key , Value val) {
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
	free_list(val);	
	free_tst(a->l);
	free_tst(a->m);
	free_tst(a->r);
	
}

