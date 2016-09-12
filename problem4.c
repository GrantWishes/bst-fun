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

		if(root == NULL) {
			root = newNode;
			printf("Root created! New node is %s\n",root->data); 
			continue;
		}

		int compare;

		current = root;
		parent = root;
	

		// TO DO
		// FIGURE OUT A CONDITION THAT DOES TWO THINGS
		// 1. EXITS OUT OF THE WHILE LOOP ONCE IT REACHES A LEAF ON THE TREE
		// 2. MAKE SURE IT ONLY DOES THAT (RIGHT NOW, THE CURRENT CONDITION OVERWRITES OTHER VALUES




	
		while((parent->left != NULL && parent->right != NULL)) {
			parent = current;
			printf("newNode data is %s and current data is %s\n",newNode->data, current->data);
			compare = strcmp(newNode->data,current->data);
			if(compare == 0) {
				printf("lolwat\n");
				break;
			}
			if(compare < 0) {
				printf("%s is less than %s!\n", newNode->data, current->data);
				current = current->left;
			}
			else if(compare > 0) {
				printf("%s is greater than %s!\n", newNode->data, current->data);
				current = current->right;
			}
		}
		compare = strcmp(newNode->data, parent->data);
		if(compare < 0) {
			parent->left = newNode;
			printf("ADDED, new node is %s\n",parent->left->data);
		}
		else {
			parent->right = newNode;
			printf("ADDED TOO, new node is %s\n",parent->right->data);
		}

		printf("Debug: Root: %s  RLeft: %s RRight: %s\n",root->data,root->left->data,root->right->data);
	}		

			
	printf("This should be A: %s and this should be F: %s\n",root->left->data, root->right->data);


	fclose(file);
	return root; // return tree root node here.
}



void print_preorder(struct Node* tree) {
	// Implement this function.
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
