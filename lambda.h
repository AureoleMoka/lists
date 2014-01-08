#include <stdio.h>
#include <stdlib.h>

#define lambda(ret_type, args, body) 	\
	({									\
		ret_type f args					\
			body						\
		&f;								\
	})
