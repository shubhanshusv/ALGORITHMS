// Shubhanshu Verma

// Modular multiplicative inverse
// Given two integers a and m, find modular multiplicative inverse of a under m
// x is said to be modular multiplicative inverse if ax % m = 1
// x should be in range 0 to m-1

// multiplicative inverse of a%m exists iff a and m are relatively prime (gcd(a,m) = 1)

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


int mod_inverse_I(int a, int m);
int *euclid_extended(int a, int b);
void mod_inverse_II(int gcd[3], int m);

int main(){

    int x = mod_inverse_I(3,11);
    cout << "Modular multiplicative inverse of 3 under 11 is " << x << endl;


    mod_inverse_II(euclid_extended(3,11),11);



    return 0;
}

// Simple approach O(m)

int mod_inverse_I(int a, int m){

	a = a%m;
	int i;

	for(i=0;i<m;i++){

		if((a*i)%m == 1){

			return i;

		}


	}

}

// Using Euclid's extended algorithm
// works when m and a are coprime
// O(logm)

// ax + my = gcd(a,m) = 1                    -------1
// ax + my = 1

// Taking modulo m on both sides
// (ax + my)%m = 1 % m = 1

// So ax % m = 1
// x is modular multiplicative inverse of a

// gcd[1] is modular multiplicative inverse of a

int *euclid_extended(int a, int b){

	int *gcd = new int(3);

	if(a == 0){

		gcd[0] = b;       // stores gcd
		gcd[1] = 0;		  // stores x
		gcd[2] = 1;		  // stores y

		return gcd;

	}

	gcd = euclid_extended(b%a,a);

	int x = gcd[2] - (b/a)*gcd[1];
	int y = gcd[1];

	gcd[1] = x;
	gcd[2] = y;

	return gcd;

}

void mod_inverse_II(int gcd[3], int m){

	if(gcd[0] != 1){

		cout << "Inverse doesn't exist" << endl;

	}else{

		int x = (gcd[1]%m + m) %m;
		cout << "Multiplicative inverse :"<< x << endl;

	}

}


// If m is prime, using fermat's little theorem

// (a^(m-1)) % m = 1
