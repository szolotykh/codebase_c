#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

int main(){
	Tnode * mytree; // Pointer to tree
	printf("Binary search tree\n");
	// Create first node of tree
	mytree = create_tnode("hhh");
	// Add nodes to the thee
	add_tnode(mytree, "xxx");
	add_tnode(mytree, "aaa");
	add_tnode(mytree, "eee");
	add_tnode(mytree, "bbb");
	add_tnode(mytree, "yyy");
	add_tnode(mytree, "ccc");
	add_tnode(mytree, "zzz");
	// Print tree
	print_tnode(mytree);
	// Free whole tree
	free_tnode(mytree);
	return 1;
}
