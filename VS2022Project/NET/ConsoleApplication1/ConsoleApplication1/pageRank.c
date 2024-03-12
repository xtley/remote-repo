#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
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
void insertionSort(int array[], int id[], int in[], int n) {
    int i;
    for (i = 1; i < n; i++) {
        int element = array[i], num = id[i];                 // for this element ...
        int j = i - 1;
        while (j >= 0 && (in[j] < in[num] || (in[j] == in[num] && array[j] < element))) {  // ... work down the ordered list
            array[j + 1] = array[j];               // ... moving elements up
            id[j + 1] = id[j];
            j--;
        }
        array[j + 1] = element;                   // and insert in correct position
        id[j + 1] = num;
    }
}
int main() {
    int webpages;
    printf("Enter the number of webpages: ");
    scanf("%d", &webpages);
    Graph G = newGraph(webpages);
    int val[20000] = { 0 }, id[20000] = { 0 };
    int in[20000] = { 0 }, out[20000] = { 0 };
    for (int i = 0; i < webpages; i++) {
        id[i] = i;
    }
    while (1) {
        getchar();
        printf("Enter a webpage: ");
        char webpage_c;
        scanf("%c", &webpage_c);
        if (webpage_c == '#') break;
        int webpage = webpage_c - '0';
        int number;
        printf("Enter the number of links on webpage %d: ", webpage);
        scanf("%d", &number);
        for (int j = 0; j < number; j++) {
            printf("Enter a link on webpage %d: ", webpage);
            int ver;
            scanf("%d", &ver);
            struct Edge e;
            e.v = webpage;
            e.w = ver;
            e.weight = 1;
            insertEdge(G, e);
            in[ver]++, out[webpage]++;
        }
    }
    printf("Done.\n\n");
    printf("Webpage ranking:\n");
    for (int i = 0; i < webpages; i++) {
        val[i] += out[i];
        for (int j = 0; j < webpages; j++) {
            if (i == j) continue;
            if (G->edges[i][j] != 0) val[i] += in[j];
        }
    }
    insertionSort(val, id, in, webpages);
    for (int i = 0; i < webpages; i++) {
        printf("%d has %d inbound links and scores %d on outbound links.\n",
            id[i], in[id[i]], val[i]);
    }
    return 0;
}
