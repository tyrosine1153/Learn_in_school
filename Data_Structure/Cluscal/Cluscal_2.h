#pragma once
#ifndef _CLUSCAL_2_H_
#define _CLUSCAL_2_H_

#define MXV 10  // 최대 정점 수
#define MX 45  //10C2 = 10*9/2=45
#define TRUE 1
#define FALSE 0
#define ASCEND 1
#define DSCEND 0

typedef struct _edge {
	int v_from, v_to, cost;
	struct _edge* Link;
}Edge;

typedef struct _edgeType {
	int n;
	Edge* adjList_H[MXV];
}EdgeType;

void CreatGragh(EdgeType* g, int V1);
void InsertVertex(EdgeType* g, int v);
void InsertEdge(EdgeType* g, Edge* p);
int Cnt_Vertex(Edge* edgeAddr[], int SU1);
void PrintGragh(EdgeType* g);
int Except(int* Chk_Vertex, int V1, int edgeCnt);
void Sorting(Edge* e[], int asds, int SU1);

#endif