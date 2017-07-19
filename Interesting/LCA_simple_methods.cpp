// Shubhanshu Verma

// LCA
// Note the methods assume tree to be a binary tree
// can be improved for special case of binary tree, i.e, binary search tree

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct node{

	int key;

	struct node *left;
	struct node *right;

};


struct node *make_node(int key);
bool find_path(struct node* root, int key, vector<int> path);
void insert_bst(struct node* root, int key);
int LCA_path_checking(struct node* root,struct node* n1, struct node* n2);
struct node* LCA_II(struct node* root, int n1, int n2);

int main(){

	struct node* root = make_node(4);
    insert_bst(root,2);
    insert_bst(root,1);
    insert_bst(root,3);
    insert_bst(root,6);
    insert_bst(root,5);
    insert_bst(root,7);

    /*
					4
			
			2  				6

		1		3		5		7


    */
    
	int x = LCA_path_checking(root,root->left->left,root->left->right);
    cout << "LCA of 1 and 3 is " << x << endl;

    struct node *p = root->right;
    int n1 = p->left->key;
    int n2 = p->right->key;

    p = LCA_II(root,n1,n2);
    cout << "LCA of 5 and 7 is " << p->key << endl;



    return 0;
}

struct node *make_node(int key){

	struct node* new_node;
	new_node = (struct node*)malloc(sizeof(struct node));

	new_node->key = key;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;

}

void insert_bst(struct node* root, int key){


	if(root->key >= key){

		if(root->left != NULL){

			insert_bst(root->left,key);

		}else{

			root->left = make_node(key);

		}


	}else{


		if(root->right != NULL){

			insert_bst(root->right,key);

		}else{

			root->right = make_node(key);

		}

	}


}

bool find_path(struct node* root, int key, vector<int> path){

	if(root == NULL){

		return false;

	}

	path.push_back(root->key);

	if(root->key == key){

		return true;

	}else{

		if(find_path(root->left,key,path) || find_path(root->right,key,path)){

			return true;

		}else{

			path.pop_back();
			return false;

		}

	}

}

// LCA by checking path from root to nodes n1 and n2

int LCA_path_checking(struct node* root,struct node* n1, struct node* n2){

	vector<int> path1;
	vector<int> path2;

	bool x = find_path(root,n1->key,path1);
	x = find_path(root,n2->key,path2);

	int i;

	while(1){

		if(path1[i] == path2[i]){

			i++;

		}else{

			i--;
			break;

		}

	}

	return i;

}

struct node* LCA_II(struct node* root, int n1, int n2){

	if(root == NULL){

		return NULL;

	}

	if(root->key == n1 || root->key == n2){

		return root;

	}

	struct node* left_tree = LCAII(root->left,n1,n2);
	struct node* right_tree = LCAII(root->right,n1,n2);

	if(left_tree != NULL && right_tree != NULL){

		return root;

	}else{

		if(left_tree != NULL){

			return left_tree;

		}else{

			return right_tree;

		}

	}

}

