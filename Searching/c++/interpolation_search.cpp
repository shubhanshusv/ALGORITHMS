// Shubhanshu Verma

// Interpolation Search
// Interpolation Search is an improvement over Binary Search
// Binary Search always goes to middle element to check.
// On the other hand interpolation search may go to different locations according the value of key being searched.
// For example if the value of key is closer to the last element, interpolation search is likely to start search toward the end side.

// The idea of formula is to return higher value of pos
// when element to be searched is closer to arr[hi]. And
// smaller value when closer to arr[lo]
// pos = lo + [ (x-arr[lo])*(hi-lo) / (arr[hi]-arr[Lo]) ]

// arr[] ==> Array where elements need to be searched
// x     ==> Element to be searched
// lo    ==> Starting index in arr[]
// hi    ==> Ending index in arr[]

#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
using namespace std;

long int interpolation_search(long int a[], long int l, long int r, long int k);

int main(){

   long int array[10] = {1,13,17,25,29,44,45,59,69,72};

   long int x = interpolation_search(array,0,9,44);

   cout << "Position of 44 in array : " << x+1;

   return 0;

}

long int interpolation_search(long int a[], long int l, long int r, long int k){

   if(l <= r){

      long int m = l + (r-l)*(k - a[l])/(a[r] - a[l]);

      if(a[m] == k){
         return m;
      }

      if(a[m] < k){
         return interpolation_search(a,m+1,r,k);
      }

      if(a[m] > k){
         return interpolation_search(a,l,m-1,k);
      }

   }

   return -1;

}
