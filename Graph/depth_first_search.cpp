// Shubhanshu Verma

// DFS (Depth First Search)

#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

struct node{

   long int id;
   struct node* next;

};

struct node* make_node(long int id, struct node* next);
void add_node(struct node* a, long int b);
struct node* add_node_short(struct node* a, long int b);
void print_graph(struct node* graph[], long int n);
void dfs(struct node* graph[], int color[], long int d[], long int f[], long int parent[],long int n);
void dfs_visit(struct node* graph[],long int id, int color[], long int d[],long int f[],long int parent[]);

long int t;

int main(){

   long int n = 6;

   struct node* graph[n];
   long int i;
   int color[n];
   long int d[n];
   long int f[n];
   long int parent[n];

   for(i=0;i<n;i++){

        graph[i] = make_node(i,NULL);

   }

   // Using add_node

   add_node(graph[0],1);
   add_node(graph[0],3);
   add_node(graph[1],4);
   add_node(graph[2],4);
   add_node(graph[2],5);
   add_node(graph[3],1);
   add_node(graph[4],3);
   add_node(graph[5],5);

   //print_graph(graph,n);

   cout << "Nodes are visited in this order:" << endl;
   dfs(graph,color,d,f,parent,n);

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

void dfs(struct node* graph[], int color[], long int d[], long int f[], long int parent[],long int n){

   long int i;

   for(i=0;i<n;i++){

      color[i] = 0;

   }

   t = 0;

   for(i=0;i<n;i++){

      if(color[i] == 0){

         dfs_visit(graph,i,color,d,f,parent);

      }

   }

}

void dfs_visit(struct node* graph[],long int id, int color[], long int d[],long int f[],long int parent[]){

   struct node* p;
   p = graph[id];
   color[id] = 1;
   t++;
   d[id] = t;
   cout << id << " ";

   while(p->next != NULL){

      if(color[p->next->id] == 0){

         parent[p->next->id] = id;
         dfs_visit(graph,p->next->id, color,d,f,parent);

      }

      p = p->next;

   }

      color[id] = 2;
      t++;
      f[id] = t;


}
