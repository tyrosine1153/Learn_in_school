#include <stdio.h>
#include <string.h>
#include "Prim_MCST.h"

void CreatGragh(EdgeType* g) {
	g->Cnt_Vertex = 0;
	for (int i = 0; i < MX; i++)
		g->adjList_H[i] = NULL;
	memset(g->Chk_Vertex, 0, MX * 2 * sizeof(int));
}

void InsertVertex(EdgeType* g, int v, int V1) {
	if ((g->Cnt_Vertex) + 1 > V1)
		printf("\n 그래프 정점의 개수를 초과하였습니다");
	else
		(g->Cnt_Vertex)++;
}

void InsertEdge(EdgeType* g, Edge* p) {
	if (p->v_from >= g->Cnt_Vertex || p->v_to >= g->Cnt_Vertex)
		printf("\n 그래프에 없는 정점입니다");
	else
		p->Link = g->adjList_H[p->v_from];
}

void PrintGragh(EdgeType* g) {
	Edge* p;

	for (int i = 0; i < g->Cnt_Vertex; i++) {
		printf("\n 정점 %c의 인접 리스트 : %c", i + 65, i + 65);
		p = g->adjList_H[i];
		while (p) {
			printf(" -> %c(%d)", p->v_to + 65, p->cost);
			p = p->Link;
		}
	}
}

int MinEdge(Edge* pos[], int SU1, int* Ent_eg, int* Ent_Vertex) {
	int sel = 0, mn = MIN;
	Edge* p = NULL;

	for (int i = 0; i < SU1; i++) {
		p = pos[i];
		//그래프에 추가된 정점과 연관있는 사용하지 않은 간선에 대하여//
		if ((Ent_Vertex[p->v_from] || Ent_Vertex[p->v_to]) && (Ent_eg[i] == 1)) {
			if (p->cost < mn)
				sel = i; mn = p->cost;
		}
	}
	p = pos[sel];  //최소 가중치 간선을 추가하고 그 번호를 리턴한다
	return sel;
}

int Except(EdgeType* g, int Cnt_branch) {
	int Cnt_node = 0;

	for (int i = 0; i < MX; i++) {
		if (g->Chk_Vertex[i] || g->Chk_Vertex[i])
			Cnt_node++;
	}
	return Cnt_node == Cnt_branch;
}

//프림 알고리즘에 의한 최소 비용 신장 트리 구하기 프로그램//