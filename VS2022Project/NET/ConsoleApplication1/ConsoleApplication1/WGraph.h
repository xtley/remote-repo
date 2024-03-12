#pragma once
typedef struct GraphRep* Graph;

// vertices are ints
typedef int Vertex;

typedef struct GraphRep {
	int** edges;  // adjacency matrix storing positive weights
	// 0 if nodes not adjacent
	int nV;       // #vertices
	int nE;       // #edges
} GraphRep;

// edges are pairs of vertices (end-points) with a weight
typedef struct Edge {
	Vertex v;
	Vertex w;
	int    weight;
} Edge;

Graph newGraph(int);
int   numOfVertices(Graph);
void  insertEdge(Graph, Edge);
void  removeEdge(Graph, Edge);
int   adjacent(Graph, Vertex, Vertex);  // returns weight, or 0 if not adjacent
void  showGraph(Graph);
void  freeGraph(Graph);
