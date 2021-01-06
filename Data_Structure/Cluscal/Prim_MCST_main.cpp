/*������ ���� �ϳ��� �߰��ϰ�
�� ������ ����� ���� �� �ּ� ������ �����Ͽ� �߰��Ѵ�
�߰��� ������ ���Ե� ������ ������ ����� �ּ� ������ �����Ͽ� �߰��Ѵ�
������ ���� [������-1]�� �����Ͽ��� �Ѵ�*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Prim_MCST.h"

enum { A, B, C, D, E, F, G, H, I, J };

#define START F

int main() {
	Edge edge[] =
		//{ {A,D,4},{A,B,2},{B,F,1},{B,E,3},{B,D,4},{B,C,4},{C,F,5},{D,E,2},{E,F,5} };
		//{ {A,D,6},{A,C,17},{A,B,3},{B,G,12},{B,D,5},{C,F,8},{C,E,10},{D,E,9},{E,G,2},{E,F,4},{F,G,14} };
	{ {A,F,11}, {A,D,8}, {A,C,12}, {A,B,9}, {B,C,2},{C,E,7},{C,D,6},{D,F,4},{D,E,3},{E,F,13} };
	int SU1 = sizeof(edge) / sizeof(Edge);  //���� ���� ���ϱ�
	Edge** edgeAddr = (Edge**)malloc(SU1 * sizeof(Edge*)), * p;

	int i, from, to, cost, sum, vx = 0, V1;

	for (i = 0; i < SU1; i++) {
		p = &edge[i];
		from = p->v_from; to = p->v_to; sum = from + to;
		if (from > to) {
			p->v_from = sum - from;
			p->v_to = sum - to;
		}
		vx = p->v_to > vx ? p->v_to : vx;
		edgeAddr[i] = p;
	}
	V1 = vx + 1;  // ���� ���� ���ϱ�

	//�׷��� �����Ͽ� ���� �߰�//
	EdgeType* G1 = (EdgeType*)malloc(sizeof(EdgeType));
	int* Ent_Vertex = (int*)malloc(V1 * sizeof(int));

	memset(Ent_Vertex, 0, V1 * sizeof(int));
	CreatGragh(G1);
	for (i = 0; i < V1; i++) {
		if (!Ent_Vertex[i]) {
			InsertVertex(G1, i, V1);
			Ent_Vertex[i] = 1;
		}
	}

	//�����߰�//
	int* Ent_eg = (int*)malloc(SU1 * sizeof(int));

	memset(Ent_eg, 0, SU1 * sizeof(int));
	for (i = 0; i < SU1; i++) {
		InsertEdge(G1, edgeAddr[i]);
		Ent_eg[i] = 1;
	}

	//������ ���� ��� ���//
	printf("\n G1�� ���� ���� ����Ʈ \n");
	PrintGragh(G1);

	//�� �׷��� �����Ͽ�//
	int pos, Cnt_branch = 0, hap = 0;
	EdgeType* G2 = (EdgeType*)malloc(sizeof(EdgeType));
	CreatGragh(G2);

	memset(Ent_Vertex, 0, V1 * sizeof(int));
	for (int i = 0; i < V1; i++)  //������ ����
		if (!Ent_Vertex[i])InsertVertex(G2, i, V1);

	//� ���� �߰��ϰ� �� ������ ����� ù��° �ּ� ������ �׷����� �߰�//
	Ent_Vertex[START] = 1;
	pos = MinEdge(edgeAddr, SU1, Ent_eg, Ent_Vertex);
	p = edgeAddr[pos]; InsertEdge(G2, p); Cnt_branch++;
	from = p->v_from; to = p->v_to; cost = p->cost;

	G2->Chk_Vertex[from]++; G2->Chk_Vertex[to]++;
	Ent_Vertex[from] = 1; Ent_Vertex[to] = 1; Ent_eg[pos] = 0;
	hap += cost;
	printf("\n %2d> ����(%c %c  %3d) �߰�", pos, from + 65, to + 65, cost);

	while (Cnt_branch + 1 < V1) {  //�ι��� ������ ������ �ּ� ������ �߰��� ��
		pos = MinEdge(edgeAddr, SU1, Ent_eg, Ent_Vertex);
		p = edgeAddr[pos]; Cnt_branch++;
		from = p->v_from; to = p->v_to; cost = p->cost;

		G2->Chk_Vertex[from]++; G2->Chk_Vertex[to]++;
		Ent_Vertex[from] = 1; Ent_Vertex[to] = 1; Ent_eg[pos] = 0;
		hap += cost;
		printf("\n %2d> ����(%c %c  %3d) �߰�", pos, from + 65, to + 65, cost);

		if (Except(G1, Cnt_branch)) {
			printf("\n %2d> ����(%c %c  %3d) ����", pos, from + 65, to + 65, cost);
			G2->Chk_Vertex[from]--; G2->Chk_Vertex[to]--;
			Ent_eg[pos] = -1; Cnt_branch--; hap -= cost;
		}
		else  // �߰� ������ ������ �߰� Ȯ��
			InsertEdge(G2, p);
	}

	printf("\n========================");
	printf("\n	�ּ� ��� ����ġ : %3d\n", hap);
	printf("\n\n G2�� ���� ���� ����Ʈ\n");
	PrintGragh(G2);
	printf("\n");
}