#include "BST_TREE.h"
#include <stdio.h>

int main(){
	BST_TREE* tree;
	tree = create_bst();
	if( tree ) {
		printf( "Create tree Success!\n");
	}	
	
	if(BST_insert(tree,1)){
		printf("Insert Success!\n");
		printf("Tree count: %d\n", tree->count);

	}


	if(!BST_delete(tree,1))
		printf("failed on deleting 1\n");
	else
		printf("Success on deleting 1\n");
	return 0;

}
