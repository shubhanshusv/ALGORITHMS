// Shubhanshu Verma

// Representation of graph using Adjacency list

#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
using namespace std;

struct node{

   long int id;
   struct node* next;

};


struct node* make_node(long int id, struct node* next);
void add_node(struct node* a, long int b);
struct node* add_node_short(struct node* a, long int b);
void print_graph(struct node* graph[], long int n);

int main(){

   long int n = 5;

    struct node* graph[n];
    struct node* last_member[n];

   long int i;

   for(i=0;i<n;i++){

        graph[i] = make_node(i,NULL);
        // avoid declaring last member if u are not using add_node_short
        last_member[i] = graph[i];

   }

   // Using add_node

   // add_node(graph[0],1);
   // add_node(graph[0],4);
   // add_node(graph[1],0);
   // add_node(graph[1],4);
   // add_node(graph[4],0);
   // add_node(graph[4],1);
   // add_node(graph[1],2);
   // add_node(graph[2],1);
   // add_node(graph[2],3);
   // add_node(graph[3],2);

   // using add_node_short

   last_member[0] = add_node_short(last_member[0],1);
   last_member[0] = add_node_short(last_member[0],4);
   last_member[1] = add_node_short(last_member[1],0);
   last_member[1] = add_node_short(last_member[1],4);
   last_member[4] = add_node_short(last_member[4],0);
   last_member[4] = add_node_short(last_member[4],1);
   last_member[1] = add_node_short(last_member[1],2);
   last_member[2] = add_node_short(last_member[2],1);
   last_member[2] = add_node_short(last_member[2],3);
   last_member[3] = add_node_short(last_member[3],2);


    print_graph(graph,n);


   return 0;

}

struct node* make_node(long int id, struct node* next){

   struct node* new_node;

   new_node = (struct node*)malloc(sizeof(struct node));

   new_node->id = id;
   new_node->next = next;

   return new_node;

}

void add_node(struct node* a, long int b){

   struct node* new_node = make_node(b,NULL);

   if(a->next!= NULL){

      struct node* p = a->next;

      while(p->next != NULL){

         p=p->next;

      }

      p->next = new_node;



   }else{

      a->next = new_node;

   }


}

// This function can be used if u store the last member of adjacency list of every node

struct node* add_node_short(struct node* a, long int b){

   struct node* new_node = make_node(b,NULL);
   a->next = new_node;

   return a->next;

}

void print_graph(struct node* graph[], long int n){

   long int i;
   struct node* p;

   for(i=0;i<n;i++){

      p = graph[i]->next;
      cout << "Node " << graph[i]->id << " :-> ";

      while(p!= NULL){

         cout << p->id;
         p = p->next;

         if(p!= NULL){

            cout << "-> ";

         }

      }

      cout << endl;

   }


}
