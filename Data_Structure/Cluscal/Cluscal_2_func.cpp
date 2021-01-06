#include <stdio.h>
#include "Cluscal_2.h"

//그래프 초기화//
void CreatGragh(EdgeType* g, int V1) {
	g->n = 0;

	for (int i = 0; i < V1; i++)
		g->adjList_H[i] = NULL;
}

//그래프에 정점 추가//
void InsertVertex(EdgeType* g, int v) {
	if (g->n >= MXV)
		printf("\n그래프 정점의 개수를 초과하였습니다");
	else
		(g->n)++;
}

//그래프에 간선 추가//
void InsertEdge(EdgeType* g, Edge* p) {
	Edge* edge;
	if (p->v_from >= g->n || p->v_to >= g->n)
		printf("그래프에 없는 정점입니다.");
	else {
		p->Link = g->adjList_H[p->v_from];
		g->adjList_H[p->v_from] = p;
	}
}

//정점 갯수 구하기//
int Cnt_Vertex(Edge* edgeAddr[], int SU1) {
	int sum, from, to, V1 = 0;
	Edge* p;

	for (int i = 0; i < SU1; i++) {
		p = edgeAddr[i];

		from = p->v_from;
		to = p->v_to;
		sum = from + to;

		if (from > to) {
			p->v_from = sum - from;  // v_from 값에 v_to 값 저장
			p->v_to = sum - to; // v_to 값에 v_from 값 저장
		}
		V1 = V1 > p->v_to ? V1 : p->v_to; //V1에 V1 과 p->v_to 중 더 큰 값 저장
	}
	return V1 + 1;
}

//그래프 출력//
void PrintGragh(EdgeType* g) {
	Edge* p;

	for (int i = 0; i < g->n; i++) {
		printf("\n 정점 %c의 인접 리스트 : %c", i + 65, i + 65);
		p = g->adjList_H[i];
		while (p) {
			printf("-> %c(%d)", p->v_to + 65, p->cost);
			p = p->Link;
		}
	}
}

//제외 대상 점검//
int Except(int* Chk_Vertex, int V1, int edgeCnt) {
	int Cnt_node = 0;
	for (int i = 0; i < V1; i++)
		Cnt_node += (Chk_Vertex[i] || Chk_Vertex[V1 + i]);  // 그래프에 포함된 정점 수
	return Cnt_node == edgeCnt;  // 정점 추가 후 정점과 간선 수 비교
}

//간선의 가중치에 따라 정렬//
void Sorting(Edge* e[], int asds, int SU1) {
	int gijun, p;
	Edge* t;
	for (int i = 0; i < SU1 - 1; i++) {
		gijun = e[i]->cost;
		p = i;
		for (int j = i + 1; i < SU1; j++) {
			if ((e[j]->cost < gijun) == asds) {
				gijun = e[j]->cost;
				p = j;
			}
		}
		t = e[i];
		e[i] = e[p];
		e[p] = t;
	}
}