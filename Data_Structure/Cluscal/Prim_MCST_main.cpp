/*임의의 정점 하나를 추가하고
그 정점에 연결된 간선 중 최소 간선을 선택하여 추가한다
추가된 간선에 포함된 각각의 정점에 연결된 최소 간선을 선택하여 추가한다
간선의 수는 [정점수-1]을 만족하여야 한다*/

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
	int SU1 = sizeof(edge) / sizeof(Edge);  //간선 개수 구하기
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
	V1 = vx + 1;  // 정점 개수 구하기

	//그래프 생성하여 정점 추가//
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

	//간선추가//
	int* Ent_eg = (int*)malloc(SU1 * sizeof(int));

	memset(Ent_eg, 0, SU1 * sizeof(int));
	for (i = 0; i < SU1; i++) {
		InsertEdge(G1, edgeAddr[i]);
		Ent_eg[i] = 1;
	}

	//정점별 인접 노드 출력//
	printf("\n G1의 인접 정점 리스트 \n");
	PrintGragh(G1);

	//새 그래프 생성하여//
	int pos, Cnt_branch = 0, hap = 0;
	EdgeType* G2 = (EdgeType*)malloc(sizeof(EdgeType));
	CreatGragh(G2);

	memset(Ent_Vertex, 0, V1 * sizeof(int));
	for (int i = 0; i < V1; i++)  //정점만 설정
		if (!Ent_Vertex[i])InsertVertex(G2, i, V1);

	//어떤 정점 추가하고 그 정점에 연결된 첫번째 최소 간선을 그래프에 추가//
	Ent_Vertex[START] = 1;
	pos = MinEdge(edgeAddr, SU1, Ent_eg, Ent_Vertex);
	p = edgeAddr[pos]; InsertEdge(G2, p); Cnt_branch++;
	from = p->v_from; to = p->v_to; cost = p->cost;

	G2->Chk_Vertex[from]++; G2->Chk_Vertex[to]++;
	Ent_Vertex[from] = 1; Ent_Vertex[to] = 1; Ent_eg[pos] = 0;
	hap += cost;
	printf("\n %2d> 간선(%c %c  %3d) 추가", pos, from + 65, to + 65, cost);

	while (Cnt_branch + 1 < V1) {  //두번대 이후의 연결점 최소 간선을 추가한 후
		pos = MinEdge(edgeAddr, SU1, Ent_eg, Ent_Vertex);
		p = edgeAddr[pos]; Cnt_branch++;
		from = p->v_from; to = p->v_to; cost = p->cost;

		G2->Chk_Vertex[from]++; G2->Chk_Vertex[to]++;
		Ent_Vertex[from] = 1; Ent_Vertex[to] = 1; Ent_eg[pos] = 0;
		hap += cost;
		printf("\n %2d> 간선(%c %c  %3d) 추가", pos, from + 65, to + 65, cost);

		if (Except(G1, Cnt_branch)) {
			printf("\n %2d> 간선(%c %c  %3d) 제거", pos, from + 65, to + 65, cost);
			G2->Chk_Vertex[from]--; G2->Chk_Vertex[to]--;
			Ent_eg[pos] = -1; Cnt_branch--; hap -= cost;
		}
		else  // 추가 가능한 간선을 추가 확정
			InsertEdge(G2, p);
	}

	printf("\n========================");
	printf("\n	최소 비용 가중치 : %3d\n", hap);
	printf("\n\n G2의 인접 정점 리스트\n");
	PrintGragh(G2);
	printf("\n");
}