#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORD_LENGTH 65

struct Node {
	char  data[MAX_WORD_LENGTH];
	struct Node* left;
	struct Node* right;
};

struct Node* root; 

struct Node* buildTreeFromFile() {
	FILE *file = fopen("problem4.input1","r");
	if (file == NULL) {
		printf("Input file not found.\n");
		return NULL;
	}
	char word[MAX_WORD_LENGTH] ;

	while(fscanf(file, "%s", word) == 1) {
		// use these num to build a tree
		struct Node* newNode;
		struct Node* current;
		struct Node* parent;
		newNode = malloc(sizeof(struct Node));

		strcpy(newNode->data, word);
		current = NULL;
		parent  = NULL;

		if(root == NULL) {
			root = newNode;
			continue;
		}

		int compare;

		current = root;
		parent = root;
	
		while(current != NULL) {
			parent = current;
			compare = strcmp(newNode->data,current->data);
			if(compare == 0) {
				break;
			}
			if(compare < 0) {
				current = current->left;
			}
			else if(compare > 0) {
				current = current->right;
			}
		}
		compare = strcmp(newNode->data, parent->data);
		if(compare < 0) {
			parent->left = newNode;
		}
		else {
			parent->right = newNode;
		}

	}		

	fclose(file);
	return root; // return tree root node here.
}



void print_preorder(struct Node* tree) {
	// Implement this function.
	printf("%s ",tree->data);
		
	if(tree->left != NULL) {
		print_preorder(tree->left);
	}

	if(tree->right != NULL) {
		print_preorder(tree->right);
	}
}




void print_inorder(struct Node* tree) {
	// Implement this function.
}

void print_postorder(struct Node* tree) {

}	// Implement this function.

bool found_in_tree(char *word_to_search, struct Node* tree) {
		// Implement this function.
	return true;
}

void use_tree_searching(struct Node* tree) {
	FILE *file = fopen("problem4.input2","r");
	if (file == NULL) {
		printf("Input file not found.\n");
		return;
	}
	char word_to_search[MAX_WORD_LENGTH];
	while(fscanf(file, "%s", word_to_search) == 1) {
		if (found_in_tree(word_to_search, tree)) {
			printf("yes ");
		} else {
			printf("no ");
		}
	}
	fclose(file);
}

int main (int argc , char * argv []) {
	struct Node* tree = buildTreeFromFile();
	print_preorder(tree);
	printf("\n");
	print_inorder(tree);
	printf("\n");
	print_postorder(tree);
	printf("\n");
	use_tree_searching(tree);
	return 0;
}
