// Shubhanshu Verma

// Prime number using fermat's little theorem
// finds out whether a number is prime or not
// probabilistic method

// Fermat's little theorem
// if n is prime, then for every a such that 1 <= a < n,
// a^(n-1) % n == 1


#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	int n = 7;

	if(prime(7)){

		cout << n << " is prime" << endl;

	}else{

		cout << n << " is not prime" << endl;

	}

	n = 11;

	if(prime(11)){

		cout << n << " is prime" << endl;

	}else{

		cout << n << " is not prime" << endl;

	}	

	n = 27;

	if(prime(27)){

		cout << n << " is prime" << endl;

	}else{

		cout << n << " is not prime" << endl;

	}

	n = 43131;

	if(prime(43131)){

		cout << n << " is prime" << endl;

	}else{

		cout << n << " is not prime" << endl;

	}


    return 0;
}

bool prime(){

















}