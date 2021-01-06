#include <stdio.h>
#include "Cluscal_2.h"

//�׷��� �ʱ�ȭ//
void CreatGragh(EdgeType* g, int V1) {
	g->n = 0;

	for (int i = 0; i < V1; i++)
		g->adjList_H[i] = NULL;
}

//�׷����� ���� �߰�//
void InsertVertex(EdgeType* g, int v) {
	if (g->n >= MXV)
		printf("\n�׷��� ������ ������ �ʰ��Ͽ����ϴ�");
	else
		(g->n)++;
}

//�׷����� ���� �߰�//
void InsertEdge(EdgeType* g, Edge* p) {
	Edge* edge;
	if (p->v_from >= g->n || p->v_to >= g->n)
		printf("�׷����� ���� �����Դϴ�.");
	else {
		p->Link = g->adjList_H[p->v_from];
		g->adjList_H[p->v_from] = p;
	}
}

//���� ���� ���ϱ�//
int Cnt_Vertex(Edge* edgeAddr[], int SU1) {
	int sum, from, to, V1 = 0;
	Edge* p;

	for (int i = 0; i < SU1; i++) {
		p = edgeAddr[i];

		from = p->v_from;
		to = p->v_to;
		sum = from + to;

		if (from > to) {
			p->v_from = sum - from;  // v_from ���� v_to �� ����
			p->v_to = sum - to; // v_to ���� v_from �� ����
		}
		V1 = V1 > p->v_to ? V1 : p->v_to; //V1�� V1 �� p->v_to �� �� ū �� ����
	}
	return V1 + 1;
}

//�׷��� ���//
void PrintGragh(EdgeType* g) {
	Edge* p;

	for (int i = 0; i < g->n; i++) {
		printf("\n ���� %c�� ���� ����Ʈ : %c", i + 65, i + 65);
		p = g->adjList_H[i];
		while (p) {
			printf("-> %c(%d)", p->v_to + 65, p->cost);
			p = p->Link;
		}
	}
}

//���� ��� ����//
int Except(int* Chk_Vertex, int V1, int edgeCnt) {
	int Cnt_node = 0;
	for (int i = 0; i < V1; i++)
		Cnt_node += (Chk_Vertex[i] || Chk_Vertex[V1 + i]);  // �׷����� ���Ե� ���� ��
	return Cnt_node == edgeCnt;  // ���� �߰� �� ������ ���� �� ��
}

//������ ����ġ�� ���� ����//
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