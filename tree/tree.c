#include <stdlib.h>
#include <time.h>
#include "tree.h"

Tnode *create_tnode( char* value){
	Tnode *new_tnode; // Holds pointer to new tnode
	new_tnode = (Tnode *) malloc(sizeof(Tnode));

	if (new_tnode == NULL) return NULL; // Error--unable to allocate.

	//Fill in the structure
	new_tnode->value = strdup(value);
	new_tnode->left = NULL;
	new_tnode->right = NULL;
	return new_tnode;
}


Tnode *add_tnode(Tnode *current_tnode, char* value){
	if(current_tnode == NULL)
		return create_tnode(value);
	

	if(strcmp(value, current_tnode->value) <= 0){
		//if value of new node LESS then value of current_tnode
		if(current_tnode->left == NULL){
			// if left child is NULL
			current_tnode->left = create_tnode(value);
			return current_tnode->left;
		}else{
			// pass node to left sub tree
			return add_tnode(current_tnode->left, value);
		}
	}else{
		//if value of new node GRADER then value of current_tnode
		if(current_tnode->right == NULL){
			// if left child is NULL
			current_tnode->right = create_tnode(value);
			return current_tnode->right;
		}else{
			// pass node to right subtree
			return add_tnode(current_tnode->right, value);
		}
	}
}

void print_tnode(Tnode *current_tnode){
	// Print left subtree
	if(current_tnode->left != NULL){
		print_tnode(current_tnode->left);
	}
	// Print current node
	printf("%s\n",current_tnode->value);
	// Print right subtree
	if(current_tnode->right != NULL){
		print_tnode(current_tnode->right);
	}
}

void free_tnode(Tnode * current_tnode){
	// Free left subtree
	if(current_tnode->left != NULL){
		free_tnode(current_tnode->left);
	}
	// Free right subtree
	if(current_tnode->right != NULL){
		free_tnode(current_tnode->right);
	}
	// Free current node
	free(current_tnode->value);
	free(current_tnode);
}

char * randstr(){
	int length = (rand() % STRING_MAX_SIZE) + 1; // from 1 to STRING_MAX_SIZE
	int ind = 0;
	char* str = (char *) malloc(sizeof(char)*(length+1));
	while(ind < length){
		*(str+ind) = (char)(rand()%26+97);
		ind++;
	}
	*(str+length) = '\0'; // Terminate string
	return str;
}







