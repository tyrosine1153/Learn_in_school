#include<stdio.h>
#include<stdlib.h>
#define LEN_Heap 20

void Pout(int* a, int n) {
    for (int i = 1; i < n; i++) {
        printf("%3d ", *(a + i));
    }
    printf("\n");
}

void MakeHeap(int* A, int* B, int n) {
    int i, j, key;

    B[1] = A[1];
    for (i = 2; i < n; i++) {
        key = A[i];
        j = i;
        while (j > 1 && key > B[j / 2]) {
            B[j] = B[j / 2];
            j = j / 2;
        }
        B[j] = key;
        Pout(B, i);
    }
}

void HeapSort(int* B, int* A, int n) {
    int i, j, j_next, key, su;
    for (i = 1; i < n; i++) {
        A[i] = B[1];
        key = B[n - i];
        j = 1; j_next = 2 * j;
        while (su = (j_next < n - i) + (j_next + 1 < n - i)) { // �ڽ� ���� ����ϴ� if ��
            if (su == 2)
                j_next = j_next + (B[j_next] < B[j_next + 1] ? 1 : 0); // �� �ڽ��� �� ū �ϳ��� ��¼��
            if (B[j_next] <= key)
                break;
            B[j] = B[j_next];
            j = j_next; j_next = 2 * j;
        }
        B[j] = key;
    }
}


int main() {
    int A[] = { 0, 8, 12, 31, 13, 42, 28, 5, 19, 23, 3, 17, 10, };
    int sz = sizeof(A) / sizeof(int);

    int* B = (int*)malloc(sizeof(int) * sz);
    printf("�� �ڷ� :"); Pout(A, sz);
    MakeHeap(A, B, sz);
    printf("�� �ڷ�: "); Pout(B, sz);
    HeapSort(B, A, sz);
    printf("���� �ڷ�: "); Pout(A, sz);


    return 0;
}

