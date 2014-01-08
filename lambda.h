#include <stdio.h>
#include <stdlib.h>

// This code isn't written by me, i saw it on Superuser
// this is awesome. It defines a function inline, by using
// the lambda function. For instance:
// lambda (int, (int a), {return a*2;}) defines the function:

/*
int anonymous_func (int a) {
	return a*2;
}
*/

#define lambda(ret_type, args, body) 	\
	({									\
		ret_type f args					\
			body						\
		&f;								\
	})
