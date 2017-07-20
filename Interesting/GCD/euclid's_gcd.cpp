// Shubhanshu Verma

// Euclid's Algorithm
// GCD of two numbers

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int gcd_recursive(int a, int b);
int gcd_iterative(int a, int b);

int main(){

	cout << "GCD of 15 and 25 is " << gcd_recursive(15,25) << endl;

	cout << "GCD of 15 and 25 is " << gcd_iterative(15,25);


    return 0;
}

// Recursive function to calculate GCD of a and b
// make sure that a <= b when u pass the values

int gcd_recursive(int a, int b){

	if(a == 0){

		return b;

	}else{

		return gcd_recursive(b%a,a);

	}

}

// Iterative function to calculate GCD of a and b
// make sure that a <= b when u pass the values

int gcd_iterative(int a, int b){

	int temp;

	while(1){

		if(a == 0){

			return b;

		}

		temp = a;
		a = b%a;
		b = temp;

	}

}

