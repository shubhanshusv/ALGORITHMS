// Shubhanshu Verma

// Trie
// An efficient information retrieval data structure
// Since there are 26 lower case alphabet letters, Size has been fixed to 26

#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <bits/stdc++.h>
using namespace std;

#define key_index(c) ((int)c - (int)'a')     // converting characters to integer keys

struct node{

   struct node* children[26];
   bool leaf;

};

struct node* make_node();
void insert_key(struct node* root, string key);
bool search_key(struct node* root,string key);

int main(){

   string key = "hello";
   struct node* root = make_node();
   insert_key(root,key);
   key = "world";
   insert_key(root,key);
   key = "this";
   insert_key(root,key);
   key = "is";
   insert_key(root,key);
   key = "trie";
   insert_key(root,key);
   key = "data";
   insert_key(root,key);
   key = "structure";
   insert_key(root,key);

   key = "world";
   bool x = search_key(root,key);
   if(x == true){

      cout << key << " is present" << endl;

   }else{

      cout << key << " is not present" << endl;

   }

   key = "worlder";
   x = search_key(root,key);
   if(x == true){

      cout << key << " is present" << endl;

   }else{

      cout << key << " is not present" << endl;

   }


   
   return 0;

}

struct node* make_node(){

   struct node* new_node;
   new_node = (struct node*)malloc(sizeof(struct node));

   int i;

   new_node->leaf = false;

   for(i=0;i<26;i++){

      new_node->children[i] = NULL;

   }

   return new_node;

}

void insert_key(struct node* root, string key){

   int i;
   int length = key.length();
   int index;

   struct node* p = root;

   for(i=0;i<length;i++){

      index = key_index(key[i]);

      if(p->children[index] == NULL){

         p->children[index] = make_node();

         p = p->children[index];

      }


   }

   p->leaf = true;

}

bool search_key(struct node* root,string key){

   int i;
   int length = key.length();
   int index;

   struct node* p = root;

   for(i=0;i<length;i++){

      index = key_index(key[i]);

      if(p->children[index] == NULL){

        return false; 
        
      }

       p = p->children[index];

   }

   return p->leaf;

}




