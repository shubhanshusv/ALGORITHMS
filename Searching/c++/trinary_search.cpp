// Shubhanshu Verma

// Trinary Search
// T(n) = T(n/3) + 4

#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
using namespace std;

long int trinary_search(long int a[], long int l, long int r, long int k);

int main(){

   long int array[10] = {1,13,17,25,29,44,45,59,69,72};

   long int x = trinary_search(array,0,9,44);

   cout << "Position of 44 in array : " << x+1;

   return 0;

}

long int trinary_search(long int a[], long int l, long int r, long int k){

   if(l <= r){

         long int m1 = l + (r-l)/3;
         long int m2 = m1 + (r-l)/3;

         if(a[m1] == k){
            return m1;
         }

         if(a[m2] == k){
            return m2;
         }

         if(a[m1] > k){
            return trinary_search(a,l,m1-1,k);
         }

         if(a[m2] < k){
            return trinary_search(a,m2+1,r,k);
         }

         return trinary_search(a,m1+1,m2-1,k);

   }

   return -1;

}