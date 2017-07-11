// Shubhanshu Verma

// Exponential Search
// Finds ideal range for binary search and then performs binary search

#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
using namespace std;

long int binary_search(long int a[], long int l, long int r, long int k);
long int exponential_search(long int a[],long int n,long int k);

int main(){

   long int array[10] = {1,13,17,25,29,44,45,59,69,72};

   long int x = exponential_search(array,10,44);

   cout << "Position of 44 in array : " << x+1;

   return 0;

}

long int exponential_search(long int a[],long int n,long int k){

   if(a[0] == k){

      return 0;

   }

   long int i = 1;

   while(a[i] <= k && i<n){

      i*=2;

   }

   return binary_search(a,i/2,min(i,n),k);

}

long int binary_search(long int a[], long int l, long int r, long int k){

   if(l <= r){

      long int m = l + (r-l)/2;

      if(a[m] == k){
         return m;
      }

      if(a[m] < k){
         return binary_search(a,m+1,r,k);
      }

      if(a[m] > k){
         return binary_search(a,l,m-1,k);
      }

   }

   return -1;

}
