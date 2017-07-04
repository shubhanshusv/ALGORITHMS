// Shubhanshu Verma

// Binary Search
// T(n) = T(n/2) + 2

#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
using namespace std;

long int binary_search(long int a[], long int l, long int r, long int k);

int main(){

   long int array[10] = {1,13,17,25,29,44,45,59,69,72};

   long int x = binary_search(array,0,9,44);

   cout << "Position of 44 in array : " << x+1;

   return 0;

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