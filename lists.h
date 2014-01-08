#include "lambda.h"

typedef struct list list;
list empty;
list* init (int, list*);
list* last (list*);
list* droplast (list*);
list* con (list*, list*);
list* single (int);
list* nth (int, list*);
size_t length (list*);
void pl (list*);
list* range (int, int);
list* map (int (*f) (int), list*);
list* filter (_Bool (*p) (int), list*);
int foldl (int (*f) (int, int), int, list*);
unsigned long fac (int);
int sum (list*);