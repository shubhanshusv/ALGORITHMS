// Shubhanshu Verma

// Dynamic Programming
// Longest Increasing Subsequence
// For an array of n elements, let L(i) be the length of the LIS ending at index i such that arr[i] is the last element of the LIS.
// Then, L(i) can be recursively written as:
// L(i) = 1 + max( L(j) ) where 0 < j < i and arr[j] < arr[i]; or
// L(i) = 1, if no such j exists.
// max(L(i)) is the required answer

// Practise : https://www.hackerrank.com/challenges/longest-increasing-subsequent


#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
using namespace std;

long int longest_increasing_subsequence(long int a[], long int n);

int main(){

   long int array[10] = {34,45,11,35,64,54,52,88,59,79};

   long int x = longest_increasing_subsequence(a, 10);

   cout << "Length of longest increasing subsequence is : " << x;

   return 0;

}

long int longest_increasing_subsequence(long int a[], long int n){

   long int l[n];
   long int i,j;
   long int max = 1;

   for(i=0;i<n;i++){

      l[i] = 1;

   }

   for(i=1;i<n;i++){

      for(j=0;j<i;j++){

         if(a[i] > a[j] && l[i] < l[j]+1){

            l[i] = l[j] + 1;

         }

      }

   }

   for(i=0;i<n;i++){

      if(max < l[i]){

         max = l[i];

      }

   }

   return max;

}