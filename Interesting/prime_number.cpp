// Shubhanshu Verma

// Prime number 
// finds out whether a number is prime or not
// uses the fact that prime numbers are of the form 6k +- 1 (except 2 and 3)
// also for a number n, check is made only till n^(1/2)

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool prime(int n);

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

bool prime(int n){

	if(n <= 1){

		return false;

	}


	if(n <= 3){

		return true;

	}

	if(n%2 == 0 || n%3 == 0 ){

		return false;
	}

	int i;

	for(i=5;i*i <= n; i+=6){

		// using the fact that prime numbers are of the form 6k +- 1
		if(n%i == 0 || n%(i+2) == 0){

			return false;

		}

	}

	return true;

}