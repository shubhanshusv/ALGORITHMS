// Shubhanshu Verma

// BFS (Breadth First Search)

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
void bfs(struct node* graph[], int color[], long int d[],long int parent[]);
std::vector<int> v;

int main(){

   long int n = 4;

   struct node* graph[n];
   long int i;
   int color[n];
   long int distance[n];
   long int parent[n];

   for(i=0;i<n;i++){

        graph[i] = make_node(i,NULL);

   }

   // Using add_node

   add_node(graph[0],1);
   add_node(graph[0],2);
   add_node(graph[1],2);
   add_node(graph[2],0);
   add_node(graph[2],3);
   add_node(graph[3],3);

   //print_graph(graph,n);

   // bfs at node 2

   for(i=0;i<n;i++){

      color[i] = 0;

   }

   v.push_back(2);
   color[2] = 1;
   parent[2] = -1;  // nil
   distance[2] = 0;

   cout << "BFS at node 2" << endl;

   bfs(graph,color,distance,parent);

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

void bfs(struct node* graph[], int color[], long int d[],long int parent[]){

   struct node* p;
   long int id;

   while(v.size() != 0){

      id = v.front();
      p = graph[id];
      cout << id << " ";
      v.erase(v.begin());

      while(p->next != NULL){

         if(color[p->next->id] == 0){

            color[p->next->id] = 1;
            d[p->next->id] = d[id] + 1;
            parent[p->next->id] = id;

            v.push_back(p->next->id);

         }

         p = p->next;

      }

      color[id] = 2;

   }

}
