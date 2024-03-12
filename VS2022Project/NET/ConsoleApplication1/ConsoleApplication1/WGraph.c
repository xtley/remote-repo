#include "WGraph.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


Graph newGraph(int V) { //初始化一个节点数为V的图
    assert(V >= 0);
    int i;

    Graph g = malloc(sizeof(GraphRep));
    assert(g != NULL);
    g->nV = V;
    g->nE = 0;

    // allocate memory for each row
    g->edges = malloc(V * sizeof(int*));
    assert(g->edges != NULL);
    // allocate memory for each column and initialise with 0
    for (i = 0; i < V; i++) {
        g->edges[i] = calloc(V, sizeof(int));
        assert(g->edges[i] != NULL);
    }

    return g;
}

int numOfVertices(Graph g) {  //返回顶点数
    return g->nV;
}

// check if vertex is valid in a graph
int validV(Graph g, Vertex v) { // 检查v是否在图g中
    return (g != NULL && v >= 0 && v < g->nV);
}

void insertEdge(Graph g, Edge e) {  //插入边
    assert(g != NULL && validV(g, e.v) && validV(g, e.w));

    if (g->edges[e.v][e.w] == 0) {   // edge e not in graph  防止重边
        g->edges[e.v][e.w] = e.weight;
        g->nE++;
    }
}

void removeEdge(Graph g, Edge e) {  // 删除边
    assert(g != NULL && validV(g, e.v) && validV(g, e.w));

    if (g->edges[e.v][e.w] != 0) {   // edge e in graph
        g->edges[e.v][e.w] = 0;
        g->nE--;
    }
}

int adjacent(Graph g, Vertex v, Vertex w) { //返回边权重
    assert(g != NULL && validV(g, v) && validV(g, w));

    return g->edges[v][w];
}

void showGraph(Graph g) { // 打印图
    assert(g != NULL);
    int i, j;

    printf("Number of vertices: %d\n", g->nV);
    printf("Number of edges: %d\n", g->nE);
    for (i = 0; i < g->nV; i++)
        for (j = 0; j < g->nV; j++)
            if (g->edges[i][j] != 0)
                printf("Edge %d - %d: %d\n", i, j, g->edges[i][j]);
}

void freeGraph(Graph g) { //释放图
    assert(g != NULL);

    int i;
    for (i = 0; i < g->nV; i++)
        free(g->edges[i]);
    free(g->edges);
    free(g);
}