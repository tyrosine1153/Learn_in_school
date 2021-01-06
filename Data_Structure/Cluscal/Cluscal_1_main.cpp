/*간선을 가중치 순으로 내림차순 정렬한다.
그래프로부터 최대 가중치 간선을 차례로 제거하되 그래프가 분리되지 않도록 한다.
간선의 개수는 [정점수-1]을 만족하여야 한다,*/
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
	
	//간선 개수 구하기//
	int SU1=sizeof(edge)/sizeof(Edge);
	int* entry = (int*)malloc(sizeof(int) * SU1);
	memset(entry, 0, sizeof(int) * SU1);
	
	//정점 개수 구하기//
	Edge** edgeAddr = (Edge**)malloc(SU1 * sizeof(Edge*)), * p;
	int i, V1;
	for (i = 0; i < SU1; i++)
		edgeAddr[i] = &edge[i];
	V1 = Cnt_Vertex(edgeAddr, SU1);  //최대 정점 수
	
	//그래프 생성해 정점 추가//
	EdgeType* G1 = (EdgeType*)malloc(sizeof(EdgeType));
	CreatGragh(G1, V1);
	for (i = 0; i < V1; i++)
		InsertVertex(G1, i);
	
	//그래프에 모든 간선 추가//
	int* Chk_Vertex = (int*)malloc(sizeof(int) * V1 * 2);  //연결정점 배열
	memset(Chk_Vertex, 0, sizeof(int) * V1 * 2);
	int from, to, Dcnt = 0;
	for (i = 0; i < SU1; i++) {
		p = edgeAddr[i]; from = p->v_from; to = p->v_to;
		Chk_Vertex[from]++; Chk_Vertex[to + V1]++;
		InsertEdge(G1, p); entry[i] = 1; Dcnt++;
	}
	
	//정점별 인접 노드 출력//
	printf("\n G1의 인접 정점 리스트\n"); PrintGragh(G1); printf("\n");

	//간선 자료 내림차순 정렬//
	Sorting(edgeAddr, DSCEND, SU1);
	
	//간선의 가중치가 큰 것부터 그래프에서 제외. 고립정점 생기지 않도록//
	for (i = 0; i < SU1; i++) {
		if (Dcnt < V1) break;  //최소 간선 수 (Dcnt) = 정점 수(V1) - 1
		p = edgeAddr[i]; from = p->v_from; to = p->v_to;
		--Chk_Vertex[from]; --Chk_Vertex[to + V1];  //일단 제외
		if (Except(Chk_Vertex, V1)) {  //제외 대상이면 제외 확정
			printf("\n (%c, %c) %d 제외", from + 65, to + 65, p->cost);
			entry[i] = 0;
			Dcnt--;
		}
		else {
			++Chk_Vertex[from]; ++Chk_Vertex[to + V1];
		}
	}
	printf("\n");
	
	//새 그래프 생성하여//
	EdgeType* G2 = (EdgeType*)malloc(sizeof(EdgeType));
	CreatGragh(G2, V1);
	for (i = 0; i < V1; i++)  InsertVertex(G2, i);
	
	//제외되지 않은 간선만 그래프에 추가//
	int hap = 0;
	for (i = 0; i < SU1; i++) {
		if (entry[i]) {
			p = edgeAddr[i]; InsertEdge(G2, p);
			from = p->v_from; to = p->v_to;
			printf("\n 간선(%c %c) 가중치 %3d", from + 65, to + 65, p->cost);
			hap = hap + p->cost;
		}
	}
	printf("\n========================");
	printf("\n	최소 비용 가중치 : %3d\n", hap);
	printf("\n\n G2의 인접 정점 리스트\n");
	PrintGragh(G2);
	printf("\n");
}