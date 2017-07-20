// Shubhanshu Verma

// Extended euclid's algorithm
// Helps to find out integers x and y such that ax + by = gcd(a,b)
// x is modular multiplicative inverse of a and y is mosular multiplicative inverse of a

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int *euclid_extended(int a, int b);

int main(){

	int *gcd = new int(3);
	gcd = euclid_extended(15,25);

	cout << "GCD of 15 and 25 is " << gcd[0] << endl;
	cout << gcd[1] << "*15 + " << gcd[2] << "*25 = " << gcd[0]; 


    return 0;
}


// ax + by = gcd                            -------1
//also  (b%a)x1 + ay1 = gcd

// put b%a = (b - (floor(b/1)*a)
// So we get bx1 + a(y1 - (floor(b/1))x1) = gcd ----2

// comparing coefficients of a in 1 and 2
// x = y1 - x1*floor(b/a)
// y = x1

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