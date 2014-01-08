#include "lists.h"

typedef struct list {
	int head;
	struct list *tail;
} list;

list empty = {0, NULL};

list* init (int h, list *t) {
	list *L = (list*) malloc (sizeof (list));
	L-> tail = t;
	L-> head = h;

	return L;
}

list* last (list *L) {
	if (L-> tail == &empty) return L;
	else return last (L-> tail);
}

list* droplast (list *L) {
	if (L-> tail == &empty) return &empty;
	else return con (single (L-> head), droplast (L-> tail));
}

list* con (list *La, list *Lb) {
	list *L = init (La-> head, La-> tail);
	last(L)-> tail = Lb;
	return L;
}

list* single (int h) {
	return init (h, &empty);
}

list* nth (int n, list *L) {
	list* rec (list *L, int i) {
		if (i == n) return L;
		else return rec (L-> tail, i+1);
	} return rec (L, 0);
}

size_t length (list *L) {
	if (L != &empty) return 1 + length (L-> tail);
	else return 0;
}

list* reverse (list *L) {
	list* rec (list *L, list *acc) {
		if (L != &empty) return rec (L-> tail, con (single (L-> head), acc));
		else return acc;
	} return rec (L, &empty);
}

void pl (list *L) {
	if (L != &empty) {
		printf ("[");
		while (L-> tail != &empty) {
			printf ("%d, ", L-> head);
			L = L-> tail;
		} printf ("%d]", L-> head);
	} else printf ("[]");
}

list* range (int a, int b) {
	if (a<=b) return init (a, range (a+1, b));
	else return &empty;
}

list* map (int (*f) (int), list* L) {
	if (L != &empty) return con (
		single (f (L-> head))
		, map (f, L-> tail)
	); else return L;
}

list* filter (_Bool (*p) (int), list *L) {
	if (L != &empty && p (L-> head)) return con (single (L-> head), filter (p, L-> tail));
	else if (L != &empty && !p (L-> head)) return filter (p, L-> tail);
	else return L;
}

int foldl (int (*f) (int, int), int acc, list *L) {
	if (L != &empty) return foldl (f, f (acc, L-> head), L-> tail);
	else return acc;
}

unsigned long fac (int c) {return foldl (lambda (int, (int a, int b), {return a*b;}), 1, range (1,c));}
int sum (list *L) {return foldl (lambda (int, (int a, int b), {return a+b;}), 0, L);}