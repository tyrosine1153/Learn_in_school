#ifndef _PRIM_MCST_H_
#define _PRIM_MCST_H_

#define MX 10
#define MIN 100

typedef struct _edge {
	int v_from;
	int v_to;
	int cost;
	struct _edge* Link;
}Edge;

typedef struct _edgeType {
	int Cnt_Vertex;
	int Chk_Vertex[MX * 2];
	Edge* adjList_H[MX];
}EdgeType;

void CreatGragh(EdgeType* g);
void InsertVertex(EdgeType* g, int v, int V1);
void InsertEdge(EdgeType* g, Edge* p);
void PrintGragh(EdgeType* g);
int MinEdge(Edge* pos[], int SU1, int* Ent_eg, int* Ent_Vertex);
int Except(EdgeType* g, int Cnt_branch);

#endif