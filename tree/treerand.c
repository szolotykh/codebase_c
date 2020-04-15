#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

#define NUM_STRINGS 30

int main(){
	srand (time(NULL));

	Tnode * mytree;
	int ind;
	int *rstr;

	printf("Binary search tree\n");
	rstr = randstr();
	mytree = create_tnode(rstr);
	free(rstr);
	
	ind = 0;
	while(ind < NUM_STRINGS){
		rstr = randstr();
		add_tnode(mytree, rstr);
		free(rstr);
		ind++;
	}

	print_tnode(mytree);
	free_tnode(mytree);
	return 1;
}
