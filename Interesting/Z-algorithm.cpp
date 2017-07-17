// Shubhanshu Verma

// Z algorithm
// pattern searching

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int *z_array(string s);
void z_search(string text, string pattern);

int main(){

	string text = "acbcaacbcacbcaadd";
	string pattern = "acbca";

	z_search(text,pattern);

    return 0;
}

int *z_array(string s){

	int n = s.length();
	int l = 0;
	int r = 0;
	int i,k;

	int *z = new int(n);

	for(i=1;i<n;i++){

		if(i > r){

			l = i;
			r = i;

			while(r < n && s[r-l] == s[r]){

				r++;

			}

			z[i] = r-l;
			r--;


		}else{

			k = i-l;

			if(z[k] < r-i + 1){

				z[i] = z[k];

			}else{

				l = i;

				while(r < n && s[r-l] == s[r]){

					r++;

				}

				z[i] = r-l;
				r--;

			}

		}

	}

	return z;

}

void z_search(string text, string pattern){

	string s = pattern + "$" + text;

	int n = s.length();
	int m = pattern.length();

	int *z = new int(n);

	z = z_array(s);

	int i;

	for(i=m+1;i<n;i++){

		if(z[i] == m){

			cout << "Pattern found at index : " << i-m-1 << endl;

		}

	}

}


