// Shubhanshu Verma

// Binary Indexed Tree
// Sum in a given range

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int *constructBITree(int arr[], int n);
int range_sum(int binary_indexed_tree[],int index);
void update_tree(int binary_indexed_tree[],int n,int index, int value);

int main() {

	int n;
	cin >> n;

	int i;
	int *a = new int[n];

	for(i=0;i<n;i++){

		cin >> a[i];

	}

	int *binary_indexed_tree = new int[n];

	binary_indexed_tree = constructBITree(a,n);

	// let's find sum in range 1 to n-2 ,i.e, excluding a[0] and a[n-1]

	cout << range_sum(binary_indexed_tree,n-2) - range_sum(binary_indexed_tree,0);

    return 0;
}

// calculates sum from range 0 to index

int range_sum(int binary_indexed_tree[],int index){

	index++; // index of binary indexed tree starts from 1

	int sum = 0;

	while(index > 0){

		sum += binary_indexed_tree[index];
		index -= index & (-index);

	}

	return sum;

}

void update_tree(int binary_indexed_tree[],int n,int index, int value){

	index++;

	while(index <= n){

		binary_indexed_tree[index] += value;

		// Update index to that of parent
		// adds last set bit of index to itself
        index += index & (-index);

	}

}

int *constructBITree(int arr[], int n){

    int *binary_indexed_tree = new int[n+1];

    int i;

    for(i=1; i<=n; i++){

        binary_indexed_tree[i] = 0;

    }

    // Store the actual values in binary_indexed_tree[] using update()
    for(i=0; i<n; i++){

        update_tree(binary_indexed_tree, n, i, arr[i]);

    }


    return binary_indexed_tree;

}


