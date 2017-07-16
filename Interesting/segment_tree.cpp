// Shubhanshu Verma

// Segment tree
// Maximum in a given range

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int a[500001];

struct node{

	int l;                  // left interval limit
	int r;					// right interval limit
	int maxi;				// maximum element in this interval limit
	struct node* parent;
	struct node* left;
	struct node* right;

};

struct node* make_node(int l,int r);
void make_tree(struct node* root);
int fill_tree(struct node* root);
int query(int l,int r,struct node* root);
void update_value(struct node* root, int index,int value,int n);
void tree_updater(int value,struct node* root);

int main() {

   	int n;
   	cin >> n;

   	struct node* root = make_node(0,n-1);
	int i;

	for(i=0;i<n;i++){

		cin >> a[i];

	}

	make_tree(root);
	int x = fill_tree(root);

	cout << query(0,n,root) << " ";

	update_value(root,n/2,2*root->maxi,n);

	cout << query(0,n,root);

    return 0;
}


struct node* make_node(int l,int r){

	struct node* new_node;

    new_node = (struct node*)malloc(sizeof(struct node));   // space allocation


    new_node->l = l;        // index value is given vertex no.
    new_node->r = r;        // next pointer is made null

    if(l == r){

    	new_node->maxi = a[l];

    }

    new_node->parent = NULL;
    new_node->right  = NULL;
    new_node->left   = NULL;

    return new_node;

}

void make_tree(struct node* root){

	if(root->l == root->r){


	}else{

		int mid = (root->l + root->r)/2;

		struct node* le = make_node(root->l,mid);
		struct node* ri = make_node(mid+1,root->r);

		root->left = le;
		root->right = ri;

		make_tree(le);
		make_tree(ri);

	}

}

int fill_tree(struct node* root){

	if(root->l == root->r){

		return root->maxi;

	}else{

		root->maxi = max(fill_tree(root->left),fill_tree(root->right));
		return root->maxi;

	}

}

int query(int l,int r,struct node* root){


	if(root->l >= l && root->r <= r){

		return root->maxi;

	}else if(root->l > r || root->r < l ){

		return -100000;

	}else{

		return max(query(l,r,root->left),query(l,r,root->right));

	}


}

void update_value(struct node* root, int index,int value,int n){


	if(index <0 || index >= n){

		return;

	}

	a[index] = value;

	tree_updater(value,root);


}

void tree_updater(int value,struct node* root){

	if(root->maxi < value){

		root->maxi = value;

	}

	if(root->l != root->r){

		int mid = (root->l + root->r)/2;

		tree_updater(value,root->left);
		tree_updater(value,root->right);

	}

}
