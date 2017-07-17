// Shubhanshu Verma

// KMP string searching method
// pattern searching

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int *make_lps(string pattern);
void kmp_string_matching(string text,string pattern);

int main(){

	string text = "acbcaacbcacbcaadd";
	string pattern = "acbca";

	kmp_string_matching(text,pattern);

    return 0;
}


// longest proper prefix that is also suffix

int *make_lps(string pattern){

	int p_len = pattern.length();
	int i = 1;
	int j = 0;
	int *lps = new int(p_len);

	lps[0] = 0;

	while(i < p_len){

		if(pattern[i] == pattern[j]){

			j++;
			lps[i] = j;
			i++;

		}else{

			if(j != 0){

				j = lps[j-1];

			}else{

				lps[j] = 0;
				i++;

			}

		}

	}

	return lps;

}

// KMP string matching

void kmp_string_matching(string text,string pattern){

	int n = text.length();
	int m = pattern.length();

	int *lps = new int(m);
	lps = make_lps(pattern);

	int i = 0;
	int j = 0;

	while(i < n){

		if(text[i] == pattern[j]){

			i++;
			j++;

			if(j == m){

				cout << "Pattern found at index :" << i- j<< endl;
				j = lps[j-1];

			}

		}else{

			if(j != 0){

				j = lps[j-1];

			}else{

				i++;

			}

		}

	}

}


