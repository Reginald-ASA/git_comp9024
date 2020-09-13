// gcc dijkstra.c PQueue.h PQueue.c WGraph.h WGraph.c

// Starting code for Dijkstra's algorithm ... COMP9024 20T2
#include <stdio.h>
#include <stdbool.h>
#include "PQueue.h"
// #include "WGraph.h"
#define VERY_HIGH_VALUE 999999
void dijkstraSSSP(Graph g, Vertex source) {
   int  dist[MAX_NODES];
   int  pred[MAX_NODES];
   bool vSet[MAX_NODES];  // vSet[v] = true <=> v has not been processed
   int s, t;
   PQueueInit();
   int nV = numOfVertices(g);
   for (s = 0; s < nV; s++) {
      joinPQueue(s);
      dist[s] = VERY_HIGH_VALUE;
      pred[s] = -1;
      vSet[s] = true;
   }
   dist[source] = 0;
   Vertex u;
   while(!PQueueIsEmpty()){
      printf("---------------------------------\n");
      printf("\n    ");
      for (int i = 0; i < nV; ++i)
         printf("%4d", i);
      printf("\ndist");
      for (int i = 0; i < nV; ++i){
         if (dist[i] > 99999)
            printf(" inf");
         else
            printf("%4d", dist[i]);
      }
      printf("\npred");
      for (int i = 0; i < nV; ++i)
         printf("%4d", pred[i]);
      printf("\n");

      u = leavePQueue(dist);
      printf("挑选了---%d---\n", u);
      vSet[u] = false;
      for (int v = 0; v < nV; ++v )
      {
         if(adjacent(g,u,v) > 0 && vSet[v]){
           t = dist[u] + adjacent(g,u,v);
           if(t < dist[v]){
               dist[v] = t;
               pred[v] = u;
           }
         }
      }
   }
   int path[nV];
   for (int i = 0; i < nV; ++i){
      if(dist[i]!=VERY_HIGH_VALUE){
         printf("%d: distance = %d, ", i,dist[i]);
         printf("shortest path: ");
         int temp = i,num = 1;
         path[0] = i;
         while(temp != source){
            path[num] = pred[temp];
            num++;
            temp = pred[temp];
         }
         for (int j = (num-1); j >= 0; j--){
            printf("%d", path[j]);
            if(j != 0){
               printf("-");
            }
         }
         printf("\n");
      }
      else{
         printf("%d: no path\n", i);
      }
   }
   /* NEEDS TO BE COMPLETED */
}
void reverseEdge(Edge *e) {
   Vertex temp = e->v;
   e->v = e->w;
   e->w = temp;
}
int main(void) {
   Edge e;
   int  n, source;
   printf("Enter the number of vertices: ");
   scanf("%d", &n);
   Graph g = newGraph(n);
   printf("Enter the source node: ");
   scanf("%d", &source);
   printf("Enter an edge (from): ");
   while (scanf("%d", &e.v) == 1) {
      printf("Enter an edge (to): ");
      scanf("%d", &e.w);
      printf("Enter the weight: ");
      scanf("%d", &e.weight);
      insertEdge(g, e);
      // reverseEdge(&e);               // ensure to add edge in both directions
      // insertEdge(g, e);
      printf("Enter an edge (from): ");
   }
   printf("Done.\n");
   dijkstraSSSP(g, source);
   freeGraph(g);
   return 0;
}