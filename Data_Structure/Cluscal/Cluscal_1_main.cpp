/*������ ����ġ ������ �������� �����Ѵ�.
�׷����κ��� �ִ� ����ġ ������ ���ʷ� �����ϵ� �׷����� �и����� �ʵ��� �Ѵ�.
������ ������ [������-1]�� �����Ͽ��� �Ѵ�,*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Cluscal_1.h"

enum { A, B, C, D, E, F, G, H, I, J };

// ----------main----------- //
int main() {
	Edge edge[] =
		//{ {A,D,4},{A,B,2},{B,F,1},{B,E,3},{B,D,4},{B,C,4},{C,F,5},{D,E,2},{E,F,5} };
		//{ {A,D,6},{A,C,17},{A,B,3},{B,G,12},{B,D,5},{C,F,8},{C,E,10},{D,E,9},{E,G,2},{E,F,4},{F,G,14} };
	{ {A,F,11}, {A,D,8}, {A,C,12}, {A,B,9}, {B,C,2},{C,E,7},{C,D,6},{D,F,4},{D,E,3},{E,F,13} };
	
	//���� ���� ���ϱ�//
	int SU1=sizeof(edge)/sizeof(Edge);
	int* entry = (int*)malloc(sizeof(int) * SU1);
	memset(entry, 0, sizeof(int) * SU1);
	
	//���� ���� ���ϱ�//
	Edge** edgeAddr = (Edge**)malloc(SU1 * sizeof(Edge*)), * p;
	int i, V1;
	for (i = 0; i < SU1; i++)
		edgeAddr[i] = &edge[i];
	V1 = Cnt_Vertex(edgeAddr, SU1);  //�ִ� ���� ��
	
	//�׷��� ������ ���� �߰�//
	EdgeType* G1 = (EdgeType*)malloc(sizeof(EdgeType));
	CreatGragh(G1, V1);
	for (i = 0; i < V1; i++)
		InsertVertex(G1, i);
	
	//�׷����� ��� ���� �߰�//
	int* Chk_Vertex = (int*)malloc(sizeof(int) * V1 * 2);  //�������� �迭
	memset(Chk_Vertex, 0, sizeof(int) * V1 * 2);
	int from, to, Dcnt = 0;
	for (i = 0; i < SU1; i++) {
		p = edgeAddr[i]; from = p->v_from; to = p->v_to;
		Chk_Vertex[from]++; Chk_Vertex[to + V1]++;
		InsertEdge(G1, p); entry[i] = 1; Dcnt++;
	}
	
	//������ ���� ��� ���//
	printf("\n G1�� ���� ���� ����Ʈ\n"); PrintGragh(G1); printf("\n");

	//���� �ڷ� �������� ����//
	Sorting(edgeAddr, DSCEND, SU1);
	
	//������ ����ġ�� ū �ͺ��� �׷������� ����. ������ ������ �ʵ���//
	for (i = 0; i < SU1; i++) {
		if (Dcnt < V1) break;  //�ּ� ���� �� (Dcnt) = ���� ��(V1) - 1
		p = edgeAddr[i]; from = p->v_from; to = p->v_to;
		--Chk_Vertex[from]; --Chk_Vertex[to + V1];  //�ϴ� ����
		if (Except(Chk_Vertex, V1)) {  //���� ����̸� ���� Ȯ��
			printf("\n (%c, %c) %d ����", from + 65, to + 65, p->cost);
			entry[i] = 0;
			Dcnt--;
		}
		else {
			++Chk_Vertex[from]; ++Chk_Vertex[to + V1];
		}
	}
	printf("\n");
	
	//�� �׷��� �����Ͽ�//
	EdgeType* G2 = (EdgeType*)malloc(sizeof(EdgeType));
	CreatGragh(G2, V1);
	for (i = 0; i < V1; i++)  InsertVertex(G2, i);
	
	//���ܵ��� ���� ������ �׷����� �߰�//
	int hap = 0;
	for (i = 0; i < SU1; i++) {
		if (entry[i]) {
			p = edgeAddr[i]; InsertEdge(G2, p);
			from = p->v_from; to = p->v_to;
			printf("\n ����(%c %c) ����ġ %3d", from + 65, to + 65, p->cost);
			hap = hap + p->cost;
		}
	}
	printf("\n========================");
	printf("\n	�ּ� ��� ����ġ : %3d\n", hap);
	printf("\n\n G2�� ���� ���� ����Ʈ\n");
	PrintGragh(G2);
	printf("\n");
}