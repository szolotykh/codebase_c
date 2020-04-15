/** 
* Struct to define a tree node
*/
struct tnode {
	char * value; // Pointer to c string
	struct tnode * left; // Pointer to left child
	struct tnode * right;	// Pointer to right child
};

typedef struct tnode Tnode;

#define STRING_MAX_SIZE 20

/** Create node
* @param value value of the tree
* @return pointer on new node
*/
Tnode *create_tnode( char* value);

/** Add node to the tree
* @param current_tnode current node of the tree of NULL
* @param value value of the tree
* @return pointer on new node
*/
Tnode *add_tnode(Tnode *current_tnode, char* value);

/** print tree of subtree
* @param current_tnode current node
*/
void print_tnode(Tnode *current_tnode);

/** Free tree or subtree memory
* @param current_tnode current node
*/
void free_tnode(Tnode * current_tnode);

/** Rand c string
* @return pointer to new random string
*/
char * randstr();
