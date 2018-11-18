#include "BST_TREE.h"
#include <stdio.h>

int main(){
	BST_TREE* tree;
	tree = create_bst();
	if( tree ) {
		printf( "Create tree Success!\n");
	}	
	for(int i=1;i<10;i++){	
		if(BST_insert(tree,i)){
			printf("Insert Success!\n");
			printf("Tree count: %d\n", tree->count);
		}	
}	
	traverse_inorder(tree->root);
	printf("\n");
	//traverse_inorder((copy_tree(tree))->root);
	
	

	return 0;

}
