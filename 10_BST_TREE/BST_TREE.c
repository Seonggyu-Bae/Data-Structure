#include "BST_TREE.h"
#include <stdio.h>
#include <stdlib.h>

BST_TREE* create_bst(){
	BST_TREE* tree = (BST_TREE*)malloc(sizeof(BST_TREE));

	if( tree ) {
		tree -> root = NULL;
		tree -> count = 0;

		return tree;
	}
	return NULL;
}


bool BST_insert(BST_TREE* tree, int data) {
	T_NODE* newRoot;
	newRoot = add_bst(tree->root, data);
	
	if(newRoot == NULL)
		return false;
	else{
		tree->root = newRoot;
		(tree->count)++;
	}
	return true;
}

bool BST_delete(BST_TREE* tree, int data){
	bool success;
	T_NODE* new_root;
	new_root = delete_bst (tree->root ,data, &success);
	if(success){
		tree->root = new_root;
		tree->count--;
		if(tree->count==0)
			tree->root = NULL;
	}

	return success;
}

T_NODE* add_bst(T_NODE* root, int data){
	if( root== NULL ){
		T_NODE* newPtr = (T_NODE*)malloc(sizeof(T_NODE));

		newPtr->left = NULL;
		newPtr->right = NULL;
		newPtr->data = data;

		return newPtr;
	}
	if( data< (root->data) ){
		root->left = add_bst(root->left, data);

		return root;
	}
	else{
		root->right = add_bst(root->right, data);
	
		return root;
	}
}

T_NODE* delete_bst (T_NODE* root, int data, bool* success){
	T_NODE* newRoot;
	T_NODE* deleted_node;
	T_NODE* search;

	if(root == NULL){
		*success = false;
		return NULL;
	}
	//traverse
	if(data<(root->data)) //exist at left somewhere
		root->left = delete_bst(root->left,data,success);
	else if(data>(root->data))// exist at right somewhere
		root->right = delete_bst(root->right, data ,success);
	else{// matched
		deleted_node = root;
		//case 1
		if(root->left == NULL){
			newRoot =root->right;
			free(deleted_node);
			*success = true;
			return newRoot;
		}
		else{
			//case 2
			if(root->right == NULL){
				newRoot= root->left;
				free(deleted_node);
				*success = true;
				return newRoot;
			}
			//case 3: I HAVE 2 Slaves
			else{
				search = root->left;

				while(search->right!=NULL)
					search=search->right;

				root->data = search->data; //promote to new boss position
				root->left = delete_bst(root->left,search->data,success);
			}
		}
		
	return root;
	}
}


T_NODE* search_bst (T_NODE* root, int search_data){
	if(root==NULL)
		return NULL;
	if(search_data<(root->data))
		return search_bst(root->left,search_data);
	else if(search_data>(root->data))
		return search_bst(root->left,search_data);
	else
		return root;
}


T_NODE* find_smallest_node (T_NODE* root){
	if(root->left==NULL)
		return root;
	else
		return find_smallest_node (root->left);
}


T_NODE* find_largest_node (T_NODE* root){
	if(root->right==NULL)
		return root;
	else
		return find_largest_node (root->right);
}

void traverse_preorder (T_NODE* root){
	if(root != NULL){
		
		int a[] = (root->data);
		printf("%d,",root->data);
		traverse_preorder(root->left);
		traverse_preorder(root->right);
	}
}

void traverse_inorder (T_NODE* root){
	if(root != NULL){
		traverse_inorder(root->left);
		printf("%d,",root->data);
		traverse_inorder(root->right);
	}
}

void traverse_postorder (T_NODE* root){
	if(root!=NULL){
		traverse_postorder(root->left);
		traverse_postorder(root->right);
		printf("%d,",root->data);
	}
}


BST_TREE* copy_tree (BST_TREE* tree){
	if(tree->count==0)
		return NULL;
	else{
		BST_TREE* newtree = create_bst();
		for(int i=0;i<(tree->count);i++){
			traverse_preorder(tree)
			int a = 
			add_bst((newtree->root),a);
			return newtree;
		}
	}
}

